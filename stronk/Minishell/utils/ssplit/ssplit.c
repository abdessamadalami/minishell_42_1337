/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:08:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/03 18:42:30 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	first_occ(char *s)
{
	int	i;
	char	f;
	int	x=0;
//	int	y=0;

	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == '"' || s[i] == '\'')
			f = s[i];
		i++;
	}
	while (s[i])
	{
	//	if (s->data[i] == '>' || s->data[i] == '<' || s->data[i] == '|')
		if (s[i] == f)
		{
			x++;
			// c = s->data[i];
		}
	/*	if (s[i] == l && x%2 == 0)
		{
			y++;
			// c = s->data[i];
		}*/
		i++;
	}
	return (x);
}

static int	set_count(t_gg *gg, char *s, char c)
{
	int	i;
	int	count;
	char	f;

	count = 0;
	i = 0;
	f = first_occ(s);
	// printf("f %c\n", f);
	while (s[i] == c)
		i++;
	count++;
	while (s[i])
	{
		if (s[i] == f)
			gg->lock++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0' && (gg->lock % 2 == 0))
			count++;
		i++;
	}
	gg->qq = gg->lock;
	// if (gg->lock % 2 != 0)
	// 	return (-1);
	printf("count %d\n", gg->lock);
	return (count);
}

static char	**ft_del(char **t, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(t[i]);
		i++;
	}
	free(t);
	return (NULL);
}

static char	**chek_and_fill(t_gg *gg, char **t, char *s, char c)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	while (s[i])
	{
		
		temp = i;
		if ((s[i] == '"' || s[i] == '\'') && (gg->lock % 2 != 0))
		{
			gg->lock--;
			continue ;
		}
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		while ((s[i] != c && s[i]) || ((s[i] == c && s[i]) && gg->lock % 2 != 0))
		{
			if (s[i] == '"' || s[i] == '\'')
			{
				gg->lock--;
			}
			i++;
		}
		t[count] = ft_subtr(s, temp, i - temp);
		if (t[count] == NULL)
			return (ft_del(t, count));
		count++;
	}
	t[count] = 0;
	gg->count = count;
	// for (int i=0;t[i];i++)
	// 	printf("chta %s\n", t[i]);
	return (t);
}

char	**ssplit(t_gg *gg, char *s, char c)
{
	char	**t;
	int		count;

	if (s == 0)
		return (0);
	count = set_count(gg, s, c);
	if (count < 0)
	{
		printf("Error tmma ss\n");
		exit(1);
	}
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == NULL)
		return (0);
	return (chek_and_fill(gg, t, s, c));
}

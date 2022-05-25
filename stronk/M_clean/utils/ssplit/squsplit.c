/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:49:19 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/25 13:05:56 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	set_count(t_gg *gg, char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	count++;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\''/* || s[i] == '>' || s[i] == '<'*/)
			gg->lock++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0' && (gg->lock % 2 == 0))
			count++;
		i++;
	}
	gg->qq = gg->lock;
	if (gg->lock % 2 != 0)
		return (-1);
	return (count + 2);
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
		if ((s[i] == '"' || s[i] == '\''))
		{
			gg->lock--;
			i++;
			continue ;
		}
		if (s[i] == c && (gg->lock % 2 == 0))
		{
			if (s[i + 1] == c)
				i++;
			i++;
			t[count] = ft_subtr(s, temp, i - temp);
			count++;
			continue ;
		}
		while (s[i])
		{
			if ((s[i] == c && (gg->lock % 2 == 0)) || (s[i] == '"' || s[i] == '\''))
			{
				break;
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
	return (t);
}

char	**squsplit(t_gg *gg, char *s, char c)
{
	char	**t;
	int		count;

	if (s == 0)
		return (0);
	count = set_count(gg, s, c);
	
	if (count < 0)
	{
		printf("go to heredoc\n");
		exit(1);
	}
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == NULL)
		return (0);
	return (chek_and_fill(gg, t, s, c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:08:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/16 00:08:48 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	set_count(t_gg *gg, char *s, char c)
{
	int	i;
	int	count;

	count = 0;
//	arg->lock = 0;
//	arg->count = 0;
	printf("i'm lock %d\n", gg->lock);
	printf("i'm count %d\n", gg->count);
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
//	printf("count %d\n", arg->lock);
	if (gg->lock % 2 != 0)
		return (-1);
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
//	printf("--i'm lock %d\n", gg->lock);
//	printf("--i'm count %d\n", gg->count);
	while (s[i])
	{
		
		temp = i;
		if ((s[i] == '"' || s[i] == '\'') && (gg->lock % 2 != 0))
		{
	//		printf("hooooooo\n");
			gg->lock--;
		//	i++;
			continue ;
		}
		if (s[i] == c /* && (cmds->lock % 2 == 0)*/)
		{
			i++;
			continue ;
		}
		// printf("lock %d\n", cmds->lock);
		while ((s[i] != c && s[i] /*& s[i] != '"' && s[i] != '\''*/) || ((s[i] == c && s[i]) && gg->lock % 2 != 0))
		{
			if (s[i] == '"' || s[i] == '\'')
			{
	//			printf("hiiiiiiiiiiii\n");
				gg->lock--;
			//	printf("hii breakit\n");
			//	break;
			}
			//	cmds->lock--;
			i++;
			// cmds->lock--;
		}
		t[count] = ft_substr(s, temp, i - temp);
	//	printf("tttttt-%s-\n", t[count]);
	//	printf("finaliiii count %d\n", count);
		if (t[count] == NULL)
			return (ft_del(t, count));
		count++;
	}
	t[count] = 0;
	gg->count = count;
	// for (int i=0; t[i] != NULL ;i++)
	// {
	// 	// printf("line is `%s`\n", cmds->line[i]);
	// 	printf("-----> t is `%s`\n", t[i]);
	// }
	return (t);
}

char	**ssplit(t_gg *gg, char *s, char c)
{
	char	**t;
	int		count;

	if (s == 0)
		return (0);
	count = set_count(gg, s, c);
	// printf("ccccccount %d\n", count);
	if (count < 0)
	{
		// return (NULL);
		printf("go to heredoc\n");
		exit(1);
	}
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == NULL)
		return (0);
	return (chek_and_fill(gg, t, s, c));
}

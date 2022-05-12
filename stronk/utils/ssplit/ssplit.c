/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:08:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/12 18:04:41 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	set_count(t_cmd *cmds, char *s, char c)
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
		if (s[i] == '"' || s[i] == '\'')
			cmds->lock++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0' && (cmds->lock % 2 == 0))
			count++;
		i++;
	}
	printf("count %d\n", count);
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

static char	**chek_and_fill(t_cmd *cmds, char **t, char *s, char c)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	
	while (s[i])
	{
		
		temp = i;
		if (s[i] == c/* && (cmds->lock % 2 == 0)*/)
		{
			if (s[i] == '"' || s[i] == '\'')
				cmds->lock--;
			i++;
			continue ;
		}
		printf("lock %d\n", cmds->lock);
		while ((s[i] != c && s[i]) || (cmds->lock % 2 != 0))
		{
			if (s[i] == '"' || s[i] == '\'')
				cmds->lock--;
			i++;
			// cmds->lock--;
		}
		t[count] = ft_substr(s, temp, i - temp);
	//	printf("tttttt-%s-\n", t[count]);
		if (t[count] == NULL)
			return (ft_del(t, count));
		count++;
	}
	t[count] = 0;
	return (t);
}

char	**ssplit(t_cmd *cmds, char *s, char c)
{
	char	**t;
	int		count;

	if (s == 0)
		return (0);
	count = set_count(cmds, s, c);
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == NULL)
		return (0);
	return (chek_and_fill(cmds, t, s, c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sosplit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:42:22 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/13 21:50:19 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	set_count(t_cmd *cmds, char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == '>')
		i++;
	count++;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\''/* || s[i] == '>' || s[i] == '<'*/)
			cmds->lock++;
		if (s[i] == '>' && s[i + 1] != '>' && s[i + 1] != '\0' && (cmds->lock % 2 == 0))
			count++;
		i++;
	}
	printf("count %d\n", cmds->lock);
	if (cmds->lock % 2 != 0)
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

static char	**chek_and_fill(t_cmd *cmds, char **t, char *s)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	
	while (s[i])
	{
		
		temp = i;
		if (s[i] == '>' || s[i] == '"' || s[i] == '\''/* && (cmds->lock % 2 == 0)*/)
		{
			if (s[i] == '"' || s[i] == '\'')
				cmds->lock--;
			i++;
			continue ;
		}
		// printf("lock %d\n", cmds->lock);
		while ((s[i] != '>' && s[i] && s[i] != '"' && s[i] != '\'') || (cmds->lock % 2 != 0))
		{
			if (s[i] == '"' || s[i] == '\'')
				break;
			//	cmds->lock--;
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

char	**sosplit(t_cmd *cmds, char *s)
{
	char	**t;
	int		count;

	if (s == 0)
		return (0);
	count = set_count(cmds, s);
	if (count < 0)
	{
		// return (NULL);
		printf("go to heredoc\n");
		exit(1);
	}
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == NULL)
		return (0);
	return (chek_and_fill(cmds, t, s));
}
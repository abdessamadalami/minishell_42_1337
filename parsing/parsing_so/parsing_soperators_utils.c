/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_soperators_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:31:21 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/28 16:18:41 by sultan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_condistions(char *s)
{
	if ((s[0] == '>' && s[1] == '\0')
		|| (s[0] == '<' && s[1] == '\0')
		|| (s[0] == '|' && s[1] == '\0')
		|| (s[0] == '>' && s[1] == '>' && s[2] == '\0')
		|| (s[0] == '<' && s[1] == '<' && s[2] == '\0'))
		return (1);
	return (0);
}

int	so_counter(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '>' || s[i] == '<' || s[i] == '|')
		{
			if (i > 0)
				count++;
			if (s[i + 1] == '>' || s[i + 1] == '<')
				i++;
			count++;
		}
		if (s[i + 1] == '\0' && s[i] != '>' && s[i] != '<')
		{
			count++;
			break ;
		}
		i++;
	}
	return (count);
}

void	fill_list_so(t_arg **sfa, char	**t)
{
	t_arg	*node;
	int		i;

	i = 0;
	while (t[i] != 0)
	{
		node = ftlstnew(t[i]);
		free(t[i]);
		ftlstadd_back(sfa, node);
		i++;
	}
	free(t);
}

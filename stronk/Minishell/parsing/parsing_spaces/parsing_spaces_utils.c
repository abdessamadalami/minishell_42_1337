/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_spaces_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:21:04 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/12 12:22:37 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_arg	*fill_list(char **t, t_normsht *normsht)
{
	t_arg	*arg;
	t_arg	*node;
	int		i;

	i = 0;
	arg = NULL;
	t[normsht->count + 1] = 0;
	while (t[i] != NULL)
	{
		node = ftlstnew(t[i]);
		free(t[i]);
		ftlstadd_back(&arg, node);
		i++;
	}
	free(t);
	return (arg);
}

int	spaces_counter(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"')
		{
			i++;
			while (s[i] != '"' && s[i] != '\0')
				i++;
		}
		else if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'' && s[i] != '\0')
				i++;
		}
		else if (s[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

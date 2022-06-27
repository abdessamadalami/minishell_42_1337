/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_wildcard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:01:16 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/11 19:45:54 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_free(char **suffix, char *prefix)
{
	int	i;

	i = 0;
	free(prefix);
	while (suffix[i])
	{
		free(suffix[i]);
		i++;
	}
	free(suffix);
}

t_arg	*parsing_wildcard(t_arg *arg)
{
	t_arg	*sfa;
	char	*prefix;
	char	**suffix;

	sfa = NULL;
	while (arg != NULL)
	{
		if (check_q(arg->data))
		{
			if (check_so(arg->data, '*'))
			{
				prefix = get_prefix(arg->data);
				suffix = get_suffix(arg->data);
				get_files(&sfa, arg->data, suffix, prefix);
				ft_free(suffix, prefix);
			}
			else
				ftlstadd_back(&sfa, ftlstnew(arg->data));
		}
		else
			ftlstadd_back(&sfa, ftlstnew(arg->data));
		arg = arg->next;
	}
	return (sfa);
}

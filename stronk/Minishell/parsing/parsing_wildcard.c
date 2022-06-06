/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_wildcard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:01:16 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/06 13:43:03 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	diklmzyana(t_arg **sfa, char *s)
{
	t_arg	*node;

	node = malloc(sizeof(t_arg));
	if (!node)
		exit(1);
	node = ftlstnew(s);
	ftlstadd_back(sfa, node);
}

static void	diklmzyanalokhra(t_arg **sfa, char *s)
{
	char	**temp;

	temp = malloc(sizeof(char) * 9999);
	if (!temp)
		exit(1);
	temp = wildsplit(s);
	addbacki_sf(sfa, temp);
}

t_arg	*parsing_wildcard(t_arg *arg)
{
	t_arg	*sfa;

	sfa = NULL;
	while (arg != NULL)
	{
		if (check_q(arg->data))
		{
			if (check_so(arg->data, '*'))
				diklmzyanalokhra(&sfa, arg->data);
			else
				diklmzyana(&sfa, arg->data);
		}
		else
			diklmzyana(&sfa, arg->data);
		arg = arg->next;
	}
	return (sfa);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_soperators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:05:14 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/06 13:42:15 by ael-asri         ###   ########.fr       */
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
	temp = sosplit(s);
	addbacki_sf(sfa, temp);
}

static void	diklmzyanalokhrawsf(t_arg **sfa, t_gg *gg, char *s)
{
	char	**temp;

	temp = malloc(sizeof(char) * 9999);
	if (!temp)
		exit(1);
	temp = squsplit(gg, s);
	addbacki_sf(sfa, temp);
}

t_arg	*parsin_dyalbss7(t_arg *arg, t_gg *gg)
{
	t_arg	*sfa;

	sfa = NULL;
	while (arg != NULL)
	{
		if (check_q(arg->data))
		{
			if ((check_so(arg->data, '<') || check_so(arg->data, '>')
					|| check_so(arg->data, '|')))
			{
				if (ft_strln(arg->data) == 1 || (ft_strln(arg->data) == 2
						&& (arg->data[0] == arg->data[1])
						&& arg->data[0] != '|'))
					diklmzyana(&sfa, arg->data);
				else
					diklmzyanalokhra(&sfa, arg->data);
			}
			else
				diklmzyana(&sfa, arg->data);
		}
		else
			diklmzyanalokhrawsf(&sfa, gg, arg->data);
		arg = arg->next;
	}
	return (sfa);
}

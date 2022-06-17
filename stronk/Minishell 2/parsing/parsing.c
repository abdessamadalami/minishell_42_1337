/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:29:38 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/16 14:44:33 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pfree(t_arg **mr, t_arg **arg, t_gg **gg, char ***line)
{
	int	i;

	i = 0;
	mr = NULL;
	arg = NULL;
	gg = NULL;
	while (*line[i])
	{
		free(*line[i]);
		i++;
	}
}

t_arg	*ft_parsing(char *s)
{
	t_arg	*arg;
	t_gg	*gg;
	t_arg	*mr;
	t_arg	*dv;

	gg = malloc(sizeof(t_gg));
	gg->lock = 0;
	gg->count = 0;
	gg->qq = 0;
	arg = parsing_spaces(s);
	check_syntax(arg);
	gg->lock = 0;
	mr = parsin_dyalbss7(arg, gg);
	arg = NULL;
	arg = check_envvars(mr);
	mr = NULL;
	mr = parsing_wildcard(arg);
	dv = remove_quotes(mr);
	return (dv);
}

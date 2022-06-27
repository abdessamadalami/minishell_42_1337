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
	t_arg	*mr;
	t_arg	*dv;
	t_arg	*dg;

	arg = parsing_spaces(s);
	if (!check_syntax(arg))
		return (NULL);
	mr = parse_so(arg);
	dg = check_envvars(mr);
	ftlstclear(&mr, free);
	mr = parsing_wildcard(dg);
	dv = remove_quotes(mr);
	ftlstclear(&arg, free);
	ftlstclear(&dg, free);
	ftlstclear(&mr, free);
	return (dv);
}

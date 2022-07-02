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

void	ftlstclearrt(t_list **lst, void (*del)(void	*))
{
	t_list	*list;

	list = *lst;
	while (*lst != NULL)
	{
		*lst = list->next;
		del(list->content);
		free(list);
		list = *lst;
	}
}

t_arg	*ft_parsing(char *s, t_list *env_lst)
{
	t_arg	*arg;
	t_arg	*mr;
	t_arg	*dv;
	t_arg	*dg;
//	t_list	*yo;

//	yo = env_lst;
	arg = parsing_spaces(s);
	if (!check_syntax(arg))
	{
		ftlstclear(&arg, free);
		return (NULL);
	}
	mr = parse_so(arg);
	dg = check_envvars(mr, env_lst);
	ftlstclear(&mr, free);
	mr = parsing_wildcard(dg);
	dv = remove_quotes(mr);
	ftlstclear(&arg, free);
	ftlstclear(&dg, free);
	ftlstclear(&mr, free);
//	ftlstclearrt(&yo, free);
//	free(yo);
	// env_lst = 0;
	// system("leaks minishell");
	// exit(1);
	return (dv);
}

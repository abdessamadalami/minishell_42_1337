/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:31:51 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/25 13:10:18 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_arg	*ftlstnew(char *s)
{
	t_arg	*ptr;

	ptr = malloc(sizeof(t_arg));
	if (ptr == NULL)
		return (0);
	ptr->data = s;
	ptr->next = NULL;
	return (ptr);
}

t_arg	*ftlstlast(t_arg *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ftlstadd_front(t_arg **lst, t_arg *new)
{
	new->next = *lst;
	*lst = new;
}

void	ftlstadd_back(t_arg **lst, t_arg *new)
{
	t_arg	*list;

	list = *lst;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	while (list->next != NULL)
	{
		list = list->next;
	}
	list->next = new;
}

int	ftlstsize(t_arg *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int	ft_strllen(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i][j])
			j++;
		i++;
	}
	return (i);
}

void	addbacki_sf(t_arg **sfa, char **t)
{
	int	i;
	t_arg	*node;

	i = 0;
	while (t[i] != 0)
	{
		node = ftlstnew(t[i]);
		ftlstadd_back(sfa, node);
		i++;
	}
}
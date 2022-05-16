/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:31:51 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/15 18:37:15 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_arg	*ft_lstnew(char *s)
{
	t_arg	*ptr;

	ptr = malloc(sizeof(t_arg));
	if (ptr == NULL)
		return (0);
	ptr->data = s;
	ptr->next = NULL;
	return (ptr);
}

t_arg	*ft_lstlast(t_arg *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_arg **lst, t_arg *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_arg **lst, t_arg *new)
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

int	ft_lstsize(t_arg *lst)
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
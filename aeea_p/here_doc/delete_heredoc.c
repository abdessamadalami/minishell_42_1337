/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:46:29 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/01 17:10:25 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

static void	del_fun(t_list *list, t_list **lst)
{
	t_list	*prev;
	t_list	*node;

	node = 0;
	list = *lst;
	while (list != NULL && (ft_strncmp(list ->content, "<<\0", 4) != 0
			&& ft_strncmp(list ->content, "<\0", 3) != 0))
	{
		prev = list;
		list = list->next;
	}
	if (list -> next != NULL)
	{
		node = list;
		prev -> next = list -> next -> next;
		node->next->next = 0;
		ft_lstclear(&node, del);
	}
	else
		prev = NULL;
}

void	delete_here(t_list **lst)
{
	t_list	*list;

	list = *lst;
	if (list != NULL && (ft_strncmp(list ->content, "<<\0", 4) == 0
			|| ft_strncmp(list ->content, "<\0", 3) == 0))
	{
		*lst = list->next->next;
	}
	else
		del_fun(list, lst);
	if (*lst != NULL && check_redirec_d(*lst))
		delete_here(lst);
}

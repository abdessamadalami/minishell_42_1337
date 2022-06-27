/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:46:29 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/11 09:51:34 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

void	delete_here(t_list **lst)
{
	int		index;
	t_list	*list;
	t_list	*prev;

	list = *lst;
	index = 0;
	if (list != NULL && (ft_strncmp(list ->content, "<<\0", 4) == 0
			|| ft_strncmp(list ->content, "<\0", 3) == 0))
		*lst = list->next->next;
	else
	{
		while (list != NULL && (ft_strncmp(list ->content, "<<\0", 4) != 0
				&& ft_strncmp(list ->content, "<\0", 3) != 0))
		{
			prev = list;
			list = list ->next;
		}
		if (list -> next != NULL)
			prev -> next = list -> next -> next;
		else
			prev = NULL;
	}
	//printf("%d\n",check_redirec_d(*lst));
	//print_list(*lst,444);
	if (*lst != NULL && check_redirec_d(*lst))
		delete_here(lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 07:22:59 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/02 09:29:35 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include"../excuting_headr.h"

// unset for delet var in env variables
// export for inssrt a local var to environment
// env is the environment variables in environment

static void	help_un(t_list *node, t_list *list, t_list *lst)
{
	char	*ptr;
	t_list	*temp;

	ptr = 0;
	if (node == 0)
	{
		ptr = list->content;
		list = list->next;
		free(ptr);
		ptr = 0;
	}
	else
	{
		temp = lst;
		node->next = lst->next;
		free(lst->content);
		free(temp);
		temp = 0;
	}
}

void	c_unset(t_list *list, char *str)
{
	t_list	*node;
	t_list	*lst;
	char	*ptr;

	lst = list;
	node = 0;
	ptr = 0;
	while (lst)
	{
		if (ft_strncmp(str, lst->content, ft_strlen(str)) == 0)
		{
			help_un(node, list, lst);
			break ;
		}
		node = lst;
		lst = lst->next;
	}
	g_st = 0;
}

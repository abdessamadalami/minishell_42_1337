/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merg_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 07:54:03 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/02 23:44:47 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

void	print_list_x(t_list **a)
{
	t_list	*ptr;
	void	*p;
	void	*c;

	ptr = *a;
	p = 0;
	c = 0;
	while (ptr)
	{
		if (p != 0 && c != 0)
		{
			free(c);
			free(p);
		}
		p = ptr->next;
		c = ptr -> content;
		printf("declare -x %s\n", (char *)ptr->content);
		ptr = ptr->next;
	}
	free(c);
	free(p);
	free(*a);
	ptr = 0;
	*a = 0;
}

t_list	*mergesortedlist(t_list *lst1, t_list *lst2)
{
	t_list	*result;

	result = NULL;
	if (lst1 == NULL)
		return (lst2);
	else if (lst2 == NULL)
		return (lst1);
	if (ft_strncmp(lst1->content, lst2->content, ft_strlen(lst1->content)) <= 0)
	{
		result = lst1;
		result->next = mergesortedlist(lst1->next, lst2);
	}
	else
	{
		result = lst2;
		result->next = mergesortedlist(lst1, lst2->next);
	}
	return (result);
}

void	mid_list(t_list *list, t_list **fast, t_list **slow)
{
	t_list	*ptr2;
	t_list	*ptr1;

	ptr1 = list ->next;
	ptr2 = list;
	while (ptr1 != NULL)
	{
		ptr1 = ptr1->next;
		if (ptr1 != NULL)
		{
			ptr2 = ptr2->next;
			ptr1 = ptr1->next;
		}
	}
	*fast = list;
	*slow = ptr2->next;
	ptr2->next = NULL;
}

void	ft_merge_sort(t_list **list)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if ((*list)->next == NULL || (*list) == NULL)
		return ;
	mid_list(*list, &ptr1, &ptr2);
	ft_merge_sort(&ptr1);
	ft_merge_sort(&ptr2);
	*list = mergesortedlist(ptr1, ptr2);
}

void	ft_merge_sort_u(t_list *env)
{
	t_list	*new_list;

	new_list = NULL;
	if (env == NULL)
		return ;
	new_list = ft_lstmap(env, f, del);
	ft_merge_sort(&new_list);
	print_list_x(&new_list);
}

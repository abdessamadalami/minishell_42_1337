/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:31:51 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/16 20:32:21 by ael-asri         ###   ########.fr       */
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

void	lst_lastone(t_arg **arg, char **t, int x)
{
	int	i;

	
	i = 0;
	t_arg	*node;


	node = malloc(sizeof(t_arg));
	if (!node)
		exit(1);
//	node->next = (*arg)->next;
	printf("x %d\n", x);
	while (i < x-1)
	{
		printf("whotaaa %d\n", i);
		
		*arg = (*arg)->next;
		i++;
	}
	printf("thats ma noode `%s`\n", (*arg)->data);
	(*arg)->next = NULL;
	i = 0;
	printf("stlll %d\n", ft_strllen(t));
	for (int i=0;i<ft_strllen(t);i++)
		printf("t[%d]: %s\n", i, t[i]);
	i = 0;
	while (i < ft_strllen(t))
	{
		node = ft_lstnew(t[i]);
		ft_lstadd_back(arg, node);
		printf("newww ma noode `%s`\n", (*arg)->data);
		(*arg) = (*arg)->next;
		i++;
	}
/*	(*arg)->next = node;
	(*arg)->next = (*arg);
	node->next;*/
	
}

void	lst_between(t_arg **arg, char **t, int x)
{
	int	i;

	
	i = 0;
	t_arg	*node;
	t_arg	*newlist;


	newlist = malloc(sizeof(t_arg));
	node = malloc(sizeof(t_arg));
	if (!node)
		exit(1);
//	node->next = (*arg)->next;
	printf("x %d\n", x);
	i = 0;
	while (i <= ft_strllen(t))
	{
		node = ft_lstnew(t[i]);
		ft_lstadd_back(&newlist, node);
		printf("newww ma noode `%s`\n", newlist->data);
		newlist = newlist->next;
		i++;
	}
	newlist->next = ft_lstlast(*arg);
	i=0;
	while (i < x-1)
	{
		printf("whotaaa %d\n", i);
		
		*arg = (*arg)->next;
		i++;
	}
	
	printf("thats ma noode `%s`\n", (*arg)->data);
	(*arg)->next = newlist;
	i = 0;
	printf("stlll %d\n", ft_strllen(t));
	for (int i=0;i<ft_strllen(t);i++)
		printf("t[%d]: %s\n", i, t[i]);
/*	(*arg)->next = node;
	(*arg)->next = (*arg);
	node->next;*/
	
}
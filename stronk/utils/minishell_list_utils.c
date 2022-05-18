/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:31:51 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/18 22:35:08 by ael-asri         ###   ########.fr       */
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
	t_arg	*newlist=NULL;
	t_arg	*cp;
	t_arg	*chyata=NULL;


	int initialsize = ft_lstsize(*arg);
	// newlist = malloc(sizeof(t_arg));
	// node = malloc(sizeof(t_arg));
	// if (!node)
	// 	exit(1);
//	node->next = (*arg)->next;
		///////////////////////////////////////////////////////// chyata time /////////////////////////////////////////////////////////
	cp = *arg;
	printf("initial size %d\n", initialsize-x);
	printf("x %d\n", x);
	i =0;
	while (i < (initialsize-x))
	{
		cp = cp->next;
		i++;
	}
	printf("-i %d\n", i);
//	printf("ssiizzee %d\n", ft_lstsize());
	i=0;
	
	while (i < (initialsize-x-1))
	{
//		printf("chyata %s\n", cp->data);
		node = ft_lstnew(cp->data);
		ft_lstadd_back(&chyata, node);
//		printf("lst dyal chyata 9bl %d\n", ft_lstsize(chyata));
		cp = cp->next;
		i++;
	}
	printf("lst dyal chyata %d\n", ft_lstsize(chyata));
/*	while (chyata != NULL)
	{
		printf("chyatayyy `%s`\n", chyata->data);
		chyata = chyata->next;
	}*/
	
	
	
	
	printf("i %d\n", i);
	printf("x %d\n", x);
	




	
	////////////////////////////////// creating the new list //////////////////////////////////
	i = 0;
	printf("stlll %d\n", ft_strllen(t));
//	t_arg *sultan;
//	sultan = *arg;
	while (t[i])
	{
//		printf("t[%d]: %s\n", i,t[i]);
		node = ft_lstnew(t[i]);
	//	printf("noode `%s`\n", node->data);
	//	printf("whyyy\n");
		ft_lstadd_back(&newlist, node);
	//	printf("newww newlist noode `%s`\n", (*newlist)->data);
		// (*newlist) = (newlist)->next;
		i++;
	}
	
	
	
	i = 0;
	while (i < 2)
	{
//		printf("chyata `%s`\n", chyata->data);
		node = ft_lstnew(chyata->data);
		ft_lstadd_back(&newlist, node);
		chyata = chyata->next;
		i++;
	}
	while (newlist != NULL)
	{
		printf("final `%s`\n", newlist->data);
		newlist = newlist->next;
	}
//	(*arg)->next = newlist;


//	arg = &newlist;
//	printf("size lkherr %d\n", ft_lstsize(newlist));
//	arg = new
//printf("newww newlist noode `%s`\n", newlist->data);
/*	while (newlist != NULL)
	{
		printf("newww newlist noode `%s`\n", newlist->data);
		newlist = newlist->next;
	}*/
//	printf("newlista `%s`\n", newlist->data);
//	newlist->next = chyata;
//	printf("i %d", i);
//	printf("newww newlist noode `%s`\n", newlist->data);
//	sultan = newlist;
//	printf("kkkk\n");
	// node = ft_lstnew(t[i]);
	// ft_lstadd_back(newlist, node);
/*	while (newlist != NULL)
	{
		printf("newww newlist noode `%s`\n", newlist->data);
		newlist = newlist->next;
	}*/
	// printf("newlist size %d\n", ft_lstsize(newlist));
	/////////////////////////////////////////////////////////////////////////////////////////////
	

	//////////////////////////////// counting till the node that contains tokens so i link it with the new one //////////////////////////////////
/*	i=0;
	while (i < x-1)
	{
		printf("i=%d x=%d\n", i, x);
		printf("thats ma noode `%s`\n", (*arg)->data);
		
		i++;
		
		if (i+1 == x-1)
			break;
		*arg = (*arg)->next;
		// i++;
	}
	printf("+i=%d +x=%d\n", i, x);
//	*arg = (*arg)->next;
//	printf("newww ma noode `%s`\n", (*newlist)->data);
	printf("malawana\n");
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	printf("malawana noode `%s`\n", (*arg)->data);
//	(newlist)->next = (*arg);
	
	printf("HANYA NTI\n");
	i=0;
	
//	printf("thats ma noode `%s`\n", (*arg)->data);
	(*arg)->next = (newlist);
//	(*arg) = (*arg)->next;
//	(*arg)->next = (chyata);
//	(*arg) = (*arg)->next;
	i = 0;
//	printf("stlll %d\n", ft_strllen(t));






	
	for (int i=0;i<ft_strllen(t);i++)
		printf("t[%d]: %s\n", i, t[i]);
	(*arg)->next = node;
	(*arg)->next = (*arg);
	node->next;*/
	
}
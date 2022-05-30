/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:31:51 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/25 10:23:47 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstnew(char *s)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (ptr == NULL)
		return (0);
	ptr->content = s;
	ptr->next = NULL;
	return (ptr);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

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

int	ft_lstsize(t_list *lst)
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

t_list	*lst_lastone(t_list **arg, char **t, int x)
{
	int	i;

	i = 0;
	t_list	*node;
	t_list	*cp;
	t_list	*newlist;

	cp = *arg;
	newlist = (*arg);
	if (!x)
	{
		newlist = (*arg)->next;
	/*	while (i < x-1)
		{
	//		printf("whotaaa %d\n", i);
			
			newlist = newlist->next;
			i++;
		}*/
	}

	else
	{
		newlist = (*arg);
	/*	while (i < x-1)
		{
	//		printf("whotaaa %d\n", i);
			
			newlist = newlist->next;
			i++;
		}*/
	}
	node = malloc(sizeof(t_list));
	if (!node)
		exit(1);
//	node->next = (*arg)->next;
//	printf("x %d\n", x);
	while (i < x-1)
	{
//		printf("whotaaa %d\n", i);
		node = ft_lstnew(cp->content);
//		printf("cp %s\n", cp->content);
		ft_lstadd_back(&newlist, node);
		cp = cp->next;
	//	newlist = newlist->next;
		i++;
	}
	
//	printf("thats ma noode `%s`\n", newlist->content);
	if (x)
		newlist->next = NULL;
	i = 0;
//	printf("hhhhyy\n");
//	printf("stlll %d\n", ft_strllen(t));
//	for (int i=0;i<ft_strllen(t);i++)
//		printf("t[%d]: %s\n", i, t[i]);
	i = 0;
//	printf("size of before %d\n", ft_lstsize(newlist));
	while (i < ft_strllen(t))
	{
		node = ft_lstnew(t[i]);
//		printf("t[%d]: %s\n", i, t[i]);
		ft_lstadd_back(arg, node);
	//	printf("newww ma noode `%s`\n", newlist->content);
//		(*arg) = (*arg)->next;
		i++;
	}
//	printf("size of new %d\n", ft_lstsize(newlist));
//	arg = &newlist;
/*	while (newlist != NULL)
	{
		printf("lst data %s\n", newlist->content);
		newlist = newlist->next;
	}*/
	return (newlist);
	
/*	(*arg)->next = node;
	(*arg)->next = (*arg);
	node->next;*/
	
}

t_list	*lst_between(t_list **arg, char **t, int x)
{
	int	i;

	
	i = 0;
	t_list	*node;
	t_list	*newlist=NULL;
	t_list	*cp;
//	t_list	*gg=NULL;
	t_list	*chyata=NULL;


	int initialsize = ft_lstsize(*arg);
	// newlist = malloc(sizeof(t_list));
	// node = malloc(sizeof(t_list));
	// if (!node)
	// 	exit(1);
//	node->next = (*arg)->next;
		///////////////////////////////////////////////////////// chyata time /////////////////////////////////////////////////////////
	cp = *arg;
//	printf("initial size %d\n", initialsize-x);
//	printf("x %d\n", x);
	i =0;
	while (i < (initialsize-x-1))
	{
		node = ft_lstnew(cp->content);
//		printf("hadi hya cp data %s\n", cp->content);
		ft_lstadd_back(&newlist, node);
		cp = cp->next;
		i++;
	}
//	printf("-i %d\n", i);
//	printf("ssiizzee %d\n", ft_lstsize());
	i=0;
	cp = cp->next;
	while (i < (initialsize-x-1))
	{
//		printf("chyata %s\n", cp->content);
		node = ft_lstnew(cp->content);
		ft_lstadd_back(&chyata, node);
//		printf("lst dyal chyata 9bl %d\n", ft_lstsize(chyata));
		cp = cp->next;
		i++;
	}
//	printf("lst dyal chyata %d\n", ft_lstsize(chyata));
/*	while (chyata != NULL)
	{
		printf("chyatayyy `%s`\n", chyata->content);
		chyata = chyata->next;
	}*/
	
	
	
	
//	printf("i %d\n", i);
//	printf("x %d\n", x);
	




	
	////////////////////////////////// creating the new list //////////////////////////////////
	i = 0;
//	printf("stlll %d\n", ft_strllen(t));
//	t_list *sultan;
//	sultan = *arg;
	while (t[i])
	{
//		printf("t[%d]: %s\n", i,t[i]);
		node = ft_lstnew(t[i]);
	//	printf("noode `%s`\n", node->content);
	//	printf("whyyy\n");
		ft_lstadd_back(&newlist, node);
	//	printf("newww newlist noode `%s`\n", (*newlist)->content);
		// (*newlist) = (newlist)->next;
		i++;
	}
	
	
	
	i = 0;
	while (i < x)
	{
//		printf("chyata `%s`\n", chyata->content);
		node = ft_lstnew(chyata->content);
		ft_lstadd_back(&newlist, node);
		chyata = chyata->next;
		i++;
//		printf("ha\n");
	}
	
	
/*	while (newlist != NULL)
	{
		printf("final `%s`\n", newlist->content);
		newlist = newlist->next;
	}*/
//	(*arg)->next = newlist;


//	arg = &newlist;
//	printf("size lkherr %d\n", ft_lstsize(newlist));
//	arg = new
//printf("newww newlist noode `%s`\n", newlist->content);
/*	while (newlist != NULL)
	{
		printf("newww newlist noode `%s`\n", newlist->content);
		newlist = newlist->next;
	}*/
//	printf("newlista `%s`\n", newlist->content);
//	newlist->next = chyata;
//	printf("i %d", i);
//	printf("newww newlist noode `%s`\n", newlist->content);
//	sultan = newlist;
//	printf("kkkk\n");
	// node = ft_lstnew(t[i]);
	// ft_lstadd_back(newlist, node);
/*	while (newlist != NULL)
	{
		printf("newww newlist noode `%s`\n", newlist->content);
		newlist = newlist->next;
	}*/
	// printf("newlist size %d\n", ft_lstsize(newlist));
	/////////////////////////////////////////////////////////////////////////////////////////////
	

	//////////////////////////////// counting till the node that contains tokens so i link it with the new one //////////////////////////////////
/*	i=0;
	while (i < x-1)
	{
		printf("i=%d x=%d\n", i, x);
		printf("thats ma noode `%s`\n", (*arg)->content);
		
		i++;
		
		if (i+1 == x-1)
			break;
		*arg = (*arg)->next;
		// i++;
	}
	printf("+i=%d +x=%d\n", i, x);
//	*arg = (*arg)->next;
//	printf("newww ma noode `%s`\n", (*newlist)->content);
	printf("malawana\n");
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	printf("malawana noode `%s`\n", (*arg)->content);
//	(newlist)->next = (*arg);
	
	printf("HANYA NTI\n");
	i=0;
	
//	printf("thats ma noode `%s`\n", (*arg)->content);
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
	return (newlist);
	
}


t_list	*akhirw7da(t_list **arg, char **t, int x)
{
	int	i;
	t_list	*newlist=NULL;
	t_list	*node;

	i = 0;
	
	
	
	////////// creating the new list /////////////////
/*	while (t[i] != 0)
	{
		node = ft_lstnew(t[i]);
		printf("addin %s\n", node->content);
		ft_lstadd_back(&newlist, node);
		i++;
	}*/
	//////////////////////////////////////////////////



	
	////////// remove the node that contains the tooken /////////////////
//	printf("x %d\n", x);
	i=0;
	while (i < x)
	{
		node = ft_lstnew((*arg)->content);
//		printf("addin %s\n", node->content);
		ft_lstadd_back(&newlist, node);
		(*arg) = (*arg)->next;
		i++;
	}
//	(*arg)->next = newlist;
//	printf("size after removin %d\n", ft_lstsize(*arg));
	////////////////////////////////////////////////////////////////////
	i=0;
	while (t[i] != 0)
	{
		node = ft_lstnew(t[i]);
//		printf("addin %s\n", node->content);
		ft_lstadd_back(&newlist, node);
		i++;
	}
	
/*	i = 0;
	while (t[i] != 0)
	{
		node = ft_lstnew(t[i]);
		printf("addin %s\n", node->content);
		ft_lstadd_back(arg, node);
		i++;
	}*/
//	printf("size after addin %d\n", ft_lstsize(*arg));
	return (newlist);
}

t_list	*machi_akhirw7da(t_list **arg, char **t, int x)
{
	t_list	*chyata=NULL;
	t_list	*newlist=NULL;
	t_list	*node;
	int		i;

	i = 0;

	////////// remove the node that contains the tooken /////////////////
//	printf("x %d\n", x);
	i=0;
	while (i < x)
	{
		node = ft_lstnew((*arg)->content);
		ft_lstadd_back(&newlist, node);
//		printf("addin %s\n", node->content);
		(*arg) = (*arg)->next;
		i++;
	}
//	(*arg)->next = newlist;
//	printf("size after addin %d\n", ft_lstsize(newlist));
	///////////////////////// chyata time //////////////////////////////
	(*arg) = (*arg)->next;
	while (*arg != NULL)
	{
		node = ft_lstnew((*arg)->content);
//		printf("addin chyata %s\n", node->content);
		ft_lstadd_back(&chyata, node);
		(*arg) = (*arg)->next;
	}
//	printf("size after addin %d\n", ft_lstsize(chyata));
	////////////////////////////////////////////////////////////////////
	
	/////////////// addin splitted things to newlist //////////////////
	i=0;
	while (t[i] != 0)
	{
		node = ft_lstnew(t[i]);
//		printf("addin splitted %s\n", node->content);
		ft_lstadd_back(&newlist, node);
		i++;
	}
	////////////////////////////////////////////////////////////////////

	while (chyata != NULL)
	{
		node = ft_lstnew(chyata->content);
//		printf("addin chyata %s\n", node->content);
		ft_lstadd_back(&newlist, node);
		chyata = chyata->next;
	}
//	printf("final size %d\n", ft_lstsize(newlist));
	return (newlist);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merg_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 07:54:03 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/28 17:37:25 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

void print_list_x(t_list *a) {

    static int i;
    printf("i = %d \n", i);
   t_list *ptr = a;
   //start from the beginning
   while(ptr)
   {
      printf("declare -x %s\n",ptr -> content);
      ptr = ptr->next;
   }
   i++;
}

t_list* mergesortedlist(t_list* lst1, t_list* lst2) 
{ 
    
	t_list* result = NULL; 
	// Base Cases
	if (lst1 == NULL) 
		return (lst2); 
	else if (lst2 == NULL) 
		return (lst1); 
	if (ft_strncmp(lst1->content ,lst2->content,ft_strlen(lst1->content)) <= 0)
    { 
		result = lst1; 
		result->next = mergesortedlist(lst1->next, lst2); 
	} 
	else
    { 
		result = lst2; 
		result->next = mergesortedlist(lst1, lst2->next); 
	}
	return result; 
}


void mid_list(t_list *list, t_list **fast, t_list **slow)
{
    t_list *ptr2;
    t_list *ptr1;
    
    ptr1  = list ->next;
    ptr2 = list;
	// ptr1 is incrmented twice and ptr2 is icremented once.
	while (ptr1 != NULL)
    { 
		ptr1 = ptr1->next; 
		if (ptr1 != NULL)
        { 
			ptr2 = ptr2->next; 
			ptr1 = ptr1->next; 
		} 
	} 
	// ptr2 is at the midpoint.
	*fast = list; 
	*slow = ptr2->next; 
	ptr2->next = NULL; 
}

void ft_merge_sort(t_list **list)
{
    static int i = 0;
    
    t_list *ptr1;
    t_list *ptr2;
    t_list *head = *list; 

    if ((*list) -> next == NULL || (*list) == NULL)
        return;
    
    mid_list(*list,&ptr1,&ptr2);
    ft_merge_sort(&ptr1);
    ft_merge_sort(&ptr2);
    *list = mergesortedlist(ptr1 ,ptr2);
}


void ft_merge_sort_u(t_list *env)
{
    static int i;
   
    t_list  *new_list;
    
    new_list = NULL;
    new_list = ft_lstmap(env, f, del);
    ft_merge_sort(&new_list);
    i++;
    print_list_x(new_list);
   // ft_lstclear(&new_list,del);
}

/*
int main()
{
	t_list *a;
	t_list *node;
    t_list *n;
	int *ptr;
    char  **tab1;
    tab1 = ft_split("ABDESSA ELOULI SULTAN ALAMI", ' ');
    int i = 0;
    a = ft_lstnew(ft_strdup("1337"));
    while (tab1[i])
	{
        node = ft_lstnew(ft_strdup(tab1[i]));
      //  printf("the content of node is = %d \n", *(int *)a -> content);
        ft_lstadd_back(&a,node);
        i++;
    }
	print_list(a);
    t_list *new_list;
    new_list = ft_lstmap(a, f, del);
   ft_merge_sort(&new_list);
   print_list(a);
    print_list(new_list);
   // printf("\nthe content of node is = %d \n", *(int *)a -> content);//static variable
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:11:46 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/16 18:12:31 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void del(void *ptr)
{
	 free(ptr);
}

void *f(void *ptr)
{
	return(ptr);
}

void print_list(t_list *list,int a)//s= 0 || s=1 print wirh order
{
    while(list != NULL)
    {
        if(ft_strchr(list -> content,'=') && a == 0)
            printf("%s\n", list->content);
        else
            printf("%s \n", list->content);
        list = list->next;
    }
    printf("\n");
}
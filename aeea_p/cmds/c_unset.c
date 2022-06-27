/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 07:22:59 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/26 17:55:04 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include"../excuting_headr.h"

// unset for delet var in env variables
// export for inssrt a local var to environment
// env is the environment variables in environment
// best tutorial for this in https://www.digitalocean.com/community/tutorials/how-to-read-and-set-environmental-and-shell-variables-on-linux

void c_unset(t_list *list, char *str)
{
    int len;
    t_list  *node;
    t_list  *lst;
    char    *ptr;

    lst = list;
    node = 0;
    ptr = 0;
    while (lst)
    {
        len = ft_strlen(str); 
        if (ft_strncmp(str, lst->content, len) == 0)
        {
            if(node == 0)
            {
                ptr = (list -> content);
                list = list -> next;
                free(ptr);
                ptr = 0;
            }
            else
            {
                node -> next = lst->next;
                free(lst -> content);
            }
           break;
        }
        node = lst;
        lst = lst->next;
    }
   e_st = 0;
}
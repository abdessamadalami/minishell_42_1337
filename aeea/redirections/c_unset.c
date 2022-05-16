/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 07:22:59 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/16 17:22:23 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include"minishell.h"

// unset for delet var in env variables
// export for inssrt a local var to environment
//env is the environment variables in environment
// best tutorial for this in https://www.digitalocean.com/community/tutorials/how-to-read-and-set-environmental-and-shell-variables-on-linux

void c_unset(t_list **list, char *str)
{
    int len;
    t_list *node;
    t_list *lst;
    lst = *list;

    node = 0;
    while (lst)
    {
        len = ft_strlen(str); 
        if (ft_strncmp(str, lst->content,len) == 0)
        {
            if(node == NULL)
            {
                node = (*list);
                *list = (*list) -> next;
                node -> next = 0;
               // free(node->content);
            }
            else
            {
                node -> next = lst->next;//the first node
                //free(lst -> content);
            }
           break;
        }
        node = lst;
        lst = lst->next;
    }
}
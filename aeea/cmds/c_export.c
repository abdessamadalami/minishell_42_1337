/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 07:32:13 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/20 09:43:56 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"
#include <stdio.h>

//getenv this function sherch about str in linkedlist and if the
// a = 1 and str in the linked list should change it and other if a = 0
// just return the str if is exist in it 
 
char *ft_getenv(t_list *list, char *str, int a)
{
    int len;
    char *ptr;
    
    while (list)
    {
        len = ft_strlen(str);
        ptr = (char *)list -> content;
        if ((ft_strncmp(str, list->content, len)) == 0 && ptr[len] == '=')
        {
             if(a == 1) //for remplace
            {
                str[ft_strlen(str)]= '=';
                list->content = str;
            }
            else if(a == 2) // a= 2 for += var
            {
               str[ft_strlen(str)]= '=';
               //printf("{%s} \n", str +ft_strlen(str) + 1 );
              // exit(1);
               list->content = ft_strjoin(list->content,str +ft_strlen(str) + 1 ); 
            }
            else if ( a == 3)// for dolar
            {
                return (ptr + len + 1);
            }
            return (list->content);
        }
        list = list->next;
    }
    return (0);
}
/*
*/
void  c_export(t_list *env, char *var)
{
    char *check;
    char *env_var;
    char *str_return;
    int p = 1;

    if (var == 0)
    {
        ft_merge_sort_u(env);
        return;
    }
    check = strchr(var, '=');  //error checking
    if (check == NULL)
        error_handling(var,0);
    else
        error_handling(var, check - var - 1);
    env_var = strdup(var);
    if (check)
    {
        env_var[check - var] = '\0';
        if (env_var[check - var -1] == '+')
        {
           env_var[check - var - 1] = '\0';
            p = 2;
        }
      //  printf(" %s %ld \n",env_var,check - var);
        str_return = ft_getenv(env, env_var,p);
        printf("_%s_ \n\n",str_return);
       // exit(1); //
        if (!str_return)
            ft_lstadd_back(&env,ft_lstnew(var));  
    }
    if (!check && var != NULL)
       ft_lstadd_back(&env, ft_lstnew(var));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 07:32:13 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/16 19:38:00 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>


//getenv this function sherch about str in linkedlist and if the
// a = 1 and str in the linked list should change it and other if a = 0
// just return the str if is exist in it 
 
char *ft_getenv(t_list *list, char *str, int a)
{
    int len;

    while (list)
    {
        len = ft_strlen(str);   
        if (ft_strncmp(str, list->content,len) == 0)
        {
            if(a)
            {
                str[ft_strlen(str)]= '=';
                list->content = str;
            }
            return (list->content);
        }
        list = list->next;
    }
    return (0);
}
/*
*/
void error_hundlening(char *str,int p)
{
    int i;
    
    i = 0;
    if (!str)
        return;
    if (p != 0)
        i = p;
    if (str[0] == '$' && p == 0)  // for dolar handling
        i++;
    if ((!ft_isalnum(str[i])) && str[i] != '_')
    {
        printf("error: `%s': not a valid identifier \n",str);
        exit(1); // chiled
    }
    
}
void  c_export(t_list *env, char *var)
{
    char *check;
    char *env_var;
    char *str_return;

    if (var == 0)
    {
        ft_merge_sort_u(env);
        return;
    }
    check = strchr(var, '=');  //error checking
    error_hundlening(var,check - var - 1);
    env_var = strdup(var);
    if (check)
    {
        env_var[check - var] = '\0';
        printf(" %s %ld \n",env_var,check - var);
        str_return = ft_getenv(env, env_var,1);
        printf("%s\n\n",str_return);
        if (!str_return)
            ft_lstadd_back(&env,ft_lstnew(var));  
        print_list(env ,0);
    }
    if (!check && var != NULL)
       ft_lstadd_back(&env, ft_lstnew(var));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 07:32:13 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/14 16:52:56 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void del(void *ptr)
{
	 free(ptr);
}

void *f(void *ptr)
{
	return(ptr);
}

char *env_var(char *cmd)
{
    if(cmd[0] == '$')
    {
        cmd = cmd + 1;
        cmd = getenv(cmd);
    }
    cmd = getenv(cmd);
    return cmd;
}

void print_list(t_list *list)//s= 0 || s=1 print wirh order
{
    while(list != NULL)
    {
        printf("%s\n", list->content);
        list = list->next;
    }
}

t_list *env_list(char **env)
{
    int index;
    t_list *list;
    t_list *node;
    
    index = 0;
    list = 0;
    while(env[index] != NULL)
    {
        node = ft_lstnew(env[index]);
        ft_lstadd_back(&list, node);
        index++;
    }
 
    return list;
}

t_list  *c_env(char **env)
{
      // this is the environment for cmd env and for the current prossece 
     return (env_list(env));
}

char *ft_getenv(t_list *list, char *str, int a)
{
    int len;

    while (list)
    {
        len = ft_strlen(str);   
        if (ft_strncmp(str, list->content,len) == 0 && a == 1)
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
void  c_export(t_list *env, char *var)
{
    char *check;
    char *env_var;
    char *str_return;

    if (var == 0)
    {
        ft_merge_sort_u(env);
        exit(0);
      //  print_list(env);
    }
    
    check = strchr(var, '=');
    env_var = strdup(var);
     printf(" _%s_ \n",env_var);
    if (check)
    {
        env_var[check - var] = '\0';
         printf(" %s %ld \n",env_var,check - var);
        str_return = ft_getenv(env, env_var,1);
        printf("%s\n\n",str_return);
        print_list(env);
    }
}
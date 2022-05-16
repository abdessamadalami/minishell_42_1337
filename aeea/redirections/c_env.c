/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:53:11 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/16 13:20:18 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
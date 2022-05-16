/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_$.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:22:02 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/16 18:56:35 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>

void error_hundlening(char *str,int p)
{
    int i;

    i = 0;
    if (str[0] == '$')
       i++;
    if ((str[i] < 'a' && str[i] > 'z') || str[i] > 'Z' && str[i] <'A' 
        || str[i] != '_')
    {
        perror(str);
        exit(1);// chiled
    }
    
}


char *env_var(char *var, t_list **env ,int a)
{
    if(var[0] == '$')
    {
        var = var + 1;
        var = ft_getenv(var, env, a);
    }
    return (var);
}

// int main(int argc, char *argv[], char **env)
// {
//   printf(" %s ", env_var("$var",env));
//   perror("><<");
// }
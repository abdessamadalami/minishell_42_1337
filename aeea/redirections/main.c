/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:52:46 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/14 16:53:13 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv , char **env)
{
    t_list *env_lst;
    char *cmd = "ev";
    printf("_________________________________ \n");
    env_lst = c_env(env);
    print_list(env_lst);
    if(ft_strncmp("env",cmd,3) == 0)
        print_list(env_lst);
    // c_export(env_lst,0);
    // c_export(env,"var=76");
    ///the position in linded list i think is good sort it 
    return 0;
}
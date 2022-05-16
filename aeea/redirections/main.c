/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:52:46 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/16 17:52:48 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv , char **env)
{
    t_list *env_lst;
    // char *cmd = "env";
    // printf("_________________________________ \n");
     env_lst = c_env(env);
   // env_lst = c_env(ft_split("1337 abd esssamadalami alami elouali",' '));
   //   print_list(env_lst);
    // if(ft_strncmp("env",cmd,3) == 0)
    //     print_list(env_lst);
   // c_export(env_lst,"sd=abdessamd");//make sure with exmple "sd = abdessamd"
    c_export(env_lst,"elouali");
    printf("_________________________________ \n");
    c_export(env_lst,0);
    // print_list(env_lst);
    // c_export(env_lst,0);
    ///the position in linded list i think is good sort it 
    printf("_________________________________ \n");
    ////////////////////////////////////////////////////////////////
    c_unset(&env_lst ,"elouali");
    c_export(env_lst,0);
    //system("leaks a.out");
    return 0;
}
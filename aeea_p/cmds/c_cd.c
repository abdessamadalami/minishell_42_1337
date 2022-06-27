/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 08:34:05 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/26 16:41:53 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

int cd_error(char **argv)
{
    printf("%s : No such file or directory\n", argv[1]);
    e_st = 1;
    return (1);
}

 static void export_path(char *new_pwd, char *old_pwd, t_list *env)
 {
    char    *t_new;
    char    *t_old;
    
    t_new = new_pwd;
    t_old = old_pwd;
    c_export(env, old_pwd);
    c_export(env, new_pwd);
    e_st = 0;
    free(t_new);
    free(t_old); 
 }

int c_cd(t_list *env, char **argv )
{
    char    *new_pwd;
    char    *old_pwd;

     old_pwd = getcwd(0,0);
     if (old_pwd == NULL)
        old_pwd = ft_strdup(" ");
    if (argv[1] == NULL)
        argv[1] = ft_getenv(env, "HOME=", 0) + 5; 
    if (chdir(argv[1]) == -1)
    {
        free(old_pwd);
        return(cd_error(argv));
    }
    new_pwd = getcwd(0,0);
    if (ft_strncmp(new_pwd,"//\0", 4)==0)
        new_pwd = ft_strdup("PWD=//");
    else
        new_pwd = ft_strjoin_n(ft_strdup("PWD="), new_pwd);
    old_pwd = ft_strjoin_n(ft_strdup("OLDPWD="), old_pwd);
    export_path(new_pwd, old_pwd, env);
    return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 08:34:05 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/02 12:53:30 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

int c_cd(t_list *env,char **argv )
{
    int a = getpid();
    char *str;
    //printf("argv %s\n", argv[1]);
    char *directory = "libft";
    str = ft_getenv(env, "PWD", 0);//? put attaching her
    printf(" %s \n", str); 
    str = ft_strjoin(ft_strdup("OLD"), str);
    printf("new str %s\n", str);
    c_export(env, str);
    printf("I am here the prossece %d\n",a);
    chdir (directory);
    str = ft_strjoin(str ,ft_strjoin("/", directory));
    c_export(env, str + 3);
    return (1);
}

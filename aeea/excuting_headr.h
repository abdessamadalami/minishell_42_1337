/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excuting_headr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:41:41 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/18 19:07:56 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCUTING_HEADR_H
#define EXCUTING_HEADR_H
#include <stdio.h>
#include "pipex/pipex_42_1337.h"
#include "libft/libft.h"
#define EXIT_S = 0;
 
// int *exit_s = 0;
void std_files(char *std_out, int fd);//minishell intra video
void error_handling(char *str, int p);
void here_doc(char *lim);
void redirect_output(char *std_out, char c);
void redirect_input(char *std_in);
void ft_merge_sort(t_list **list);
void mid_list(t_list *list, t_list **fast, t_list **slow);
void g_redirections(char *cmd, char *red); //we can addapt it 
void ft_merge_sort_u(t_list *env);
void *f(void *ptr);
void del(void *ptr);
void print_list(t_list *list,int a);
void  c_export(t_list *env, char *var);
t_list  *c_env(char **env);
void c_unset(t_list **list, char *str);
char *env_var(char *arg, t_list **env ,int a);
char *ft_getenv(t_list *list, char *str, int a);
void exit_status();
char	*get_path_env(t_list *env, char *cmd);
void  error_printf(int a , char *cmd);
void print_tab(char **str);

#endif
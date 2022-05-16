/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:41:41 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/16 14:57:06 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
#include<stdio.h>
#include "../pipex/pipex_42_1337.h"
#include "../libft/libft.h"

void std_files(char *std_out, int fd);//minishell intra video
void here_doc(char **argc);
void redirect_output(char *std_out, char c);
void redirect_input(char *std_in);
void ft_merge_sort(t_list **list);
void mid_list(t_list *list, t_list **fast, t_list **slow);
void g_redirections(char *cmd,char **eng,char **env,char *red); //we can addapt it 
void ft_merge_sort_u(t_list *env);
void *f(void *ptr);
void del(void *ptr);
void print_list(t_list *list,int a);
void  c_export(t_list *env, char *var);
t_list  *c_env(char **env);
void c_unset(t_list **list, char *str);

#endif
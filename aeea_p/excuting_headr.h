/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excuting_headr.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:41:41 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/02 19:47:31 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCUTING_HEADR_H
# define EXCUTING_HEADR_H

# include <stdio.h>
# include "pipex/pipex_42_1337.h"
# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

//void	rl_replace_line (const char *text, int clear_undo);

typedef struct s_var
{
	int		std_out;
	int		std_in;
	int		to_close;
	int		fd[2];
	int		a;
	int		b;
	int		n_p;
	int		*ids;
	t_list	*fds_std_in;
}	t_var;

typedef struct s_var1
{
	char	*str;
	int		bol;
	int		rturnv;
	int		bol2;
	int		gg;
}	t_var1;

int		f_building(t_list **env, t_list *pars_il, t_var *v_pipe);
void	fr(t_list *fds);
int		redir(t_list **list, int *bol, int *std_in, int *std_out);
char	*ft_getenv(t_list *list, char *str, int a);
int		print_listt(t_list *list, int a);
void	handler_sig(int sig);
int		chiled_processe(t_list *pars_il, t_list *env, int std_in, int std_out);
void	pipe_excuting(t_var *v_pipe, t_list **env, t_list *pars_il);
int		ft_echo_o(char **av);
void	ft_pwd(void);
void	pipe_aff(t_var *v_pipe, int n_p, int i);
int		error_handlin_g(char *str, int f);
int		error_handling_e(char *str, int p);
char	*ft_strjoin_n(char *s1, char *s2);
int		redirect_inpu(char *std_in);
int		*ff(int a);
int		check_redirec_d(t_list *lst);
char	**make_arrenv(t_list *env);
int		chiled_build(t_list *pars_il, t_list *env, int std_in, int std_out);
int		check_redirec_list(t_list *pars_il);
void	delete_here(t_list **lst);
void	printf_err(t_list *str);
int		redirect_inpu(char *std_in);
t_list	*chec_for_here_doc(t_list **lst, t_list *env);
void	close_aff(t_var *v_pipe);
int		pip_number(t_list *list);
void	wait_exit_status(int *ids, int n_p);
int		g_st;
void	dup_parm(t_list **pars_il, int *fd, t_list **std_in);
void	get_par( t_list *list, char *env);
void	std_files(char *std_out, int fd);//minishell intra video
int		error_handling(char *str);
int		here_doc(char *lim, t_list *env);
int		redirect_output(char *std_out, char c);
int		redirect_input(char *std_in);
void	ft_merge_sort(t_list **list);
void	mid_list(t_list *list, t_list **fast, t_list **slow);
int		g_redirections(char *cmd, char *red,
			int *std_in, int *std_out);//we can addapt it 
void	ft_merge_sort_u(t_list *env);
void	*f(void *ptr);
void	del(void *ptr);
void	print_list(t_list *list, int a);
void	c_export(t_list *env, char *var);
t_list	*c_env(char **env);
void	c_unset(t_list *list, char *str);
char	*env_var(char *arg, t_list **env, int a);
char	*ft_getenv(t_list *list, char *str, int a);
void	exit_status(void);
char	*get_path_env(t_list *env, char *cmd);
void	error_printf(char *cmd);
void	print_tab(char **str);
int		check_redirec(char *red);
char	*get_path_env(t_list *env, char *cmd);
int		check_for_pipe(char *str);
int		chec_for_cmds(char **argv, t_list *env);
int		executing(t_list *pars_il, t_list **env);
t_list	*make_list_fork(t_list *list);
int		chec_for_pipe(t_list *list);
char	**make_argv(t_list *list, t_list *env, int *std_in, int *std_out);
void	c_exit(char **args);
int		c_cd(t_list *env, char **argv);

#endif
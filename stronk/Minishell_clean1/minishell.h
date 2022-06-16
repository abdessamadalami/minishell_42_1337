/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:04:48 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/16 14:57:44 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_gg
{
	int	count;
	int	lock;
	int	qq;
}	t_gg;
// ---------------- struct --------------------//

typedef struct s_normsht
{
	int	count;
	int	init;
}	t_normsht;

typedef struct s_squsplit
{
	int	x;
	int	y;
	int	count;
	int	temp;
}	t_squsplit;
typedef struct s_arg
{
	char			*data;
	struct s_arg	*next;
}	t_arg;

// --------------------- parsing -------------------------//
void	parse_quotes_fordq(char *s, char *t, int *i, int *j);
void	parse_quotes_forsq(char *s, char *t, int *i, int *j);
void	parse_quotes_lastone(char *s, char *t, int *i, int *j);
t_arg	*ft_parsing(char *s);
t_arg	*parsin_dyalbss7(t_arg *arg, t_gg *gg);
t_arg	*remove_quotes(t_arg *arg);
t_arg	*parsing_spaces(char *s);
t_arg	*fill_list(char **t);
int		spaces_counter(char *s);
t_arg	*parsing_wildcard(t_arg *arg);
int		check_so(char *s1, char c);
int		check_q(char *s);
char	get_token(char *s);
char	get_qtoken(char *s);
int		check_qso(char *s);
void	check_syntax(t_arg *arg);
char	first_occc(char *s);
char	last_occc(char *s);
int		count_q(char *s, char c);
t_arg	*check_for_dollar(t_arg *arg);

// --------------------- splits -------------------------//
char	**squsplit(t_gg *gg, char *s);
char	**sosplit(char *s);
char	**wildsplit(char *s);
void	check_sdq(char *s, t_squsplit *sq, int *i);
void	just_awhile(char *s, t_squsplit *sq, int *i);
void	random_if(char *s, int *i);

// ---------------- syntax checking --------------------//
void	check_syntax(t_arg *arg);

//>> 	check redirections
void	check_red(t_arg *s);
int		check_red_condition(char *s, int i, int count);

//>> 	check pipes
void	check_pip(t_arg *s);

//>> 	check quotes
int		*count_sdq(char *s, char f, char l);
void	count_quotes(char *s, int x, int y);
void	check_qt(t_arg *s);
char	first_occc(char *s);
char	last_occc(char *s);
void	print_if(int x, int y);
int		just_while(char *s, char c, int i);

//>>	env variables
int		is_alphanum(char c);
void	normal_case(char **t, char *s, int *i, int *j);
void	mult_case(char **t, int count, int *j);
void	ft_lock(char c, int *lock, int *dlock);

// --------------------- utils ------------------------//
char	*ft_strdp(char *s1);
int		ft_strln(char *s);
int		ft_strllen(char **s);
char	*ft_strjn(char *s1, char *s2);
char	*ft_subtr(char	*s, int start, int len);
char	*ft_ssubtr(char	*s, int start, int len);
void	*ft_calloc(int count, int size);
int		check_isvalid(t_arg *cmds);
char	**dosplit(char *s, char c);
int		so_counter(char *s);
t_arg	*ftlstnew(char	*s);
int		ftlstsize(t_arg *lst);
void	ftlstadd_front(t_arg **lst, t_arg *new);
void	ftlstadd_back(t_arg **lst, t_arg *new);
t_arg	*lst_lastone(t_arg **arg, char **t, int x);
t_arg	*lst_between(t_arg **arg, char **t, int x);
t_arg	*akhirw7da(t_arg **arg, char **t, int x);
t_arg	*machi_akhirw7da(t_arg **arg, char **t, int x);
void	addbacki_sf(t_arg **sfa, char **t);
char	*ft_itoa(int n);
int		is_there_dq(char *s);

//>>	dollar handling:
int		checki_checki(char *s);
int		check_dollar_mark(char *s);
int		check_dollar(char *s);
int		check_qdollar(char *s);
int		lot_ofthem(char *s);
void	handle_mixed_quotes(t_arg *sfa, char *s);
void	bzzaf_tdollarats(t_arg *sfa, char *s);
int		conditions_topassd(char c);
int		ds_index(char *s);
char	*check_get_env(char *s, char *var, int *lock, int *i);
char	**getsplitted(char *s);
void	addback_wsf(t_arg *z3ta, char *s);
char	*ft_allocate(char *s);
char	**getsplitted(char *s);
void	lock_malo2(char c, char v, int *lock);
void	lock_malo(char c, int *lock);
void	put_z3tindaplaces2(t_arg *sfa, t_arg *z3ta, char *s);
void	addback_wsf2(t_arg **z3ta, char *s);
char	*check_get_env2(char *var, int *lock);

t_arg	*check_envvars(t_arg *arg);

// --------------------- errors -----------------------//
void	print_syntax_error(int x, char c);

// -------------------- builtins ----------------------//
void	ft_echo(char **s, int x);
void	ft_pwd(void);

#endif

#ifndef MINISHELL_H
#define MINISHELL_H

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

typedef struct s_arg
{
	char	*data;
	struct s_arg	*next;
}	t_arg;


int		ft_exec(char **av, char **path, char **envp);
char	*get_new_path(char **path, char *cmd);

// ----------------- path ---------------------//
char	**get_path(void);


// ---------------- utils --------------------//
//char	**ft_msplit( char *s, char c);			
char	**ssplit(t_gg *gg, char *s, char c);
char	**sosplit(char *s);
char	**qusplit(char *s, char c);
char	**squsplit(t_gg *gg, char *s);
char	*ft_strdp(char *s1);
int		ft_strln(const char *s);
int		ft_strllen(char **s);
char	*ft_strjn(char *s1, char *s2);
char	*ft_subtr(char	*s, int start, int len);
int		check_isvalid(t_arg *cmds);
char	*ft_sstrcat(char c);

/*					list utils				*/
t_arg	*ftlstnew(char	*s);					//
int		ftlstsize(t_arg *lst);					//
//t_arg	*ftlstlast(t_arg *lst);				//
void	ftlstadd_front(t_arg **lst, t_arg *new);//
void	ftlstadd_back(t_arg **lst, t_arg *new);//
t_arg	*lst_lastone(t_arg **arg, char **t, int x);
t_arg	*lst_between(t_arg **arg, char **t, int x);
t_arg	*akhirw7da(t_arg **arg, char **t, int x);
t_arg	*machi_akhirw7da(t_arg **arg, char **t, int x);
void	addbacki_sf(t_arg **sfa, char **t);

// ---------------- parsing ------------------//
t_arg	*ft_parsing(char *s);
int		check_so(char *s1, char c);
int		check_q(char *s);
char	get_token(char *s);
char	get_qtoken(char *s);
int		check_qso(char *s);

// --------------- builtins -----------------//
void	ft_echo(char **s, int x);
void	ft_cd(char *path);
void	ft_pwd(void);

#endif
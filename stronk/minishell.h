#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
/*
typedef struct s_arg
{
	char	*cmad;
	char	**args;
	char	**so;
}				t_arg;

typedef	struct	scmd
{
	char	**line;
	char	**env;
	char	**path;
	char	**temp;
	// char 	**cmd;
	// char	**args;
	t_arg	*cmd;
	char	**flags;
	char	*sign;
	char	*var;
	int		input;
	int		output;
	int		lock;
}				tcmd;
*/
typedef struct s_gg
{
	int				count;
	int				lock;
}	t_gg;
// ---------------- struct --------------------//
	//-- cmd --//
typedef struct s_arg
{
	char			*data;

	// char	**line;
//	char			**path;
	// int				count;
	// int				lock;
	struct s_arg	*next;
}	t_arg;

	//--  arg --//





int		ft_exec(char **av, char **path, char **envp);
char	*get_new_path(char **path, char *cmd);

// ----------------- path ---------------------//
char	**get_path(void);


// ---------------- utils --------------------//
char	**ft_split( char *s, char c);
char	**ssplit(t_gg *gg, char *s, char c);
char	**sosplit(char *s);
//char	**qsplit(t_cmd *cmds, char *s);
char	*ft_strdup(char *s1);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char	*s, int start, int len);
int		check_isvalid(t_arg *cmds/*char **path, char **cmd*/);

/*					list utils				*/
t_arg	*ft_lstnew(char	*s);
int		ft_lstsize(t_arg *lst);
t_arg	*ft_lstlast(t_arg *lst);
void	ft_lstadd_front(t_arg **lst, t_arg *new);
void	ft_lstadd_back(t_arg **lst, t_arg *new);
void	lst_lastone(t_arg **arg, char **t, int x);
void	lst_between(t_arg **arg, char **t, int x);

// ---------------- parsing ------------------//
int		ft_new_parsing(char *s);


// --------------- commands -----------------//
void	ft_echo(char *s, int x);
void	ft_cd(char *path);
void	ft_pwd(void);

#endif
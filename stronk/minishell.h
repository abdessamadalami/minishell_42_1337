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
}				t_list;

typedef	struct	scmd
{
	char	**line;
	char	**env;
	char	**path;
	char	**temp;
	// char 	**cmd;
	// char	**args;
	t_list	*cmd;
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
	int	qq;
}	t_gg;
// ---------------- struct --------------------//
	//-- cmd --//
typedef struct s_list
{
	char			*content;
	int		q;
	// char	**line;
//	char			**path;
	// int				count;
	// int				lock;
	struct s_list	*next;
}	t_list;

	//--  arg --//





int		ft_exec(char **av, char **path, char **envp);
char	*get_new_path(char **path, char *cmd);

// ----------------- path ---------------------//
char	**get_path(void);


// ---------------- utils --------------------//
//char	**ft_split( char *s, char c);
char	**ssplit(t_gg *gg, char *s, char c);
char	**sosplit(char *s);
char	**qusplit(char *s, char c);
char	**squsplit(t_gg *gg, char *s, char c);
char	*ft_strdup(char *s1);
//int		ft_strlen(const char *s);
int		ft_strllen(char **s);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_substr(char	*s, int start, int len);
int		check_isvalid(t_list *cmds/*char **path, char **cmd*/);
char	*ft_sstrcat(char c);

/*					list utils				*/
t_list	*ft_lstnew(char	*s);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*lst_lastone(t_list **arg, char **t, int x);
t_list	*lst_between(t_list **arg, char **t, int x);
t_list	*akhirw7da(t_list **arg, char **t, int x);
t_list	*machi_akhirw7da(t_list **arg, char **t, int x);
void	addbacki_sf(t_list **sfa, char **t);

// ---------------- parsing ------------------//
t_list		*ft_new_parsing(char *s);


// --------------- commands -----------------//
void	ft_echo(char *s, int x);
void	ft_cd(char *path);
void	ft_pwd(void);

#endif
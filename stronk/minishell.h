#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_arg
{
	char	*cmad;
	char	**args;
}				t_arg;

typedef	struct	s_cmd
{
	char	**line;
	char	**env;
	char	**path;
	// char 	**cmd;
	// char	**args;
	t_arg	*cmd;
	char	**flags;
	char	*sign;
	char	*var;
	int		input;
	int		output;
	int		lock;
}				t_cmd;



int		ft_exec(char **av, char **path, char **envp);
char	*get_new_path(char **path, char *cmd);

// ----------------- path ---------------------//
char	**get_path(void);


// ---------------- utils --------------------//
char	**ft_split( char *s, char c);
char	**ssplit(t_cmd *cmds, char *s, char c);
char	*ft_strdup(char *s1);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char	*s, int start, int len);
int		check_isvalid(t_cmd *cmds/*char **path, char **cmd*/);

// ---------------- parsing ------------------//
int		ft_parsing(t_cmd *cmds, char *s, char **envi);


// --------------- commands -----------------//
void	ft_echo(char *s, int x);
void	ft_cd(char *path);
void	ft_pwd(void);

#endif
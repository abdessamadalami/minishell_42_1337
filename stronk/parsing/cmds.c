#include "minishell.h"

int	ft_exec(char **av, char **path, char **envp)
{
	char	*s;
	char	**cmd;

	cmd = ft_split(av[2], ' ');
	if (!cmd)
		exit(1);
	s = get_new_path(path, cmd);
	if (!s)
		return (0);
	free(path);
	if (execve(s, cmd, envp) == -1)
		return (0);
	free(s);
	free(cmd);
	return (1);
}

void	ft_echo(char *av, char **env)
{
	char **path;
	char	**s;

	path = get_path(env);
	s = ft_split(av, ' ');
//	get_new_path();
	ft_exec(s, path, env);
}

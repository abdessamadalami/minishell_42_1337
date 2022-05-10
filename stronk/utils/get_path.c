#include "../minishell.h"

int	check_line(char	*s)
{
	int		i;
	char	*p;

	i = 0;
	p = ft_strdup("PATH");
	while (p[i])
	{
		if (s[i] != p[i])
		{
			free(p);
			return (0);
		}
		i++;
	}
	free(p);
	return (1);
}

char	*get_line_(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (check_line(envp[i]))
			return (&(envp[i][5]));
		i++;
	}
	return (NULL);
}

char	**get_path(char **envp)
{
	char	*line;
	char	**path;

	line = get_line_(envp);
	if (!line)
		return (NULL);
	//	free_and_exit(&line);
	path = ft_split(line, ':');
	if (!path)
		return (NULL);
		// free_and_exit(path);
	return (path);
}

char	*get_new_path(char **path, char **cmd, int x)
{
	int		i;
	char	*t;

	i = 0;
	while (path[i])
	{
		t = ft_strjoin(path[i], cmd[x]);
		if (!t)
			return (NULL);
			// free_and_exit(&t);
		if (!access(t, 0))
			return (t);
		i++;
		free(t);
	}
	return (NULL);
}
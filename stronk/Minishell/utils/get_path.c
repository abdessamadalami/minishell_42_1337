/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:28:26 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/12 16:30:39 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	**get_path(void)
{
	char	*line;
	char	**path;

	// line = get_line_(envp);
	
	//	free_and_exit(&line);
	line = getenv("PATH");
	if (!line)
		return (NULL);
	path = ft_split(line, ':');
	if (!path)
		return (NULL);
		// free_and_exit(path);
	return (path);
}

char	*get_new_path(char **path, char *cmd)
{
	int		i;
	char	*t;

	i = 0;
	while (path[i])
	{
		t = ft_strjoin(path[i], cmd);
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

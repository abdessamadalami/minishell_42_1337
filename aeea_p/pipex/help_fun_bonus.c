/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:00:26 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/01 07:57:17 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_42_1337.h"

int	get_index_of_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			return (i);
		i++;
	}
	return (0);
}

char	*get_path(char **env, char *cmd)
{
	int		i;
	char	*str;
	char	*ptr;
	char	**str1;

	i = 0;
	str = env[get_index_of_path(env)] + 5;
	str1 = ft_split(str, ':');
	while (str1[i] != 0)
	{
		str = str1[i];
		str1[i] = ft_strjoin(str1[i], "/");
		free (str);
		ptr = ft_strjoin(str1[i], cmd);
		if (access(ptr, 0) != 0)
		{
			free(ptr);
			ptr = 0;
		}
		else
			break ;
		i++;
	}
	free_function(str1);
	return (ptr);
}

void	free_function(char **str)
{
	int	i;

	i = 0;
	if (str == 0)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	failed_function(char *path, char **engvic)
{
	error_print(engvic);
	free(path);
	free_function(engvic);
	exit(0);
}

void	close_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

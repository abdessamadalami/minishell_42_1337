/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_42_1337_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:17:01 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/19 11:11:29 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_42_1337.h"

char	*path_chec(char **engvic, char **env)
{
	char	*path;

	path = 0;
	if (access_func(engvic) != 0)
		path = access_func(engvic);
	else
		path = get_path(env, engvic[0]);
	return (path);
}

void	wrong_file(char *path, int *fd, char **engvic)
{
	free(path);
	free_function(engvic);
	close_pipe(fd);
	exit(0);
}

void	chiled_prossice(int file, t_fd *fd_c, int *fd, int i)
{
	char	**engvic;
	char	*path;
	char	*name;
	
	name = fd_c -> argv[fd_c->argc - 1];
	fd_c -> std_out = fd[1];
	engvic = ft_split(fd_c -> argv[i], ' ');
	path = path_chec(engvic, fd_c -> env);
	close(fd[0]);
	if (file == -1 && i == 2)
		wrong_file(path, fd, engvic);
	if (i == 2 || (ft_strncmp(fd_c -> argv[1], "here_doc", 9) == 0 && i == 3))
		fd_c -> std_in = file;
	else if (i == fd_c->argc - 2)
		fd_c -> std_out = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd_c -> std_in, 0);
	dup2(fd_c -> std_out, 1);
	execve(path, engvic, fd_c -> env);
	failed_function(path, engvic);
}

void	process_ing(char **argc, char **env, int file, int argv)
{
	int		fd[2];
	int		id2;
	t_fd	fd_c;
	int		i;

	i = 2;
	fd_c.argv = argc;
	fd_c.env = env;
	fd_c.argc = argv;
	if (ft_strncmp(argc[1], "here_doc", 9) == 0)
		i = i + 1;
	while (i <= argv - 1)
	{
		pipe(fd);
		id2 = fork();
		if (id2 == 0)
			chiled_prossice(file, &fd_c, fd, i);
		close(fd[1]);
		if (fd_c.to_close)
			close(fd_c.to_close);
		fd_c.std_in = fd[0];
		fd_c.to_close = fd_c.std_in;
		i++;
	}
}

void	pipex_42(int argv, char **argc, char **env, int file)
{
	int	i;

	i = 1;
	if (ft_strncmp(argc[1], "here_doc", 9) != 0 && access(argc[1], R_OK))
		perror(argc[1]);
	if (ft_strncmp(argc[1], "here_doc", 9) != 0)
		file = open(argc[1], O_RDONLY, 0644);
	process_ing(argc, env, file, argv);
	while (wait(0) != -1)
	{
	}
}

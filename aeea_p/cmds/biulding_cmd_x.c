/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biulding_cmd_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:55:36 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/01 07:58:01 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

static void	catch_s(int id)
{
	int	exit_s;

	exit_s = 0;
	waitpid(id, &exit_s, 0);
	if (WIFEXITED(exit_s))
		g_st = WEXITSTATUS(exit_s);
}

static void	exe_c(int *id, char *path, char **argv, t_list *env)
{
	*id = fork();
	if (*id == 0)
	{
		if (access_func(argv))
			path = access_func(argv);
		else
			path = get_path_env(env, argv[0]);
		if (path == 0)
		{
			free(path);
			error_printf(argv[0]);
			free_function(argv);
		}
		execve(path, argv, make_arrenv(env));
		free(path);
		free_function(argv);
	}
}

int	chiled_build(t_list *pars_il, t_list *env, int std_in, int std_out)
{
	char	*path;
	char	**argv;
	int		cmd;
	int		id;

	std_out = 1;
	path = 0;
	argv = make_argv(pars_il, env, &std_in, &std_out);
	if (argv == 0 || std_in == -1 || std_out == -1)
	{
		free_function(argv);
		return (1);
	}
	dup2(std_in, 0);
	dup2(std_out, 1);
	cmd = chec_for_cmds(argv, env);
	if (cmd != 1)
	{
		exe_c(&id, path, argv, env);
		catch_s(id);
	}
	free_function(argv);
	return (1);
}

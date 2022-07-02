/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:53:29 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/02 19:39:17 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

void	close_aff(t_var *v_pipe)
{
	close(v_pipe->fd[1]);
	if (v_pipe->to_close)
		close(v_pipe->to_close);
	v_pipe->std_in = v_pipe->fd[0];
	v_pipe->to_close = v_pipe->std_in;
}

void	pipe_aff(t_var *v_pipe, int n_p, int i)
{
	if (i == n_p)
		(*v_pipe).std_out = 1;
	else if (n_p > 0)
	{
		pipe(v_pipe->fd);
		(*v_pipe).std_out = v_pipe ->fd[1];
	}
}

int	f_building(t_list **env, t_list *pars_il, t_var *v_pipe)
{
	int	a;

	a = 0;
	v_pipe->n_p = pip_number(pars_il);
	if (v_pipe->n_p == 0)
		a = chiled_build(pars_il, *env, v_pipe->std_in, v_pipe->std_out);
	if (a == 1)
	{
		dup2(v_pipe->a, 0);
		dup2(v_pipe->b, 1);
		return (1);
	}
	v_pipe->ids = malloc((v_pipe->n_p + 1) * sizeof(int));
	if (v_pipe->ids == 0)
		return (1);
	return (0);
}

int	chiled_processe(t_list *pars_il, t_list *env, int std_in, int std_out)
{
	char	*path;
	char	**argv;
	int		cmd;

	path = 0;
	argv = make_argv(pars_il, env, &std_in, &std_out);
	dup2(std_in, 0);
	dup2(std_out, 1);
	cmd = chec_for_cmds(argv, env);
	if (std_in == -1 || argv == 0 || cmd == 1)
		exit(1);
	if (std_in != -1)
	{
		if (access_func(argv))
			path = access_func(argv);
		else
			path = get_path_env(env, argv[0]);
		if (path == 0)
			error_printf(argv[0]);
		execve(path, argv, 0);
	}
	return (0);
}

void	pipe_excuting(t_var *v_pipe, t_list **env, t_list *pars_il)
{
	int	i;

	i = 0;
	while (i <= v_pipe->n_p)
	{
		if (pars_il == 0)
			break ;
		pipe_aff(v_pipe, v_pipe->n_p, i);
		v_pipe->ids[i] = fork();
		if (v_pipe->ids[i] == 0)
			chiled_processe(pars_il, *env, v_pipe->std_in, v_pipe->std_out);
		close_aff(v_pipe);
		dup_parm(&pars_il, &v_pipe->std_in, &v_pipe->fds_std_in);
		i++;
	}
	wait_exit_status(v_pipe->ids, v_pipe->n_p);
	dup2(v_pipe->a, 0);
	dup2(v_pipe->b, 1);
}

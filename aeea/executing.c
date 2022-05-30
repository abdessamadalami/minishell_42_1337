/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:40:34 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/30 16:25:26 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "excuting_headr.h"


static int chiled_processe(t_list *pars_il ,t_list *env, int std_in, int std_out)
{
	char	*path;
	char	**argv;
	int		cmd;	

	cmd = 0;
	argv = make_argv(pars_il, env);
	cmd = chec_for_cmds(argv, env);
	if (!cmd && std_in != -1)
	{
		path = get_path_env(env, argv[0]);
		//close(fd[0]);//!close
		if(path == NULL)
			 error_printf(argv[0]);//!free memory
		dup2(std_in, 0);
		dup2(std_out, 1);
		execve(path, argv, 0);
	}
	if(cmd == 1)
		return 1;
	return 0;
}


static void pipe_aff(t_var *v_pipe ,int n_p ,int i)
{
	if (n_p > 0)
		{
			pipe(v_pipe ->fd);
			(*v_pipe).std_out = v_pipe ->fd[1];
		}
		if (i == n_p)
			(*v_pipe).std_out = 1;
}

static int f_building(int *n_p, t_list *env, t_list *pars_il , int **ids)
{
	int a;

	a = 0;
	*n_p = pip_number(pars_il);
	if (*n_p == 0)
		 a = chiled_processe(pars_il, env,-1,-1);
	if (a == 1)
		return (1);
	*ids = malloc((*n_p + 1) * sizeof(int));//!good
	if (ids == NULL)
		return (1);
	return (0);
}

void executing(t_list *pars_il, t_list *env)
{
	int		*ids;
	int 	i;
	int		n_p;
	t_var	v_pipe;

	i = 0;
	if (f_building(&n_p,env, pars_il, &ids) == 1)
		return;
	while (i <= n_p)
	{
		pipe_aff(&v_pipe, n_p, i);
		ids[i] = fork();
		if (ids[i] == 0)
		{
		  	//?if we have pipe with building command we must exit thr child prossece
			if(chiled_processe(pars_il, env, v_pipe.std_in, v_pipe.std_out))
				exit(0);
		}
		close_aff(&v_pipe);
		if (dup_parm(&pars_il, v_pipe.fd) == 0 && n_p > 0)
			break;
		i++;
	}
	wait_exit_status(ids, n_p);
}
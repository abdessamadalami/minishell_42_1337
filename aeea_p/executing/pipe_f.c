/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:53:29 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/26 19:56:08 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

void close_aff(t_var *v_pipe)
{
    close(v_pipe->fd[1]);
    if (v_pipe->to_close)
        close(v_pipe->to_close);
    v_pipe->std_in = v_pipe->fd[0];
    v_pipe->to_close = v_pipe->std_in;
}

void pipe_aff(t_var *v_pipe ,int n_p ,int i)
{
	if (i == n_p)
		(*v_pipe).std_out = 1;
	else if (n_p > 0)
	{
		pipe(v_pipe->fd);
		(*v_pipe).std_out = v_pipe ->fd[1];
	}
}

void pipe_excuting(t_var *v_pipe, t_list **env, t_list *pars_il)
{
	int i;
	
	i = 0;
	while (i <= v_pipe->n_p)
	{
		if(pars_il == 0)
			break;
		pipe_aff(v_pipe , v_pipe->n_p , i);
		v_pipe->ids[i] = fork();
		if (v_pipe->ids[i] == 0)
			chiled_processe(pars_il, *env, v_pipe->std_in, v_pipe->std_out);
		close_aff(v_pipe);
		dup_parm(&pars_il, &v_pipe->std_in ,&v_pipe->fds_std_in);
		i++;
	}
	wait_exit_status(v_pipe->ids, v_pipe->n_p);
	dup2(v_pipe->a,0);
	dup2(v_pipe->b,1);
}
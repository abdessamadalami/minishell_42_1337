/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:40:34 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/02 19:43:50 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

char	**make_arrenv(t_list *env)
{
	char	*str;
	char	*temp;
	char	**ptr;

	str = 0;
	while (env)
	{
		temp = str;
		str = ft_strjoin(str, env->content);
		free(temp);
		str = ft_strjoin(str, " ");
		env = env->next;
	}
	ptr = ft_split(str, ' ');
	return (ptr);
}

t_list	*here_doc_return(t_list **pars_il, t_list *env)
{
	t_list	*fds_std_in;

	fds_std_in = 0;
	fds_std_in = chec_for_here_doc(pars_il, env);
	return (fds_std_in);
}

void	init_v(t_var *v_pipe)
{
	v_pipe->a = dup(0);
	v_pipe->b = dup(1);
	v_pipe->std_in = 0;
	v_pipe->fd[1] = 1;
	v_pipe->ids = 0;
	v_pipe->fds_std_in = 0;
}

static int	default_dup(t_var *v_pipe, int a, t_list *pars_il)
{
	if (a == 1)
	{
		dup2(v_pipe->a, 0);
		g_st = 1;
	}
	if (a == 2)
	{
		fr(pars_il);
		fr(v_pipe->fds_std_in);
	}
	return (0);
}

int	executing(t_list *pars_il, t_list **env)
{
	t_var	v_pipe;
	t_list	*fds;

	init_v(&v_pipe);
	fds = 0;
	if (check_redirec_list(pars_il))
	{
		v_pipe.fds_std_in = here_doc_return(&pars_il, *env);
		if (pars_il == 0 || v_pipe.fds_std_in == 0)
		{
			if (g_st == 1337)
				return (default_dup(&v_pipe, 1, pars_il));
			return (default_dup(&v_pipe, 2, pars_il));
		}
		fds = v_pipe.fds_std_in;
		v_pipe.std_in = *(int *)v_pipe.fds_std_in->content;
		v_pipe.fds_std_in = v_pipe.fds_std_in->next;
		if (pars_il == 0)
			return (0);
	}
	if (f_building(env, pars_il, &v_pipe) != 1)
		pipe_excuting(&v_pipe, env, pars_il);
	fr(fds);
	return (0);
}

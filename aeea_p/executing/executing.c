/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:40:34 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/27 12:35:37 by ael-oual         ###   ########.fr       */
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

int	chiled_processe(t_list *pars_il, t_list *env, int std_in, int std_out)
{
	char	*path;
	char	**argv;
	int		cmd;

	path = 0;
	argv = make_argv(pars_il, env, &std_in, &std_out);
	printf("argv %s   %d %d \n", argv[0], std_in, std_out);
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
			error_printf(argv[0]);//!free memory
		execve(path, argv, 0);
	}
	return (0);
}

static int	f_building(int *n_p, t_list **env, t_list *pars_il, int **ids, t_var v_pipe)
{
	int	a;

	a = 0;
	*n_p = pip_number(pars_il);
	if (*n_p == 0)
		a = chiled_build(pars_il, *env, v_pipe.std_in, v_pipe.std_out);
	if (a == 1)
	{
		dup2(v_pipe.a, 0);
		dup2(v_pipe.b, 1);
		return (1);
	}
	*ids = malloc((*n_p + 1) * sizeof(int));
	if (ids == 0)
		return (1);
	return (0);
}

t_list	*here_doc_return(t_list **pars_il, t_list *env)
{
	t_list	*fds_std_in;

	fds_std_in = 0;
	fds_std_in = chec_for_here_doc(pars_il, env);
	return (fds_std_in);
}

void	executing(t_list *pars_il, t_list **env)
{
	int		i;
	t_var	v_pipe;

	i = 0;
	v_pipe.a = dup(0);
	v_pipe.b = dup(1);
	v_pipe.std_in = 0;
	v_pipe.fd[1] = 1;
	v_pipe.ids = 0;
	v_pipe.fds_std_in = 0;
	if (check_redirec_list(pars_il))
	{
		v_pipe.fds_std_in = here_doc_return(&pars_il, *env);
		v_pipe.std_in = *(int *)v_pipe.fds_std_in->content;
		v_pipe.fds_std_in = v_pipe.fds_std_in->next;
		if (pars_il == 0)
			return ;
	}
	if (f_building(&v_pipe.n_p, env, pars_il, &v_pipe.ids, v_pipe) == 1)
		return ;
	pipe_excuting(&v_pipe, env, pars_il);
}

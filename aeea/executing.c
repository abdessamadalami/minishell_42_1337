/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:40:34 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/05 14:44:05 by ael-oual         ###   ########.fr       */
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
	if (argv == NULL)
		return 1;
	cmd = chec_for_cmds(argv, env);
	if (!cmd && std_in != -1) //for other redirction ???
	{
		if (access_func(argv))
			path = access_func(argv);
		else
			path = get_path_env(env, argv[0]);
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

void chec_for_here_doc(t_list **lst, t_list *env)
{
	t_list *list;
	t_list *temp;
	
	list = *lst;
	while (list)
	{
		if (list-> next != NULL && ft_strncmp(list-> next ->content, "<<\0", 4) == 0)
		{
			here_doc(list->next->next->content, env);
			list -> next = list->next->next->next;
			return;
		}
		if (ft_lstsize(list) == 2 && ft_strncmp(list->content, "<<\0", 4) == 0)
		{
			here_doc(list->next->content, env);
			*lst = 0;
			return;
		}
		
		list = list->next;
	}
}

void executing(t_list *pars_il, t_list *env)
{
	int		*ids;
	int 	i;
	int		n_p;
	t_var	v_pipe;
	int		a;

	a = dup(0);
	int b = dup(1);
	i = 0;
	
	chec_for_here_doc(&pars_il , env);
	if (f_building(&n_p,env, pars_il, &ids) == 1)
	{
		dup2(a,0);
		dup2(b,1);
		return ;
	}
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
	dup2(a,0);
	dup2(b,1);
}
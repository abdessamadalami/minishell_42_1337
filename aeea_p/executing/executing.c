/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:40:34 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/20 13:07:34 by sultan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../excuting_headr.h"

char **make_arrenv(t_list *env)
{
	char *str;
	char *temp;
	char **ptr;
	
	str = 0;
	while (env)
	{
		temp = str;
		str = ft_strjoin(str,env-> content);
		free(temp);
		str = ft_strjoin(str, " ");
		env = env->next;
	}
	ptr = ft_split(str,' ');
	return (ptr);
}

static int chiled_processe(t_list *pars_il ,t_list *env, int std_in, int std_out)
{
	char	*path;
	char	**argv;
	int 	cmd;
	
	path = 0;
	argv = make_argv(pars_il, env ,&std_in, &std_out);
	printf("argv %s   %d %d \n", argv[0] , std_in , std_out);
	dup2(std_in, 0);
	dup2(std_out, 1);
	cmd = chec_for_cmds(argv, env);
	if(std_in == -1 || argv == NULL || cmd == 1)
	{
		exit(1);
	}
	if (std_in != -1) //for other redirction ???
	{
		if (access_func(argv))
			path = access_func(argv);
		else
			path = get_path_env(env, argv[0]);
		if(path == NULL)
			 error_printf(argv[0]);//!free memory
		execve(path, argv, 0);
	}
	return 0;
}

static void pipe_aff(t_var *v_pipe ,int n_p ,int i)
{
	if (n_p > 0)
	{
		pipe(v_pipe->fd);
		(*v_pipe).std_out = v_pipe ->fd[1];
	}
	if (i == n_p)
		(*v_pipe).std_out = 1;
}

static int f_building(int *n_p, t_list **env, t_list *pars_il , int **ids,t_var v_pipe)
{
	int a;
	
	a = 0;
	*n_p = pip_number(pars_il);
	if (*n_p == 0)
		 a = chiled_build(pars_il, *env, v_pipe.std_in ,v_pipe.std_out);
	//    printf("in f_build_________________\n");
	// 	print_list(*env,1);  
	if (a == 1)
		return (1);
	*ids = malloc((*n_p + 1) * sizeof(int));//!good
	if (ids == NULL)
		return (1);
	return (0);
}


 t_list *here_doc_return(t_list **pars_il, t_list *env , t_var *v_pipe)
 {
	t_list *fds_std_in;

	fds_std_in = 0;
	fds_std_in = chec_for_here_doc(pars_il, env);
	return fds_std_in;
 }
 
void executing(t_list *pars_il, t_list **env)
{
	int		*ids;
	int 	i;
	int		n_p;
	t_var	v_pipe;
	t_list *fds_std_in;
	t_list *c_lst;
	int		a;
	int		b;

	fds_std_in = 0;
	a = dup(0);
	b = dup(1);
	i = 0;
	v_pipe.std_in = 0;
	v_pipe.fd[1] = 1;
	ids = 0;
	if (check_redirec_list(pars_il))
	{
		fds_std_in = here_doc_return( &pars_il, *env , &v_pipe);
		c_lst = fds_std_in;
		v_pipe.std_in = *(int *)fds_std_in->content;
		fds_std_in = fds_std_in ->next;	
		if (pars_il == NULL)
			return;
	}
	if (f_building(&n_p,env, pars_il, &ids,v_pipe) == 1)
	{
		dup2(a,0);
		dup2(b,1);
		return ;
	}
	while (i <= n_p)
	{
		if(pars_il == NULL)
			break;
		if (i == n_p)
			v_pipe.std_out = 1;
		else if (n_p > 0)
		{
			pipe(v_pipe.fd);
			(v_pipe).std_out = v_pipe.fd[1];
		}
		ids[i] = fork();
		if (ids[i] == 0)
			chiled_processe(pars_il, *env, v_pipe.std_in, v_pipe.std_out);
		close(v_pipe.fd[1]);
		if (v_pipe.to_close)
			close(v_pipe.to_close);
		v_pipe.std_in = v_pipe.fd[0];
		v_pipe.to_close = v_pipe.std_in; 
		dup_parm(&pars_il, &v_pipe.std_in ,&fds_std_in);
		i++;	
	}
	wait_exit_status(ids, n_p);
	dup2(a,0);
	dup2(b,1);
}

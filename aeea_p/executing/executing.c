/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:40:34 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/18 18:35:16 by sultan           ###   ########.fr       */
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


	//? << stop cat -e ; we don't have a problem with this case the cmd becams : cat -e && std_in is the file desctiptor of the pipe[0]
	// << stop < file cat -e ; we don't have a problem with this case the cmd becams : cat -e && std_in id becam the file
	//!  ( << stop < file cat -e > xf | << ss ls > f) >>>>>> (std_in = file --------cat -e > xf | ls > f) 
	//! ls | << ss ls this case the linked list of fds is 0 -> fi_p[0];
	//! < a << stop cat | cat -e | < ds
	//? [list of std_in]: 5 -> 4 -> 0

 t_list *here_doc_return(t_list **pars_il, t_list *env , t_var *v_pipe)
 {
	t_list *fds_std_in;

	fds_std_in = 0;
	fds_std_in = chec_for_here_doc(pars_il, env);
		if (*pars_il == NULL)
			return 0;
		if (*(int *)fds_std_in->content != -1)
		{
			v_pipe->std_in = *(int *)fds_std_in->content;
			if (fds_std_in -> next != NULL)
				fds_std_in = fds_std_in->next;
		}
		else
		{
			if (fds_std_in-> next == NULL)
				return 0;
			else
			{
				*pars_il = make_list_fork(*pars_il);
				fds_std_in = fds_std_in->next;
				v_pipe->std_in = *(int *)fds_std_in->content;
				fds_std_in = fds_std_in->next;
			}
		}
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
		if (fds_std_in == NULL )
			return;
	}
	
	print_list(pars_il ,23);
	printf("look up\n");
	if(fds_std_in != NULL && *(int *)fds_std_in -> content == -1 && fds_std_in -> next == 0)
	{
		printf("rjt\n");
		return;
	}
	//print_list(fds_std_in ,4);
	printf(" look up\n");
	
	if (f_building(&n_p,env, pars_il, &ids,v_pipe) == 1)
	{
		dup2(a,0);
		dup2(b,1);
		//ft_lstclear(&pars_il, del);
		//printf(" %p %p\n",env->next, pars_il->content);
		//	system("leaks minishell");
		return ;
	}
	while (i <= n_p)
	{
		if (n_p > 0 && i != n_p)
		{
			pipe(v_pipe.fd);
			(v_pipe).std_out = v_pipe.fd[1];
		}
		if (i == n_p)
		{
			if ( fds_std_in != 0 && *(int *)fds_std_in -> content == -1)
				break ;
			printf(" the last cmd  %d \n", v_pipe.std_in);
			print_list(pars_il,23);
			if(pars_il == NULL)
				break;
			v_pipe.std_out = 1;
			printf("jj %d \n", (v_pipe).std_out);
		}
		ids[i] = fork();
		if (ids[i] == 0)
		{
			//printf("in the ");
			chiled_processe(pars_il, *env, v_pipe.std_in, v_pipe.std_out);
		}
		if (fds_std_in != NULL && *(int *)fds_std_in -> content == -1 && fds_std_in -> next == 0)
			break;
		//close_aff(&v_pipe);
		close(v_pipe.fd[1]);
		if (v_pipe.to_close)
			close(v_pipe.to_close);
		v_pipe.std_in = v_pipe.fd[0];
		v_pipe.to_close = v_pipe.std_in;
		if ( pars_il != 0 && dup_parm(&pars_il, &v_pipe.std_in ,&fds_std_in) == 0 && i != n_p)
		{
			printf(" iam in brak \n");
			printf("home std_in %d\n", v_pipe.std_in);
			printf(" parcile %p \n", pars_il);
			i++;
		}
		i++;	
	}
	wait_exit_status(ids, n_p);
	dup2(a,0);
	dup2(b,1);
	//close(v_pipe.std_in);
	//system("leaks minishell");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:40:34 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/07 13:15:23 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "excuting_headr.h"
static int chiled_build(t_list *pars_il ,t_list *env, int std_in, int std_out)
{
	char	*path;
	char	**argv;
	int		cmd;	

	cmd = 0;
	// printf("<<<< %d >>> \n",std_in);
	// exit(0);
	argv = make_argv(pars_il, env);
	if (argv == NULL)
		return 1;
	cmd = chec_for_cmds(argv, env);
	if(cmd == 1)
		return 1;
	return 0;
}

static int chiled_processe(t_list *pars_il ,t_list *env, int std_in, int std_out)
{
	char	*path;
	char	**argv;
	int		cmd;	

	cmd = 0;
	// printf("<<<< %d >>> \n",std_in);
	// exit(0);
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
		 a = chiled_build(pars_il, env, -1, -1);
	if (a == 1)
		return (1);
	*ids = malloc((*n_p + 1) * sizeof(int));//!good
	if (ids == NULL)
		return (1);
	return (0);
}

void delete_here(t_list **lst)
{
	int index;
	t_list *list;
	t_list *prev;
	
	
	list = *lst;
	index = 0;
	
	if (list != NULL && (ft_strncmp(list ->content,"<<\0",4) == 0 || 
	ft_strncmp(list ->content,"<\0",3) == 0)) 
	{
		*lst = list->next->next;
	}
	else
	{
		while(list != NULL && (ft_strncmp(list ->content,"<<\0",3) != 0 || 
		ft_strncmp(list ->content,"<\0",3) == 0))
		{
			prev = list;
			list = list ->next;
		}
		if (list -> next != NULL)
			prev -> next = list -> next -> next;
		else
			prev = NULL;
	}
}

int check_redirec_list(t_list *lst)
{
	while (lst)
	{
		if (ft_strncmp(lst->content, "<<\0", 4) == 0)
			return 1;
		lst = lst -> next;
	}
	return 0;
}

int redirect_inpu(char *std_in)
{
	int fd_input;
	int pid;

	fd_input = open(std_in, O_RDONLY);
	// if (fd_input == -1)
	// {
	// 	//perror(std_in); // chmod error 
	// 	//exit(1);// exit just the child you must check if a pipe exists or no
	// }
   return fd_input;
}

int chec_for_infile(t_list *lst)
{
	int in_p;
	int h_p;
	int i;
	char *stdin_n;

	in_p = 0;
	h_p = 0;
	i = 0;
	while (lst)
	{
		if (ft_strncmp(lst->content, "<\0", 3) == 0)
		{
			stdin_n = lst -> next ->content;
			in_p = i;
		}
		if (ft_strncmp(lst->content, "<<\0", 4) == 0)
			 h_p = i;
		i++;
		lst = lst->next;
	}
	// printf("%d	in_p %d h_p	",in_p,h_p);
	// exit(0);
	if (in_p > h_p)
		return (redirect_inpu(stdin_n));// we have tow case here
	return (0);
}

t_list *chec_for_here_doc(t_list **lst, t_list *env)
{
	t_list *list;
	t_list *temp;
	t_list *fds;
	
	list = *lst;
	int f;
	int fd;
	int i;
	int bol_infile;
	f = 1;
	fds = 0;
	i = 0;
	while (list)
	{
		if (ft_strncmp(list->content, "|\0", 4) == 0) //!cas of pipe 
			f = 1;
		if (ft_strncmp(list->content, "<<\0", 4) == 0)
		{
			fd = here_doc(list->next->content, env);
			i++;
			if(f == 1)
				ft_lstadd_back(&fds, ft_lstnew(&fd));
			f = 0;
			//printf("fd of the first pipe is %d\n", *(int *)fds->content);
		}
		list = list->next;
	}
	bol_infile = chec_for_infile(*lst);
	if (bol_infile != -1)
		i++;
	if (bol_infile && bol_infile != -1) // !u mast delet in file if u  have her
	{
		dup2(bol_infile ,0);
		fds = 0;
	}
	while (i)
	{
		delete_here(lst);
		i--;
	}
	return fds;
}

void executing(t_list *pars_il, t_list *env)
{
	int		*ids;
	int 	i;
	int		n_p;
	t_var	v_pipe;
	t_list *fds_here_doc;
	int		a;

	a = dup(0);
	int b = dup(1);
	i = 0;
	if (check_redirec_list(pars_il))
	{
		//printf(" %d \n",check_redirec_list(pars_il));
		fds_here_doc = chec_for_here_doc(&pars_il, env);
		if (fds_here_doc != NULL)
			v_pipe.std_in = *(int *)fds_here_doc->content;
		//printf("almify %d\n",*(int *)fds_here_doc -> content);
	}
	// print_list(pars_il ,3233);
	// exit(0);
	// printf(" _%d_ \n" , getpid());
	if (f_building(&n_p,env, pars_il, &ids) == 1)
	{
		dup2(a, 0);
		dup2(b, 1);
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
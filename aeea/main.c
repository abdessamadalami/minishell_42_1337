/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:52:46 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/20 11:12:29 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "excuting_headr.h"


char	*get_path_env(t_list *env, char *cmd)
{
	int		i;
	char	*str;
	char	*ptr;
	char	**str1;

	i = 0;
	str1 = ft_split(ft_getenv(env,"PATH",0), ':');
	while (str1[i] != 0)
	{
		str = str1[i];
		str1[i] = ft_strjoin(str1[i], "/");
		free (str);
		ptr = ft_strjoin(str1[i], cmd);
		if (access(ptr, 0) != 0)
		{
			free(ptr);
			ptr = 0;
		}
		else
			break;
		i++;
	}
	free_function(str1);
	return (ptr);
}
int check_redirec(char *red)
{
    if (red[0] == '>' && red[1] == 0)
        return (1);
    else if (red[0] == '<' && red[1] == 0)
        return (1);
    else if (red[0] == '<' && red[1] == '<' && red[2] == 0)
       return (1);
	else if (red[0] == '>' && red[1] == '>' && red[3] == 0)
        return (1);
	return (0);
}

char  **make_argv(t_list *list ,t_list *env)
{
	char *str;
	char **argv;
	str = 0;
	argv = 0;
	while (list)
	{
		if(env_var(list ->content, &env ,0))
			list -> content = env_var(list ->content, &env ,3);
		if (check_redirec(list ->content))
		{
			g_redirections(list -> next ->content, list ->content);
			if(list -> next ->next != NULL && !check_redirec(list -> next -> next -> content))
				list = list -> next -> next;
		}
		str = ft_strjoin(str, list->content);
		str = ft_strjoin(str, " ");
		list = list -> next;
	}
	argv = ft_split(str, ' ');
	
	return (argv);
}

void excuting_f(t_list *pars_il,t_list *env)
{
	int index;
	char *path;
	char **argv;

	index = 0;
	//printf("_%s_\n", env_var("alami$USER>>>>>>$USER", &env ,3));
	 //not redirections
	 argv = make_argv(pars_il,env);
	 print_tab(argv);
	 path = get_path_env(env,argv[0]);
	  printf("PATH %s\n",path);
	// print_list(env,0);
	
	// while ()
	// {}
	//execve("/bin/ls",eng,0);
}

int main(int argc, char **argv, char **env)
{

	
    t_list *env_lst;
	t_list *par;
    // char *cmd = "env";
    // printf("_____________env-c____________________ \n");
     env_lst = c_env(env);
     par = c_env(ft_split("> f env ", ' '));
	////////////////////////////////////////////////////////////////
			/*
               exctutin command with execve and the other command unset
			   env export $?
			*\
	





	 
	// par = c_env(ft_split("ls > f", ' '));
	//par = c_env(ft_split("ls $USER,$USER > a > b > c > d", ' '));
	//printf("_%s_\n", env_var("$USER$USER", &env_lst ,0));
	 excuting_f(par,env_lst);
	 // print_list(par,1);
	 printf("___________________ft_getenv______________ \n");
	// if (!get_path_env(env_lst, "lsds"))
	// {
	// 	error_printf(127,"l/sds");
	// }
	// else
	// 	printf(" %s \n",get_path_env(env_lst, "lsds"));
    return (0);
}

//127 command not found or file not found, permission dined 
//1: for cat file not found or nor valid identifer
//0: for normal cas with good excuting
//258 syntax error


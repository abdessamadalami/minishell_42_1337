/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chec_for_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:42:06 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/17 15:11:35 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"
//? return one or zero for cancellation excution 
//! dont forget exit_status command
static int str_n_cmp(t_list *env, char **argv)
{
	int index;

	index = 0;
	if (argv[index + 1] == NULL)
			c_export(env, 0);
		while(argv[index + 1] != NULL)
		{
			c_export(env, argv[index + 1]);
			index++;
		}	
	return 1;
}

static int unset_cmd(char **argv, t_list *env)
{
	int index;
	
	index = 0;
	if (argv[index + 1] == NULL)
			return 1;
		while (argv[index + 1] != NULL)
		{
			c_unset(env, argv[index + 1]);
			index++;
		}
		return 1;
}

void	ft_pwd(void)
{
	char *ptr;
	printf(" iam here \n");
	ptr = getcwd(0,0);
	printf("%p\n", ptr);
	printf("%s\n", ptr);
}

int chec_for_cmds(char **argv,t_list *env)
{
	int index;

	index = 0;
	//print_list(env,0);
	if (!ft_strncmp(argv[index], "export\0",8))
		return (str_n_cmp(env, argv));
	else if (!ft_strncmp(argv[index], "cd\0",8))
		return (c_cd(env, argv));
	else if (!ft_strncmp(argv[index], "unset\0",7))
		return (unset_cmd(argv, env));
	else if (!ft_strncmp(argv[index], "env\0", 7)) // what about agr with env
	{
		print_list(env, 0);
		return 1;
	}
	//! error syntax and parcil
	else if (!ft_strncmp(argv[index], "$?\0", 4)) // exit status
	{
		printf(" command not found: %d\n", e_st);
		return 1;
	}
	else if (!ft_strncmp(argv[index], "exit\0", 4)) // exit status
	{
		c_exit(argv);
		return 1;
	}
	else if (!ft_strncmp(argv[index], "pwd\0", 5)) // exit status
	{
		ft_pwd();
		return 1;
	}
	
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chec_for_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:42:06 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/30 22:03:05 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"
//? return one or zero for cancellation excution 
//! dont forget exit_status command
static int	str_n_cmp(t_list *env, char **argv)
{
	int	index;

	index = 0;
	if (argv[index + 1] == 0)
		c_export(env, 0);
	while (argv[index + 1] != 0)
	{
		c_export(env, argv[index + 1]);
		index++;
	}
	return (1);
}

static int	unset_cmd(char **argv, t_list *env)
{
	int	index;

	index = 0;
	if (argv[index + 1] == 0)
		return (1);
	while (argv[index + 1] != 0)
	{
		c_unset(env, argv[index + 1]);
		index++;
	}
	return (1);
}

int	print_listt(t_list *list, int a)
{
	while (list != 0)
	{
		if (ft_strchr(list -> content, '=') && a == 0)
			printf("%s\n", (char *)list->content);
		list = list->next;
	}
	return (1);
}

static int	other_statment( char *content)
{
	if (!ft_strncmp(content, "$?\0", 4))
	{
		printf("command not found: %d\n", g_st);
		return (1);
	}
	else if (!ft_strncmp(content, "pwd\0", 5))
	{
		ft_pwd();
		return (1);
	}
	return (0);
}

int	chec_for_cmds(char **argv, t_list *env)
{
	int	index;

	index = 0;
	if (!ft_strncmp(argv[index], "export\0", 8))
		return (str_n_cmp(env, argv));
	else if (!ft_strncmp(argv[index], "cd\0", 8))
		return (c_cd(env, argv));
	else if (!ft_strncmp(argv[index], "unset\0", 7))
		return (unset_cmd(argv, env));
	else if (!ft_strncmp(argv[index], "env\0", 7))
		return (print_listt(env, 0));
	else if (!ft_strncmp(argv[index], "exit\0", 4))
	{
		c_exit(argv);
		return (1);
	}
	else if (!ft_strncmp(argv[index], "echo\0", 6))
	{
		ft_echo_o(argv);
		return (1);
	}
	return (other_statment(argv[index]));
}

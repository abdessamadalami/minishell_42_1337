/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:38:04 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/10 22:11:04 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_isvalid(t_cmd *cmds/*, char **path, char **cmd*/) {
	int	i;

	i = 0;
	while (cmds->cmd[i] != '\0')
	{
		if (cmds->cmd[0][0] == '-')
		{
			cmds->flags = cmds->cmd;
		}
		else if (!get_new_path(cmds->path, cmds->cmd, i))
		{	
			printf("command not found %s\n", cmds->cmd[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_cmd(char **path, char **cmd)
{
	if (!get_new_path(path, cmd,0))
	{	
		printf("command not found %s\n", cmd[0]);
		return (0);
	}
	return (1);
}

void	fill_args(t_cmd *cmds)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (cmds->cmd[i])
	{
		printf("%s\n", cmds->args[0]);
		cmds->args[j] = cmds->cmd[i];
		i++;
		j++;
	}
}

int	ft_parsing(t_cmd *cmds, char *s, char **envi)
{
	cmds->env = envi;
	cmds->path = get_path();
	cmds->cmd = ft_split(s, ' '/*, '\"', '\'', ';'*/);
	
	if (is_cmd(cmds->path, cmds->cmd))
		fill_args(cmds);
	else
	{
		printf("command not found %s\n", cmds->cmd[0]);
		return (0);
	}
	for (int i=0; cmds->cmd[i] != NULL ;i++)
	{
		// printf("path is `%s`\n", cmds->path[i]);
		printf("arg is `%s`\n", cmds->args[i]);
	}
	// if (!check_isvalid(cmds/*cmds->path, cmds->cmd*/))
	// {
	// 	exit(1);
	// }
	// printf("env is `%s`\n", cmds->env[1]);
	
	return (1);
}


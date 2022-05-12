/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:38:04 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/11 22:10:41 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
int	check_isvalid(t_cmd *cmds*//*, char **path, char **cmd*//*) {
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
*/
void	parse_cmd(t_cmd *cmds)
{
	int	i=0,j=0,m=0;
// printf("whhh\n");
	while (cmds->line[m])
	{
		// for (int i=0; cmds->argy->args[i] != NULL ;i++)
		// {
		// 	printf("argy arg is `%s`\n", cmds->argy->args[i]);
		// }
		if (!get_new_path(cmds->path, cmds->line, m))
		{
			cmds->cmd->args[i] = cmds->line[m];
			i++;
		}
		else
		{
			cmds->cmd->cmad = cmds->line[m];
			j++;
		}
		// printf("hiii\n");
		// cmds->argy->args = ft_split(cmds->line[i], ' '/*, '\"', '\'', ';'*/);
		m++;
	}
	// return (cmds->argy->args);
}
/*
void	so_parsing(t_cmd *cmds)
{
	int	i;

	i = 0;
	while (cmds->line[i] != '\0')
	{
		j = 0;
		while (cmds->line[i][j] != '\0')
		{
			if (cmds->line[i][j] == '>>')
		}
	}
}
*/

int	ft_parsing(t_cmd *cmds, char *s, char **envi)
{
	cmds->env = envi;
	cmds->path = get_path();
	cmds->line = ssplit(s);
	
	// Parsing commands
	cmds->cmd = malloc(sizeof(t_cmd) * 999);
	cmds->cmd->cmad = malloc(sizeof(char) * 999);
	cmds->cmd->args = malloc(sizeof(char) * 999);
	parse_cmd(cmds);
	// cmds->argy = malloc(sizeof(t_arg)*99);
	// for (int i=0; cmds->line[i] != NULL ;i++)
	// {
	// 	printf("line is `%s`\n", cmds->line[i]);
	// }
	
	// cmds->argy->args = get_cmd(cmds);
	
	// if (is_cmd(cmds->path, cmds->cmd))
	// 	fill_args(cmds);
	// else
	// {
	// 	printf("command not found %s\n", cmds->cmd[0]);
	// 	return (0);
	// }
	// for (int i=0; cmds->cmd[i] != NULL ;i++)
	// {
		// printf("line is `%s`\n", cmds->line[i]);
		printf("cmd is `%s`\n", cmds->cmd->cmad);
	//}
	for (int i=0; cmds->cmd->args[i] != NULL ;i++)
	{
		// printf("line is `%s`\n", cmds->line[i]);
		printf("arg of %s is `%s`\n", cmds->cmd->cmad, cmds->cmd->args[i]);
	}
	// if (!check_isvalid(cmds/*cmds->path, cmds->cmd*/))
	// {
	// 	exit(1);
	// }
	// printf("env is `%s`\n", cmds->env[1]);
	
	return (1);
}


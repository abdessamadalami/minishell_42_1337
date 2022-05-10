/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:38:04 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/10 14:01:54 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_isvalid(char **path, char **cmd) {
	int	i;

	i = 0;
	while (cmd[i] != '\0')
	{
		if (!get_new_path(path, cmd, i))
		{	
			printf("command not found %s\n", cmd[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_parsing(t_cmd *cmds, char *s, char **env)
{
	cmds->path = get_path(env);
	cmds->cmd = ft_split(s, ' ');
	
	if (!check_isvalid(cmds->path, cmds->cmd))
	{
		exit(1);
	}
	// for (int i=0; cmds->path[i] != NULL ;i++)
	// {
	// 	printf("path is `%s`\n", cmds->path[i]);
	// //	printf("cmd is `%s`\n", cmds->cmd[i]);
	// }
	return (1);
}
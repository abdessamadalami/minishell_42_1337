/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggparsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:38:04 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/30 21:14:35 by ael-asri         ###   ########.fr       */
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

char	*ssat(char *s)
{
	char	*t;
	int		i;
	int		j;

	i = 0;
	j = 0;
	
	///// count num of chars
	int	y=0;
	while (s[i] == '>')
		i++;
	while (s[i] != '>')
	{
		y++;
		i++;
	}
	//////////////////////
	
	t = malloc(sizeof(char) * y + 1);
	if (!t)
		return (NULL);
	i = 0;
	while (s[i] == '>')
		i++;
	while (s[i] != '>')
	{
		t[j] = s[i];
		i++;
		j++;
	}
	t[j] = '\0';
	return (t);
}

static void	parse_cmd(t_cmd *cmds)
{
	int	i=0,m=0;
// printf("whhh\n");
	while (cmds->line[m])
	{
		// for (int i=0; cmds->argy->args[i] != NULL ;i++)
		// {
		// 	printf("argy arg is `%s`\n", cmds->argy->args[i]);
		// }
		// printf("-%s-\n", cmds->line[m]);
	//	cmds->line[m] = ssat(cmds->line[m]);
		// printf("line %s\n", cmds->line[m]);
		// if (!access(cmds->line[m], 0))
		if (!get_new_path(cmds->path, cmds->line[m]))
		{
			cmds->cmd->args[i] = cmds->line[m];
			if (!cmds->cmd->args)
			{
				printf("okk\n");
				exit(1);
			}
			// else
			// {
			// 	cmds->cmd->so[i] = ft_strdup(">");
			// 	printf("so -%s-\n", cmds->cmd->so[i]);
			// }
			// if (!cmds->cmd->args)
			// {
			// 	cmds->cmd->args[i][0] = '>';
			// 	cmds->cmd->args[i][1] = '\0';
			// }
		//	cmds->cmd->args[i] = ssat(cmds->cmd->args[i]);
//			 printf("arg -%s-\n", cmds->cmd->args[i]);
			i++;
		}
		else
		{
			// printf("Yo! it's a cmd!\n");
		//	printf("hhii\n");
			cmds->cmd->cmad = cmds->line[m];
//			printf("cmd -%s-\n", cmds->cmd->cmad);
		}
		// if (get_new_path(cmds->path, cmds->line, m) == NULL)
		// {
		// 	cmds->cmd->args[i] = cmds->line[m];
		// 	cmds->cmd->args[i] = ssat(cmds->cmd->args[i]);
		// 	printf("argdddd -%s-\n", cmds->cmd->args[i]);
		// 	i++;
		// }
		// else
		// 	cmds->cmd->cmad = cmds->line[m];
		// printf("hiii\n");
		// cmds->argy->args = ft_split(cmds->line[i], ' '/*, '\"', '\'', ';'*/);
		m++;
	}
	// return (cmds->argy->args);
}

int	check_so(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	parse_so(t_cmd *cmds)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	j = 0;
	m = 0;
	while (cmds->cmd->args[i] != '\0')
	{
		if (check_so(cmds->cmd->args[i],"<") || check_so(cmds->cmd->args[i],"<<")
			|| check_so(cmds->cmd->args[i],">") || check_so(cmds->cmd->args[i],">>") || check_so(cmds->cmd->args[i],"||"))
		{
			cmds->cmd->so[j] = cmds->cmd->args[i];
			printf("so -%s-\n", cmds->cmd->so[j]);
			j++;
		}
		else
		{
			cmds->cmd->args[m] = cmds->cmd->args[i];
			m++;
		}
		i++;
	}
}

char	*ft_dirhatma(char *s, char c, int x)
{
	int	i;

	i = 0;
	s = ft_strdup("");
	// printf("malnaaaaaa %c\n", s[i]);
	// printf("malnaaaaaa");
	s[i] = c;
	
	if (x)
	{
		i++;
		s[i] = c;
	}
	i++;
	s[i] = '\0';
	return (s);
}

static void	parso(t_cmd *cmds)
{
	char	*temp;
	temp = ft_strdup("");
	int i=0,j,m=0, v=0;
	while (cmds->cmd->args[i] != NULL)
	{
		if (check_so(cmds->cmd->args[i],"<") || check_so(cmds->cmd->args[i],">")  ||
			check_so(cmds->cmd->args[i],"|"))
		{
			temp = sosplit(cmds, cmds->cmd->args[i]);
			// cmds->cmd->so[j] = cmds->cmd->args[i];
			// printf("so -%s-\n", cmds->cmd->so[j]);
			
		//	if (check_so(cmds->cmd->args[i],cmds->cmd->args[i + 1]))
			if (cmds->cmd->args[i][0] == cmds->cmd->args[i][1])
			{
	//			cmds->cmd->so[v] = ft_dirhatma(cmds->cmd->so[v], cmds->cmd->args[i][0], 1);
				printf("HAADI FIHAA MOCHKIL %s\n", cmds->cmd->args[i]);
				printf("Yo there'are two so in here\n");
				v++;
			}
			else
			{
			//	cmds->cmd->so[0] = cmds->cmd->args[i][0];
				// temp = cmds->cmd->args[i];
				// cmds->cmd->args[i] = ft_dirhatma(cmds->cmd->args[i], cmds->cmd->args[i][0], 0);
				// i++;
				// cmds->cmd->args[i]
				// cmds->cmd->so[v] = cmds->cmd->args[i][0];
				// v++;
				// cmds->cmd->so[v] = '\0';
			//	v++;
				printf("HAADI FIHAA MOCHKIL %s\n", cmds->cmd->args[i]);
				printf("Yo there's a so in here\n");
			}
			i++;
		}
		//	continue;
	//	cmds->temp = ssplit(cmds, cmds->line[i], ' ');
	//	cmds->temp = sosplit(cmds, cmds->line[i]);
		
		j=0;
		m = i;
	/*	while (cmds->temp[j])
		{
			cmds->cmd->args[i] = cmds->temp[j];
			i++;
			j++;
		}
		free(cmds->temp);*/
		i = m;
		i++;
	}
}

int	ft_ppparsing(t_cmd *cmds, char *s, char **envi)
{
	cmds->line = malloc(sizeof(char) * 9999);
	cmds->cmd = malloc(sizeof(t_cmd) * 9999);
	cmds->temp = malloc(sizeof(t_cmd) * 9999);
	cmds->cmd->cmad = malloc(sizeof(char) * 9999);
	cmds->cmd->args = malloc(sizeof(char) * 9999);
	cmds->cmd->so = malloc(sizeof(char) * 9999);
	cmds->lock = 0;
	cmds->env = envi;
	cmds->path = get_path();
//	cmds->line = sosplit(cmds, s);
	cmds->line = ssplit(cmds, s, ' ');

	int i=0,j,m=0;
	while (cmds->cmd->args[i])
	{
	//	cmds->temp = ssplit(cmds, cmds->line[i], ' ');
		cmds->temp = sosplit(cmds, cmds->line[i]);
		j=0;
		m = i;
		while (cmds->temp[j])
		{
			cmds->cmd->args[i] = cmds->temp[j];
			i++;
			j++;
		}
		free(cmds->temp);
		i = m;
		i++;
	}
	// if (!cmds->line)
	// {
	// 	printf("number of quotes is odd\n");
	// 	exit(1);
	// }
	// printf("line---%s\n", cmds->line[0]);
	
	// Parsing commands
	cmds->lock = 0;
	parse_cmd(cmds);
	
//	parse_so(cmds);
	//////////////////////////
	parso(cmds);
	//////////////////////////
	printf("everything good\n");
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
		printf("cmd is `%s`\n", cmds->cmd->cmad);
		
	//}
	for (int i=0; cmds->cmd->so[i] != NULL ;i++)
	{
		printf("so is `%s`\n", cmds->cmd->so[i]);
	}
	for (int i=0; cmds->cmd->args[i] != NULL ;i++)
	{
		// printf("line is `%s`\n", cmds->line[i]);
		printf("argyy is `%s`\n", cmds->cmd->args[i]);
	}
	// if (!check_isvalid(cmds/*cmds->path, cmds->cmd*/))
	// {
	// 	exit(1);
	// }
	// printf("env is `%s`\n", cmds->env[1]);
	
	return (1);
}


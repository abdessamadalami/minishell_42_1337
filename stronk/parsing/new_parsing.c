/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:29:38 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/15 23:46:47 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	parso(t_arg *arg)
{
	int i=0;
	while (arg != NULL)
	{
		if (check_so(arg->data, "<") || check_so(arg->data, ">")  ||
			check_so(arg->data, "|"))
		{
//			temp = sosplit(cmds, cmds->cmd->args[i]);
			if (arg->data[0] == arg->data[1])
			{
				printf("HAADI FIHAA MOCHKIL %s\n", arg->data);
				printf("Yo there'are two so in here\n");
			}
			else
			{
				printf("HAADI FIHAA MOCHKIL %s\n", arg->data);
				printf("Yo there's a so in here\n");
			}
			i++;
		}
		i++;
		arg = arg->next;
	}
}

int	ft_new_parsing(char *s)
{
	t_arg	*arg;
//	t_arg	*node;
	t_gg	*gg;
	char	**line;
//	char	*path;
	arg = malloc(sizeof(t_arg));
//	node = malloc(sizeof(t_arg));
	gg = malloc(sizeof(t_gg));
	line = malloc(sizeof(char) * ft_strlen(s));
//	arg->path = malloc(sizeof(char) * 9999);
//	cmds->cmd = malloc(sizeof(t_cmd) * 9999);
//	cmds->temp = malloc(sizeof(t_cmd) * 9999);
//	cmds->cmd->cmad = malloc(sizeof(char) * 9999);
//	cmds->cmd->args = malloc(sizeof(char) * 9999);
//	cmds->cmd->so = malloc(sizeof(char) * 9999);
//	cmds->env = envi;
	
//	node = ft_lstnew(s);

	gg->lock = 0;
	gg->count = 0;
//	cmds->path = get_path();
//	ta ft_lstnew(gg, NULL);
//	ft_lstadd_back(&cmds, cmds);




	line = ssplit(gg, s, ' ');

	// line = ft_split(s, ' ');
	for (int i=0; line[i] != NULL ;i++)
	{
		// printf("line is `%s`\n", cmds->line[i]);
		printf("line is `%s`\n", line[i]);
	}
	printf("arg_count %d\n", gg->count);
/*	
	int	i=0;
	
	while (i < gg->count)
	{
		node = ft_lstnew(line[i]);
	//	printf("line %s\n", line[i]);
		ft_lstadd_back(&arg, node);
		printf("line [%d]=`%s`\n", i, line[i]);
		printf("data `%s`\n", node->data);
	//	printf("i %d\n", i);
	//	printf("data `%s`\n", arg->next->gg);
	//	free(vv);
		i++;
	}*/
//	printf("ngolo okk\n");
//	while ()
/*	int i=0,j,m=0;
	while (cmds->cmd->args[i])
	{
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

	cmds->lock = 0;*/
//	parse_cmd(cmds);
	
//	parse_so(arg);
	//////////////////////////
	//parso(arg);
	//////////////////////////
	printf("everything good\n");
	
	
	
//	vv = arg;
	// for (int i=0; i < arg->count ;i++)
	// {
	// 	printf("daataa `%s`\n", vv->gg);
	// 	vv = arg->next; 
	// 	// printf("so is `%s`\n", cmds->cmd->so[i]);
	// }
	// for (int i=0; line[i] != NULL ;i++)
	// {
	// 	// printf("line is `%s`\n", cmds->line[i]);
	// 	printf("line is `%s`\n", line[i]);
	// }

	return (1);
}
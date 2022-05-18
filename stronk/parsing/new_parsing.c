/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:29:38 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/18 22:32:18 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_so(char *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_q(t_gg *gg, char *s)
{
	int	i;
//	int	x;

	i = 0;
//	x = 0;
	int	q = gg->qq;
//	printf("sss count %d\n", q);
	while (s[i] != '\0')
	{
	/*	if (ft_strlen(s) == 1 && (s[i] == '>') && (s[i + 1] == '\0'))
		{
			
			return (0);
		//	gg->count--;
		//	i++;
		}
		if (s[i] == '"' || s[i] == '\'')
		{
			q--;
	//		printf("+700 \n");
		//	i++;
		}*/
		if ((s[i] == '"' || s[i] == '\'') /*&& (q % 2 == 0) && (s[i + 1] != '\0')*/)
		{
			printf("this count %d, i is %d\n", q, i);
			return (0);
		}
		i++;
	}
//	if (x == 2)
//	printf("+100 \n");
		return (1);
//	return (0);
}

void	parso(t_arg *arg, t_gg *gg)
{
	char	**temp;
	t_arg	*dv;
	t_arg	*node;
	int i;
	int	x;
	int	r;

	i = 0;
	x = 0;
	dv = malloc(sizeof(t_arg));
	node = malloc(sizeof(t_arg));
	if (!node || !dv)
		exit(1);
//		return (NULL);
	dv = arg;
	temp = malloc(sizeof(char) * 9999);
	while (dv != NULL)
	{
		if (check_q(gg, dv->data))
		{
			
			if ((check_so(dv->data, '<') || check_so(dv->data, '>')  || check_so(dv->data, '|')) &&
				!(ft_strlen(dv->data) == 1 && (dv->data[i] == '>') && (dv->data[i + 1] == '\0'))/* && check_q(gg, dv->data)*/)
			{
				printf("YO ONE IN HERE %s\n", dv->data);
				temp = sosplit(dv->data);
				if (x == ft_lstsize(arg) - 1)
				{
					printf("AKHITR W7DA\n");
					lst_lastone(&arg, temp, x);
				}
				else
				{
					printf("MACHI AKHITR W7DA\n");
					lst_between(&arg, temp, x);
					
					r = ft_strllen(temp);
					
				/*	if (x != 0)
					{
						while (r>0)
						{
							arg = arg->next;
							r--;
						}
						dv = dv->next;
					}
					else
					{
					//	arg = arg->next;
						dv = dv->next;
					}
				*/
					
				//	arg = arg->next;
					dv = dv->next;
		//			arg->next = dv;
				//	break;
				//	dv = arg;
					x++;
				}
				printf("hppp\n");
			/*	while (temp[i] != '\0')
				{
					// printf("line is `%s`\n", cmds->line[i]);
					
					node = ft_lstnew(temp[i]);
					ft_lstadd_back(&arg, node);
					printf("temp is `%s`\n", temp[i]);
					i++;
				}*/
			/*	if (arg->data[0] == arg->data[1])
				{
					printf("HAADI FIHAA MOCHKIL %s\n", arg->data);
					printf("Yo there'are two so in here\n");
				}
				else
				{
					printf("HAADI FIHAA MOCHKIL %s\n", arg->data);
					printf("Yo there's a so in here\n");
				}*/
				
			//	i++;
			}
		/*	else
			{
				printf("YO ONE IN HERE %s\n", dv->data);
				temp = sosplit(dv->data);
				if (x == ft_lstsize(arg) - 1)
				{
					printf("AKHITR W7DA\n");
					lst_lastone(&arg, temp, x);
				}
				else
				{
					printf("MACHI AKHITR W7DA\n");
					lst_between(&arg, temp, x);
				}
				printf("hppp\n");
			}*/
		}
		printf("hdata %s\n", dv->data);
		x++;
		dv = dv->next;
	}
}

t_arg	*ft_new_parsing(char *s)
{
	t_arg	*arg;
	t_arg	*node;
	t_gg	*gg;
	char	**line;
//	char	*path;
	arg = malloc(sizeof(t_arg));
	node = malloc(sizeof(t_arg));
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
	gg->qq = 0;
//	cmds->path = get_path();
//	ta ft_lstnew(gg, NULL);
//	ft_lstadd_back(&cmds, cmds);




	line = ssplit(gg, s, ' ');

	// line = ft_split(s, ' ');
	// for (int i=0; line[i] != NULL ;i++)
	// {
	// 	// printf("line is `%s`\n", cmds->line[i]);
	// 	printf("line is `%s`\n", line[i]);
	// }
	printf("arg_count %d\n", gg->count);

	int	i=0;

	arg = ft_lstnew(line[i]);
	i++;
	while (i < gg->count)
	{
		node = ft_lstnew(line[i]);
	//	printf("line %s\n", line[i]);
		ft_lstadd_back(&arg, node);
//		printf("line [%d]=`%s`\n", i, line[i]);
//		printf("data `%s`\n", node->data);
	//	printf("i %d\n", i);
	//	printf("data `%s`\n", arg->next->gg);
	//	free(vv);
		i++;
	}
	printf("hiiii  %d\n", i);
	printf("lstsize %d\n", ft_lstsize(arg));
	i=0;
/*	while (arg != NULL)
	{
		printf("data [%d] `%s`\n", i, arg->data);
		arg = arg->next;
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
	parso(arg, gg);
	//////////////////////////
	i=0;
	
	while (arg != NULL)
	{
		printf("--[%s\n", arg->data);
		arg = arg->next;
	}
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

	return (arg);
//	return (1);
}
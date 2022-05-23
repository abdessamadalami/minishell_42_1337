/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:29:38 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/23 18:37:45 by ael-asri         ###   ########.fr       */
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

int	check_q(char *s)
{
	int	i;
//	int	x;

	i = 0;
//	x = 0;

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
	//		printf("this count %d, i is %d\n", q, i);
			return (0);
		}
		i++;
	}
//	if (x == 2)
//	printf("+100 \n");
		return (1);
//	return (0);
}

char	get_token(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '>' || s[i] == '<' || s[i] == '|')
			return (s[i]);
		i++;
	}
	return (0);
}

char	get_qtoken(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"' || s[i] == '\'')
			return (s[i]);
		i++;
	}
	return (0);
}
/*
t_arg	*ft_vv(t_arg *vv)
{
	int	x=0;
	char **temp;
	t_arg *new;
	temp = malloc(sizeof(char) * 9999);
	char	c;
	while (vv != NULL)
	{
		if (!check_q(vv->data))
		{
			c = get_qtoken(vv->data);
			temp = ft_split(vv->data, c);
			new = machi_akhirw7da(&vv, temp, x);
		}
		x++;
		vv = vv->next;
	}
	return (new);
}
*/
int	check_qso(char *s)
{
	int	i;

	i = 0;
	printf("s %s\n", s);
	if (s[i] )
	while (s[i] != '\0')
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			i++;
			while (s[i] != '"' && s[i] != '\'')
				i++;
		}
		i++;
		printf("s[%d]: %c\n", i, s[i]);
		if (s[i] == '\0' || s[i] == '>' || s[i] == '<' || s[i] == '|')
			return (0);
		i++;
	}
	// if (s[i] == '"' || s[i] == '\'')
	// 	return (0);
	return (1);
}

t_arg	*parso(t_arg *arg, t_gg *gg)
{
	char	**temp;
	t_arg	*dv;
	t_arg	*node;
	t_arg	*sfa;
	int i;
	int	x;
	int	r;
	int	sz;
	int	v;
	int	lc = 0;
	char	c;

	i = 0;
	x = 0;
	v = 0;
	sz = ft_lstsize(arg);
	dv = malloc(sizeof(t_arg));
	sfa = malloc(sizeof(t_arg));
	node = malloc(sizeof(t_arg));
	if (!node || !dv)
		exit(1);
//		return (NULL);
	dv = arg;
	temp = malloc(sizeof(char) * 9999);
	while (dv != NULL)
	{
		
		if (check_q(dv->data))
		{
			printf("ha\n");
			lc = 0;
			if ((check_so(dv->data, '<') || check_so(dv->data, '>')  || check_so(dv->data, '|')) &&
				!(ft_strlen(dv->data) == 1 && (dv->data[i] == '>' || dv->data[i] == '<' || dv->data[i] == '|') && (dv->data[i + 1] == '\0'))/* && check_q(gg, dv->data)*/)
			{
				
				if (!(ft_strlen(dv->data) == 2 && (dv->data[i+1] == '>' || dv->data[i+1] == '<' || dv->data[i+1] == '|') && (dv->data[i + 2] == '\0')))
				{
					
				printf("YO ONE IN HERE %s\n", dv->data);
				c = get_token(dv->data);
				temp = sosplit(dv->data, c);
				if (/*x == ft_lstsize(arg) - 1*/dv->next == NULL)
				{
					printf("AKHITR W7DA\n");
					arg = akhirw7da(&arg, temp, x);
			//		arg = lst_lastone(&arg, temp, x);
					x=0;
					dv = arg;
					printf("ja\n");
				/*	while (dv != NULL)
					{
						printf("lst data bisalaam dv %s\n", dv->data);
						dv = dv->next;
					}*/
				//	dv = dv->next;
					
				//	break;
				}
				else
				{
					printf("MACHI AKHITR W7DA\n");
					arg = machi_akhirw7da(&arg, temp, x);
				//	lst_between(&arg, temp, x);
					
					r = ft_strllen(temp);
					v ++;
				//	t_arg *vv = arg;
					
					dv = arg;
				/*	if (x != 0)
					{
						while (r>0)
						{
							dv = dv->next;
							r--;
						}
						dv = dv->next;
						printf("machi hdata dv %s\n", dv->data);
					}*/
				/*	else
					{
					//	arg = arg->next;
						dv = dv->next;
					}
				*/
				/*	while (arg != NULL)
					{
						printf("lst data bisalaam arg %s\n", arg->data);
						arg = arg->next;
					}*/
				//	dv = dv->next;
					

				//	arg->next = dv;
			/*		while (dv != NULL)
					{
						printf("lst data bisalaam dv %s\n", dv->data);
						dv = dv->next;
					}*/
				//	dv = arg;
//					dv = dv->next;



		//			arg->next = dv;
				//	break;
				//	dv = arg;
				//	printf("r-1 %d\n", x+r);
					x =0;
				}
		//		printf("hppp\n");
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
		else if (/*!check_q(dv->data) &&*/ !check_qso(dv->data))
		{
			printf("ho\n");
		//	dv = dv->next;
			lc = 1;
			printf("dakchi li bghina %s\n", dv->data);
			c = get_token(dv->data);
			temp = squsplit(gg, dv->data, c);
			r = ft_strllen(temp);
		//	for (int j=0;j<ft_strllen(temp);j++)
		//		printf("s temp %s\n", temp[j]);
			if (/*x == ft_lstsize(arg) - 1*/dv->next == NULL)
			{
					printf("AKHITR W7DA\n");
					arg = akhirw7da(&arg, temp, x);
			//		arg = lst_lastone(&arg, temp, x);
					x=0;
					dv = dv->next;
					dv = arg;
					while (r>0)
					{
						dv = dv->next;
						r--;
					}
				//	break;
			}
			else
			{
				printf("MACHI AKHITR W7DA\n");
				arg = machi_akhirw7da(&arg, temp, x);
			/*	while (arg != NULL)
				{
					printf("lst data bisalaam arg %s\n", arg->data);
					arg = arg->next;
				}*/
			//	exit(1);
				r = ft_strllen(temp);
			//	arg = arg->next;
				dv = arg;
				sfa = arg;
				x =0;
				//	dv = dv->next;
				while (r>0)
				{
			//		printf("lst data bisalaam arg %s\n", dv->data);
					dv = dv->next;
					
					r--;
				}
			//	continue;
			//	printf("lst data bisalaam arg %s\n", dv->data);
			//	dv = dv->next;
			}
		}

		
		////////////// lkhdma hna //////////////////
	/*	if (!check_q(dv->data))
		{
			printf("hi\n");
			c = get_qtoken(dv->data);
			temp = ft_split(dv->data, c);
			arg = machi_akhirw7da(&arg, temp, x);
			arg = arg->next;
			dv = arg;
		}*/
		///////////////////////////////////////////
		printf("hdata dv %s\n", dv->data);
		x++;
	//	v++;
		if (!dv)
			break;
		dv = dv->next;
	}
//	arg = dv;
	printf("size dv %d\n", ft_lstsize(arg));
	return (arg);
}

t_arg	*parsqu(t_arg *arg)
{
	char	**temp;
	t_arg	*dv;
	t_arg	*node;
	int i;
	int	x;
	int	r;
	int	sz;
	int	v;
	char	c;

	i = 0;
	x = 0;
	v = 0;
	sz = ft_lstsize(arg);
	dv = malloc(sizeof(t_arg));
	node = malloc(sizeof(t_arg));
	if (!node || !dv)
		exit(1);
//		return (NULL);
	dv = arg;
	temp = malloc(sizeof(char) * 9999);
	while (dv != NULL)
	{
		if (!check_q(dv->data) && dv->q == 0)
		{
			
			if ((check_so(dv->data, '"') || check_so(dv->data, '\''))/* && check_q(gg, dv->data)*/)
			{
			// 	if (!(ft_strlen(dv->data) == 2 && (dv->data[i+1] == '>' || dv->data[i+1] == '<' || dv->data[i+1] == '|') && (dv->data[i + 2] == '\0')))
			// 	{
					
				printf("YO ONE IN HERE %s\n", dv->data);
				c = get_qtoken(dv->data);
				temp = ft_split(dv->data, c);
				printf("temp %s\n", temp[1]);
				if (/*x == ft_lstsize(arg) - 1*/dv->next == NULL)
				{
					printf("AKHITR W7DA\n");
					arg = akhirw7da(&arg, temp, x);
			//		arg = lst_lastone(&arg, temp, x);
				//	x=0;
					dv = arg;
				/*	while (dv != NULL)
					{
						printf("lst data bisalaam dv %s\n", dv->data);
						dv = dv->next;
					}*/
				//	dv = dv->next;
				}
				else
				{
					printf("MACHI AKHITR W7DA\n");
					arg = machi_akhirw7da(&arg, temp, x);
				//	lst_between(&arg, temp, x);
					dv = arg;
					r = ft_strllen(temp);
					v ++;
				//	x =0;
				}
			//	}
			}
		 }
		printf("hdata dv %s\n", dv->data);
		x++;
	//	v++;
		if (!dv)
			break;
		dv = dv->next;
	}
//	arg = dv;
	printf("size dv %d\n", ft_lstsize(arg));
	return (arg);
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
//	printf("arg_count %d\n", gg->count);

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
///	printf("hiiii  %d\n", i);
//	printf("lstsize %d\n", ft_lstsize(arg));
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
	t_arg *mr;
	mr = parso(arg, gg);
	//////////////////////////
//	mr = parsqu(mr);
//	mr = parso(mr);
	//////////////////////////
	i=0;
	
	while (mr != NULL)
	{
		printf("--[%s\n", mr->data);
		mr = mr->next;
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
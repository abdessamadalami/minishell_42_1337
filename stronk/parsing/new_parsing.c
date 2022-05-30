/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:29:38 by ael-asri          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/25 10:23:47 by ael-oual         ###   ########.fr       */
=======
/*   Updated: 2022/05/26 14:52:17 by ael-asri         ###   ########.fr       */
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
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

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == '"' || s[i] == '\''))
		{
			return (0);
		}
		i++;
	}
		return (1);
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
<<<<<<< HEAD
/*
t_list	*ft_vv(t_list *vv)
{
	int	x=0;
	char **temp;
	t_list *new;
	temp = malloc(sizeof(char) * 9999);
	char	c;
	while (vv != NULL)
	{
		if (!check_q(vv->content))
		{
			c = get_qtoken(vv->content);
			temp = ft_split(vv->content, c);
			new = machi_akhirw7da(&vv, temp, x);
		}
		x++;
		vv = vv->next;
	}
	return (new);
}
*/
=======

>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
int	check_qso(char *s)
{
	int	i;

	i = 0;
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
		if (s[i] == '\0' || s[i] == '>' || s[i] == '<' || s[i] == '|')
			return (0);
		i++;
	}
	return (1);
}

<<<<<<< HEAD
t_list	*parso(t_list *arg, t_gg *gg)
{
	char	**temp;
	t_list	*dv;
	t_list	*node;
	t_list	*sfa;
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
	dv = malloc(sizeof(t_list));
	sfa = malloc(sizeof(t_list));
	node = malloc(sizeof(t_list));
	if (!node || !dv)
		exit(1);
//		return (NULL);
	dv = arg;
	temp = malloc(sizeof(char) * 9999);
	while (dv != NULL)
	{
		
		if (check_q(dv->content))
		{
		//	printf("ha\n");
			lc = 0;
			if ((check_so(dv->content, '<') || check_so(dv->content, '>')  || check_so(dv->content, '|')) &&
				!(ft_strlen(dv->content) == 1 && (dv->content[i] == '>' || dv->content[i] == '<' || dv->content[i] == '|') && (dv->content[i + 1] == '\0'))/* && check_q(gg, dv->content)*/)
			{
				
				if (!(ft_strlen(dv->content) == 2 && (dv->content[i+1] == '>' || dv->content[i+1] == '<' || dv->content[i+1] == '|') && (dv->content[i + 2] == '\0')))
				{
					
			//	printf("YO ONE IN HERE %s\n", dv->content);
				c = get_token(dv->content);
				temp = sosplit(dv->content);
				if (/*x == ft_lstsize(arg) - 1*/dv->next == NULL)
				{
				//	printf("AKHITR W7DA\n");
					arg = akhirw7da(&arg, temp, x);
			//		arg = lst_lastone(&arg, temp, x);
					x=0;
					dv = arg;
					//printf("ja\n");
				/*	while (dv != NULL)
					{
						printf("lst data bisalaam dv %s\n", dv->content);
						dv = dv->next;
					}*/
				//	dv = dv->next;
					
				//	break;
				}
				else
				{
					//printf("MACHI AKHITR W7DA\n");
					arg = machi_akhirw7da(&arg, temp, x);
				//	lst_between(&arg, temp, x);
					
					r = ft_strllen(temp);
					v ++;
				//	t_list *vv = arg;
					
					dv = arg;
				/*	if (x != 0)
					{
						while (r>0)
						{
							dv = dv->next;
							r--;
						}
						dv = dv->next;
						printf("machi hdata dv %s\n", dv->content);
					}*/
				/*	else
					{
					//	arg = arg->next;
						dv = dv->next;
					}
				*/
				/*	while (arg != NULL)
					{
						printf("lst data bisalaam arg %s\n", arg->content);
						arg = arg->next;
					}*/
				//	dv = dv->next;
					

				//	arg->next = dv;
			/*		while (dv != NULL)
					{
						printf("lst data bisalaam dv %s\n", dv->content);
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
			/*	if (arg->content[0] == arg->content[1])
				{
					printf("HAADI FIHAA MOCHKIL %s\n", arg->content);
					printf("Yo there'are two so in here\n");
				}
				else
				{
					printf("HAADI FIHAA MOCHKIL %s\n", arg->content);
					printf("Yo there's a so in here\n");
				}*/
				
			//	i++;
				}
			}
			
		/*	else
			{
				printf("YO ONE IN HERE %s\n", dv->content);
				temp = sosplit(dv->content);
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
		else if (/*!check_q(dv->content) &&*/ !check_qso(dv->content))
		{
		//	printf("ho\n");
		//	dv = dv->next;
			lc = 1;
			//printf("dakchi li bghina %s\n", dv->content);
			c = get_token(dv->content);
			temp = squsplit(gg, dv->content, c);
			r = ft_strllen(temp);
		//	for (int j=0;j<ft_strllen(temp);j++)
		//		printf("s temp %s\n", temp[j]);
			if (/*x == ft_lstsize(arg) - 1*/dv->next == NULL)
			{
					//printf("AKHITR W7DA\n");
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
			//	printf("MACHI AKHITR W7DA\n");
				arg = machi_akhirw7da(&arg, temp, x);
			/*	while (arg != NULL)
				{
					printf("lst data bisalaam arg %s\n", arg->content);
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
			//		printf("lst data bisalaam arg %s\n", dv->content);
					dv = dv->next;
					
					r--;
				}
			//	continue;
			//	printf("lst data bisalaam arg %s\n", dv->content);
			//	dv = dv->next;
			}
		}

		
		////////////// lkhdma hna //////////////////
	/*	if (!check_q(dv->content))
		{
			printf("hi\n");
			c = get_qtoken(dv->content);
			temp = ft_split(dv->content, c);
			arg = machi_akhirw7da(&arg, temp, x);
			arg = arg->next;
			dv = arg;
		}*/
		///////////////////////////////////////////
	//	printf("hdata dv %s\n", dv->content);
		x++;
	//	v++;
		if (!dv)
			break;
		dv = dv->next;
	}
//	arg = dv;
//	printf("size dv %d\n", ft_lstsize(arg));
	return (arg);
}

t_list	*parsqu(t_list *arg)
{
	char	**temp;
	t_list	*dv;
	t_list	*node;
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
	dv = malloc(sizeof(t_list));
	node = malloc(sizeof(t_list));
	if (!node || !dv)
		exit(1);
//		return (NULL);
	dv = arg;
	temp = malloc(sizeof(char) * 9999);
	while (dv != NULL)
	{
		if (!check_q(dv->content) && dv->q == 0)
		{
			
			if ((check_so(dv->content, '"') || check_so(dv->content, '\''))/* && check_q(gg, dv->content)*/)
			{
			// 	if (!(ft_strlen(dv->content) == 2 && (dv->content[i+1] == '>' || dv->content[i+1] == '<' || dv->content[i+1] == '|') && (dv->content[i + 2] == '\0')))
			// 	{
					
		//		printf("YO ONE IN HERE %s\n", dv->content);
				c = get_qtoken(dv->content);
				temp = ft_split(dv->content, c);
			//	printf("temp %s\n", temp[1]);
				if (/*x == ft_lstsize(arg) - 1*/dv->next == NULL)
				{
				//	printf("AKHITR W7DA\n");
					arg = akhirw7da(&arg, temp, x);
			//		arg = lst_lastone(&arg, temp, x);
				//	x=0;
					dv = arg;
				/*	while (dv != NULL)
					{
						printf("lst data bisalaam dv %s\n", dv->content);
						dv = dv->next;
					}*/
				//	dv = dv->next;
				}
				else
				{
				//	printf("MACHI AKHITR W7DA\n");
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
		//printf("hdata dv %s\n", dv->content);
		x++;
	//	v++;
		if (!dv)
			break;
		dv = dv->next;
	}
//	arg = dv;
	//printf("size dv %d\n", ft_lstsize(arg));
	return (arg);
}



t_list	*parsin_dyalbss7(t_list *arg, t_gg *gg)
{
	char	**temp;
//	t_list	*dv;
	t_list	*node;
	t_list	*sfa=NULL;
=======
t_arg	*parsin_dyalbss7(t_arg *arg, t_gg *gg)
{
	char	**temp;
	char	*sl;
	t_arg	*node;
	t_arg	*sfa=NULL;
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
	int		i;
	char	c;

	i = 0;
<<<<<<< HEAD
//	x = 0;
//	v = 0;
//	sz = ft_lstsize(arg);
//	dv = malloc(sizeof(t_list));
//	sfa = malloc(sizeof(t_list));
//	t = count_malloc();
	node = malloc(sizeof(t_list));
=======
	node = malloc(sizeof(t_arg));
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
	temp = malloc(sizeof(char) * 9999);
	if (!node || !temp)
		exit(1);
	while (arg != NULL)
	{
		
		if (check_q(arg->content))
		{
<<<<<<< HEAD
			if ((check_so(arg->content, '<') || check_so(arg->content, '>')  || check_so(arg->content, '|')) &&
				!(ft_strlen(arg->content) == 1 && (arg->content[i] == '>' || arg->content[i] == '<' || arg->content[i] == '|') && (arg->content[i + 1] == '\0')))
			{
				
				if (ft_strlen(arg->content) == 2 && arg->content[i+1] != arg->content[i])
				{
					char *sl;
					
					sl = ft_strdup(ft_sstrcat(arg->content[i]));
					node = ft_lstnew(sl);
					ft_lstadd_back(&sfa, node);
					sl = ft_strdup(ft_sstrcat(arg->content[i + 1]));
					node = ft_lstnew(sl);
					ft_lstadd_back(&sfa, node);
				}
				else if (!(ft_strlen(arg->content) == 2 && (arg->content[i+1] == arg->content[i] || arg->content[i+1] == arg->content[i] || arg->content[i+1] == arg->content[i]) && (arg->content[i + 2] == '\0')))
				{
					
				//	printf("YO ONE IN HERE %s\n", arg->content);
					c = get_token(arg->content);
					temp = sosplit(arg->content);
				// 	for (int j=0;j<ft_strllen(temp);j++)
				// //		printf("s temp %s\n", temp[j]);
=======
			if ((check_so(arg->data, '<') || check_so(arg->data, '>')  || check_so(arg->data, '|')) &&
				!(ft_strln(arg->data) == 1 && (arg->data[i] == '>' || arg->data[i] == '<' || arg->data[i] == '|') && (arg->data[i + 1] == '\0')))
			{
				
				if (ft_strln(arg->data) == 2 && arg->data[i+1] != arg->data[i])
				{
					sl = ft_strdp(ft_sstrcat(arg->data[i]));
					node = ftlstnew(sl);
					ftlstadd_back(&sfa, node);
					sl = ft_strdp(ft_sstrcat(arg->data[i + 1]));
					node = ftlstnew(sl);
					ftlstadd_back(&sfa, node);
				}
				else if (!(ft_strln(arg->data) == 2 && (arg->data[i+1] == arg->data[i] || arg->data[i+1] == arg->data[i] || arg->data[i+1] == arg->data[i]) && (arg->data[i + 2] == '\0')))
				{
					c = get_token(arg->data);
					temp = sosplit(arg->data);
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
					addbacki_sf(&sfa, temp);
				}
			}
			else
			{
<<<<<<< HEAD
				node = ft_lstnew(arg->content);
				ft_lstadd_back(&sfa, node);
=======
				node = ftlstnew(arg->data);
				ftlstadd_back(&sfa, node);
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
			}
		}
		else if (!check_qso(arg->content))
		{
<<<<<<< HEAD
	//		printf("dakchi li bghina %s\n", arg->content);
			c = get_token(arg->content);
			temp = squsplit(gg, arg->content, c);
	//		r = ft_strllen(temp);
=======
			c = get_token(arg->data);
			temp = squsplit(gg, arg->data);
		//	for (int i=0;temp[i];i++)
		//		printf("hi %s\n", temp[i]);
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
			addbacki_sf(&sfa, temp);
		}
<<<<<<< HEAD
		
	//	printf("hdata dv %s\n", arg->content);
	//	x++;
	//	if (!arg)
	//		break;
=======
		printf("h data %s\n", arg->data);
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
		arg = arg->next;
	}
	return (sfa);
}

t_list	*ft_new_parsing(char *s)
{
	t_list	*arg;
	t_list	*node;
	t_gg	*gg;
	char	**line;
<<<<<<< HEAD
//	char	*path;
	arg = malloc(sizeof(t_list));
	node = malloc(sizeof(t_list));
=======
	int		i;

	arg = malloc(sizeof(t_arg));
	node = malloc(sizeof(t_arg));
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
	gg = malloc(sizeof(t_gg));
	line = malloc(sizeof(char) * ft_strln(s));
	gg->lock = 0;
	gg->count = 0;
	gg->qq = 0;
	i = 0;



	line = ssplit(gg, s, ' ');
	arg = ftlstnew(line[i]);
	i++;
	while (i < gg->count)
	{
<<<<<<< HEAD
		node = ft_lstnew(line[i]);
	//	printf("line %s\n", line[i]);
		ft_lstadd_back(&arg, node);
//		printf("line [%d]=`%s`\n", i, line[i]);
//		printf("data `%s`\n", node->content);
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
		printf("data [%d] `%s`\n", i, arg->content);
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
	t_list *mr;
//	mr = parso(arg, gg);
=======
		node = ftlstnew(line[i]);
		ftlstadd_back(&arg, node);
		i++;
	}
	//////////////////////////
	t_arg *mr;
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
	mr = parsin_dyalbss7(arg, gg);
	//////////////////////////
	while (mr != NULL)
	{
		//printf("--[%s\n", mr->content);
		mr = mr->next;
	}
<<<<<<< HEAD
//	printf("everything good\n");
	
	
	
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

=======
	printf("everything good\n");
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
	return (arg);
}
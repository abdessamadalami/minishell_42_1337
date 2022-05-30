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
/*   Updated: 2022/05/30 15:52:20 by ael-asri         ###   ########.fr       */
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
	node = malloc(sizeof(t_list));
	if (!node || !dv)
		exit(1);
//		return (NULL);
	dv = arg;
	temp = malloc(sizeof(char) * 9999);
	while (dv != NULL)
	{//printf("hi\n");
		if (check_q(dv->content))
		{
			lc = 0;
			if ((check_so(dv->content, '<') || check_so(dv->content, '>')  || check_so(dv->content, '|')) &&
				!(ft_strlen(dv->content) == 1 && (dv->content[i] == '>' || dv->content[i] == '<' || dv->content[i] == '|') && (dv->content[i + 1] == '\0'))/* && check_q(gg, dv->content)*/)
			{
				
				if (!(ft_strlen(dv->content) == 2 && (dv->content[i+1] == '>' || dv->content[i+1] == '<' || dv->content[i+1] == '|') && (dv->content[i + 2] == '\0')))
				{
					
//				printf("YO ONE IN HERE %s\n", dv->content);
				c = get_token(dv->content);
				temp = sosplit(dv->content, c);
				if (/*x == ft_lstsize(arg) - 1*/dv->next == NULL)
				{
//					printf("AKHITR W7DA\n");
					arg = akhirw7da(&arg, temp, x);
			//		arg = lst_lastone(&arg, temp, x);
					x=0;
					dv = arg;
//					printf("ja\n");
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
//					printf("MACHI AKHITR W7DA\n");
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
=======
t_arg	*parsin_dyalbss7(t_arg *arg, t_gg *gg)
{
	char	**temp;
	char	*sl;
	t_arg	*node;
	t_arg	*sfa=NULL;
	int		i;
//	char	c;

	i = 0;
	node = malloc(sizeof(t_arg));
	temp = malloc(sizeof(char) * 9999);
	if (!node || !temp)
		exit(1);
	while (arg != NULL)
	{
		
		if (check_q(arg->data))
		{
			if ((check_so(arg->data, '<') || check_so(arg->data, '>')  || check_so(arg->data, '|')) &&
				!(ft_strln(arg->data) == 1 && (arg->data[i] == '>' || arg->data[i] == '<' || arg->data[i] == '|') && (arg->data[i + 1] == '\0')))
			{
				
				if (ft_strln(arg->data) == 2 && arg->data[i+1] != arg->data[i])
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
				{
					sl = ft_strdp(ft_sstrcat(arg->data[i]));
					node = ftlstnew(sl);
					ftlstadd_back(&sfa, node);
					sl = ft_strdp(ft_sstrcat(arg->data[i + 1]));
					node = ftlstnew(sl);
					ftlstadd_back(&sfa, node);
				//	free(sl);
				}
				else if (!(ft_strln(arg->data) == 2 && (arg->data[i+1] == arg->data[i] || arg->data[i+1] == arg->data[i] || arg->data[i+1] == arg->data[i]) && (arg->data[i + 2] == '\0')))
				{
				//	c = get_token(arg->data);
					temp = sosplit(arg->data);
					addbacki_sf(&sfa, temp);
				}
<<<<<<< HEAD
				printf("hppp\n");
			}*/
		}
		else if (/*!check_q(dv->content) &&*/ check_qso(dv->content))
		{
		//	dv = dv->next;
			lc = 1;
//			printf("dakchi li bghina %s\n", dv->content);
			c = get_token(dv->content);
			temp = squsplit(gg, dv->content, c);
			r = ft_strllen(temp);
			for (int j=0;j<ft_strllen(temp);j++)
//				printf("s temp %s\n", temp[j]);
			if (/*x == ft_lstsize(arg) - 1*/dv->next == NULL)
			{
//					printf("AKHITR W7DA\n");
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
//				printf("MACHI AKHITR W7DA\n");
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
				x =0;
				//	dv = dv->next;
				while (r>0)
				{
			//		printf("lst data bisalaam arg %s\n", dv->content);
					dv = dv->next;
					
					r--;
				}
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
=======
			}
			else
			{
				node = ftlstnew(arg->data);
				ftlstadd_back(&sfa, node);
			//	free(node->data);
			}
		}
		else if (!check_qso(arg->data))
		{
		//	printf("jwa\n");
		//	printf("q %s\n", arg->data);
		//	c = get_token(arg->data);
			temp = squsplit(gg, arg->data);
			// for (int i=0;temp[i];i++)
			// 	printf("hi %s\n", temp[i]);
			addbacki_sf(&sfa, temp);
		}
	/*	else
		{
			printf("jwa\n");
			node = ftlstnew(arg->data);
			ftlstadd_back(&sfa, node);
		}*/
		arg = arg->next;
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
	}
//	printf("sfa %s\n", sfa->data);
	free(temp);
//	free(node);
//	free(sl);
/*while (node != NULL)
	{
		free(node->data);
		node = node->next;
	}*/
	return (sfa);
}

<<<<<<< HEAD
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
		if (!check_q(dv->content))
		{
			
			if ((check_so(dv->content, '"') || check_so(dv->content, '\''))/* && check_q(gg, dv->content)*/)
			{
			// 	if (!(ft_strlen(dv->content) == 2 && (dv->content[i+1] == '>' || dv->content[i+1] == '<' || dv->content[i+1] == '|') && (dv->content[i + 2] == '\0')))
			// 	{
					
//				printf("YO ONE IN HERE %s\n", dv->content);
				c = get_qtoken(dv->content);
				temp = ft_split(dv->content, c);
//				printf("temp %s\n", temp[1]);
				if (/*x == ft_lstsize(arg) - 1*/dv->next == NULL)
				{
//					printf("AKHITR W7DA\n");
					arg = akhirw7da(&arg, temp, x);
			//		arg = lst_lastone(&arg, temp, x);
					x=0;
					dv = arg;
				/*	while (dv != NULL)
					{
						printf("lst data bisalaam dv %s\n", dv->content);
						dv = dv->next;
					}*/
				//	dv = dv->next;
				}
				else
=======
t_arg	*remove_quotes(t_arg *arg)
{
	int		i;
	int		j;
	t_arg	*sfa=NULL;
	t_arg	*node;
	char	*s;

	i =0;
	j = 0;
	while (arg != NULL)
	{
	//	printf("zft %s\n", arg->data);
		if (!check_q(arg->data))
		{
			
			s = malloc(sizeof(char) * (ft_strln(arg->data) - 1));
			while (arg->data[i])
			{
				if (arg->data[i] != '"' && arg->data[i] != '\'')
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
				{
					s[j] = arg->data[i];
					j++;
				}
				i++;
			}
<<<<<<< HEAD
		 }
//		printf("hdata dv %s\n", dv->content);
		x++;
	//	v++;
		if (!dv)
			break;
		dv = dv->next;
=======
			s[j] = '\0';
	//		printf("sss %s\n", s);
			node = ftlstnew(s);
			ftlstadd_back(&sfa, node);
		}
		else
		{
	//		printf("cc\n");
			node = ftlstnew(arg->data);
			ftlstadd_back(&sfa, node);
		}
		
		arg = arg->next;
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
	}
	return (sfa);
}

t_list	*ft_new_parsing(char *s)
{
<<<<<<< HEAD
	// if (!s)
	// 	printf("walo\n");
	t_list	*arg;
	t_list	*node;
	t_gg	*gg;
	char	**line;
//	char	*path;
	arg = malloc(sizeof(t_list));
	node = malloc(sizeof(t_list));
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
=======
	t_arg	*arg;
	t_arg	*node;
	t_gg	*gg;
	char	**line;
	int		i;
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd

//	arg = malloc(sizeof(t_arg));
//	node = malloc(sizeof(t_arg));
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
=======
		node = ftlstnew(line[i]);
		ftlstadd_back(&arg, node);
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
		i++;
	}
	free(gg);
//	free(node);
//	
	//////////////////////////
<<<<<<< HEAD
	t_list *mr;
	mr = parso(arg, gg);
	//////////////////////////
//	mr = parsqu(mr);
//	mr = parso(mr);
	//////////////////////////
	i=0;
	
/*	while (mr != NULL)
	{
		printf("--[%s\n", mr->content);
		mr = mr->next;
	}
	printf("everything good\n");*/
=======
	t_arg *mr;
	t_arg *dv;
	mr = parsin_dyalbss7(arg, gg);
//	free(line);
>>>>>>> 49a307ac50c24b8947080a6787c3b93827d46ebd
	
	//////////////////////////
	dv = remove_quotes(mr);
	
	
	// while (node != NULL)
	// {
	// 	free(node->data);
	// 	node = node->next;
	// }
//	free(gg);
//	free(line);
//	free(mr);
// free(arg);
	
//	arg = mr;
	// while (mr != NULL)
	// 		{
	// 			printf("--[%s\n", mr->data);
	// 			mr = mr->next;
	// 		}
	// 		printf("everything good\n");
//	system("leaks minishell");
	return (dv);
}
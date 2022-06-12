/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:29:38 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/12 19:12:22 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_qdollar(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'' && s[i] != '\0')
			{
				if (s[i] == '$')
					return (0);
				i++;
			}
			if (s[i] == '\0')
				break ;
		}
		i++;
	}
	return (1);
}

int	check_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '$')
			return (0);
		i++;
	}
	return (1);
}

t_arg	*check_for_dollar(t_arg *arg)
{
	t_arg	*sfa;
	t_arg	*z3ta;
	t_arg	*node;
	char	*var;
	char	**temp;
	char	*gg;
	char	*t;
	char 	*l;
	int		i;
	int		j;
	int		x;
	int		y;
	int		z;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	z = 0;
	sfa = NULL;
	z3ta = NULL;
	var = malloc(sizeof(char)*9999);
	gg = malloc(sizeof(char)*9999);
	l = malloc(sizeof(char)*9999);
	temp = (char **)malloc(sizeof(char *)*9999);
	t = malloc(sizeof(char)*9999);
	if (!var)
		exit(1);
	while (arg != NULL)
	{
		if (check_qdollar(arg->data) && !check_dollar(arg->data))
		{
			// if (!check_qd(arg->data))
			// {
				printf("hii\n");
				temp = dosplit(arg->data, first_occc(arg->data));
				for(int r=0;temp[r];r++)
					printf("r %s\n", temp[r]);
				// exit(1);
				if (!temp)
					return (NULL);
				while (temp[z] != NULL)
				{
					y = 0;
					if (!check_dollar(temp[z]))
					{
						while (temp[z][y] != '\0')
						{
							if (temp[z][y] == '$')
							{
								y++;
								while ((((temp[z][y] >= 'a' && temp[z][y] <= 'z')
									|| (temp[z][y] >= 'A' && temp[z][y] <= 'Z')
									|| (temp[z][y] >= '0' && temp[z][y] <= '9')) || temp[z][y] == '_') && temp[z][y] != '\0')
								{
									var[j] = temp[z][y];
									y++;
									j++;
								}
								var[j] = '\0';
								if (!getenv(var))
									exit(1);
								t = ft_strjn(t, getenv(var));
								printf("t %s\n",  t);
								j = 0;
							//`	y++;
								while (temp[z][y] != '\0')
								{
									gg[j] = temp[z][y];
									printf("c %c\n", t[j]);
									y++;
									j++;
								}
								gg = ft_strjn(t, gg);
								printf("gg %s\n",  gg);
								node = ftlstnew(gg);
								ftlstadd_back(&z3ta, node);
								y++;
							//	break ;
							}
							else
							{
								t[x] = temp[z][y];
								printf("t %c", t[x]);
								x++;
								y++;
							}
						//	y++;
						}
					}
					else
					{
						printf("data %s\n", temp[z]);
						node = ftlstnew(temp[z]);
						ftlstadd_back(&z3ta, node);
					}
					if (temp[z + 1] == NULL)
					{
						while (z3ta != NULL)
						{
							l = ft_strjn(l, z3ta->data);
							z3ta = z3ta->next;
						}
						node = ftlstnew(l);
						ftlstadd_back(&sfa, node);
					}
					z++;
						//i++;
						
					/*	while (arg->data[i] != '-' && arg->data[i] != '\0')
						{
							var[j] = arg->data[i];
							// printf("var[%d]: %c\n", j,var[j]);
							j++;
							i++;
						}
						var[j] = '\0';
						if (!getenv(var))
							exit(1);
						t = ft_strjn(t, getenv(var));
						printf("t %s\n",  t);
						node = ftlstnew(t);
						ftlstadd_back(&sfa, node);
					//	break;
					}
					else
					{
						t[x] = arg->data[i];
						x++;
						i++;
					}*/
				}
			// }
			// else
			// {
			// 	node = ftlstnew(arg->data);
			// 	ftlstadd_back(&sfa, node);
			// }
		}
		else
		{
			node = ftlstnew(arg->data);
			ftlstadd_back(&sfa, node);
		}
		arg = arg->next;
	}
	return (sfa);
}

t_arg	*ft_parsing(char *s)
{
	t_arg	*arg;
	t_gg	*gg;
	char	**line;
	t_arg	*mr;
	t_arg	*dv;
	t_arg	*sd;
	t_arg	*ms;

	gg = malloc(sizeof(t_gg));
	line = malloc(sizeof(char) * ft_strln(s));
	gg->lock = 0;
	gg->count = 0;
	gg->qq = 0;
	arg = parsing_spaces(s);
	check_syntax(arg);
	gg->lock = 0;
	mr = parsin_dyalbss7(arg, gg);
	sd = check_for_dollar(mr);
	ms = parsing_wildcard(sd);
	dv = remove_quotes(ms);
//	system("leaks minishell");
	


	///// echo "don't freak out buddy!">'don"t freak out buddy!'
	
	return (dv);
}

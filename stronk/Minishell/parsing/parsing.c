/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:29:38 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/05 15:02:26 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_arg	*parsin_dyalbss7(t_arg *arg, t_gg *gg)
{
	char	**temp;
	t_arg	*node;
	t_arg	*sfa=NULL;

	node = malloc(sizeof(t_arg));
	temp = malloc(sizeof(char) * 9999);
	if (!node || !temp)
		exit(1);
	while (arg != NULL)
	{
		if (check_q(arg->data))
		{
			if ((check_so(arg->data, '<') || check_so(arg->data, '>')  || check_so(arg->data, '|')))
			{
				if (ft_strln(arg->data) == 1 || (ft_strln(arg->data) == 2 && (arg->data[0] == arg->data[1]) && arg->data[0] != '|'))
				{
					node = ftlstnew(arg->data);
					ftlstadd_back(&sfa, node);
				}
				else
				{
					temp = sosplit(arg->data);
					addbacki_sf(&sfa, temp);
				}
			}
			else
			{
				node = ftlstnew(arg->data);
				ftlstadd_back(&sfa, node);
			}
		}
		else
		{
			temp = squsplit(gg, arg->data);
			addbacki_sf(&sfa, temp);
		}
		arg = arg->next;
	}
	free(temp);
	return (sfa);
}

t_arg	*remove_quotes(t_arg *arg)
{
	int		i;
	int		j;
	t_arg	*sfa=NULL;
	t_arg	*node;
	char	*s;
	char	c;
	char	l;
	int		gg;

	i =0;
	j = 0;
	while (arg != NULL)
	{
		if (!check_q(arg->data))
		{
			c = first_occc(arg->data);
			gg = count_q(arg->data, c);
			if (c == '"')
				l = '\'';
			else
				l = '"';
			s = malloc(sizeof(char) * (ft_strln(arg->data) - 1));
			while (arg->data[i])
			{
				if (arg->data[i] == c)
					gg--;
				if (arg->data[i] != c)
				{
					if (arg->data[i] == l && (gg % 2 == 0))
					{
						i++;
						continue;
					}
					s[j] = arg->data[i];
					j++;
				}
				else if (arg->data[i] == l && (gg % 2 != 0))
				{
					s[j] = arg->data[i];
					j++;
				}
				
				i++;
			}
			s[j] = '\0';
			node = ftlstnew(s);
			ftlstadd_back(&sfa, node);
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
	t_arg	*node;
	t_gg	*gg;
	char	**line;
	int		i;
	t_arg *mr;
	t_arg *dv;

	
	//	printf("rra -%s-\n", s);
//	arg = malloc(sizeof(t_arg));
//	node = malloc(sizeof(t_arg));
	gg = malloc(sizeof(t_gg));
	line = malloc(sizeof(char) * ft_strln(s));
	gg->lock = 0;
	gg->count = 0;
	gg->qq = 0;
	i = 0;

	
	line = ssplit(gg, s, ' ');
	for(int k=0;line[k];k++)
		printf("line %s\n", line[k]);
	arg = ftlstnew(line[i]);
	i++;
	
	while (i < gg->count)
	{
		node = ftlstnew(line[i]);
		ftlstadd_back(&arg, node);
		i++;
	}
//	free(gg);
//	free(node);
	check_syntax(arg);
	//////////////////////////
//	printf("lstsize dyal arg %d\n", ftlstsize(arg));
	mr = parsin_dyalbss7(arg, gg);
//	free(line);
	// while (arg != NULL)
	// {
	// 			printf("--[%s\n", arg->data);
	// 			arg = arg->next;
	// 		}
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
	// {
	// 	printf("--[%s\n", mr->data);
	// 	mr = mr->next;
	// }
	// printf("everything good\n");
//	system("leaks minishell");
	
	return (dv);
}
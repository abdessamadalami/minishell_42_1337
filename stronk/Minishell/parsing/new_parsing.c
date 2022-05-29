/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:29:38 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/29 20:58:45 by ael-asri         ###   ########.fr       */
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

t_arg	*parsin_dyalbss7(t_arg *arg)
{
	char	**temp;
	char	*sl;
	t_arg	*node;
	t_arg	*sfa=NULL;
	int		i;
	char	c;

	i = 0;
	node = malloc(sizeof(t_arg));
	temp = malloc(sizeof(char) * 9999);
	if (!node || !temp)
		exit(1);
	while (arg != NULL)
	{
		
	//	if (check_q(arg->data))
	//	{
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
				//	free(sl);
				}
				else if (!(ft_strln(arg->data) == 2 && (arg->data[i+1] == arg->data[i] || arg->data[i+1] == arg->data[i] || arg->data[i+1] == arg->data[i]) && (arg->data[i + 2] == '\0')))
				{
					c = get_token(arg->data);
					temp = sosplit(arg->data);
					addbacki_sf(&sfa, temp);
				}
			}
			else
			{
				node = ftlstnew(arg->data);
				ftlstadd_back(&sfa, node);
			//	free(node->data);
			}
	/*	}
		else if (!check_qso(arg->data))
		{
		//	printf("q %s\n", arg->data);
			c = get_token(arg->data);
			temp = squsplit(gg, arg->data);
			for (int i=0;temp[i];i++)
				printf("hi %s\n", temp[i]);
			addbacki_sf(&sfa, temp);
		}*/
		arg = arg->next;
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
				{
					s[j] = arg->data[i];
					j++;
				}
				i++;
			}
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
	}
	return (sfa);
}

t_arg	*ft_new_parsing(char *s)
{
	t_arg	*arg;
	t_arg	*node;
	t_gg	*gg;
	char	**line;
	int		i;

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
		node = ftlstnew(line[i]);
		ftlstadd_back(&arg, node);
		i++;
	}
//	free(node);
//	
	//////////////////////////
	t_arg *mr;
	t_arg *dv;
	mr = parsin_dyalbss7(arg);
	//////////////////////////
	dv = remove_quotes(mr);
	
	
	// while (node != NULL)
	// {
	// 	free(node->data);
	// 	node = node->next;
	// }
//	free(gg);
//	free(line);
//free(arg);
//	system("leaks minishell");
//	arg = mr;
	while (mr != NULL)
			{
				printf("--[%s\n", mr->data);
				mr = mr->next;
			}
			printf("everything good\n");
	return (dv);
}
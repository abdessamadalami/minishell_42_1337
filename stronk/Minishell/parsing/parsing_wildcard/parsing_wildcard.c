/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_wildcard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:01:16 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/11 19:45:54 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
/*
static int	so_counter(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '>' || s[i] == '<' || s[i] == '|')
		{
			if (i > 0)
				count++;
			if (s[i + 1] == '>' || s[i + 1] == '<')
				i++;
			count++;
		}
		if (s[i + 1] == '\0' && s[i] != '>' && s[i] != '<')
		{
			count++;
			break ;
		}
		i++;
	}
	return (count);
}
*/
static void	diklmzyana(t_arg **sfa, char *s)
{
	t_arg	*node;

	node = malloc(sizeof(t_arg));
	if (!node)
		exit(1);
	node = ftlstnew(s);
	ftlstadd_back(sfa, node);
}
/*
static void	diklmzyanalokhra(t_arg **sfa, char *s)
{
	char	**temp;

	printf("s %s\n", s);
	temp = malloc(sizeof(char) * 9999);
	if (!temp)
		exit(1);
	temp = wildsplit(s);
	addbacki_sf(sfa, temp);
}
*/
int	prefsuff_checker(char *s, char *prefix, char *suffix)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	j = 0;
	f = 1;
//	printf("s %s\n", s);
	while (prefix[i] != '\0' && s[i] != '\0')
	{
		if (s[i] != prefix[i])
		{
			f = 0;
			break ;
		}
		i++;
	}
	i = ft_strln(s) - ft_strln(suffix);
	// printf("ft_strln(s) %d\n", ft_strln(s));
	// printf("ft_strln(suffix) %d\n", ft_strln(suffix));
	while (suffix[j] != '\0' && s[i] != '\0')
	{
		if (s[i] != suffix[j])
		{
			f = 0;
			break ;
		}
		i++;
		j++;
	}
//	printf("f %d\n", f);
	if (f == 1)
		return (1);
	return (0);
}

void	get_files(t_arg **sfa, char *s, char *prefix, char *suffix)
{
	t_arg			*node;
	struct dirent	*de;
	DIR				*dr;
	int				w=0;

//	node = malloc(sizeof(t_arg));
//	if (!node)
//		exit(1);
	node = NULL;
	dr = opendir(".");
	if (!dr)
	{
		printf("no such file\n");
		exit(1);
	}
	while (1)
	{
		de = readdir(dr);
		if (!de)
			break ;
		if (prefsuff_checker(de->d_name, prefix, suffix))
		{
			printf("file: %s\n", de->d_name);
		//	node->data = de->d_name;
			ftlstadd_back(&node, ftlstnew(de->d_name));
		//	printf("node data %s\n", node->data);
			// node = node->next;
			w = 1;
		}
	}
	closedir(dr);
	printf("ho\n");
	if (w == 1)
	{
	//	while (node != NULL)
	//	{
			ftlstadd_back(sfa, node);
	//		node = node->next;
	//	}
	}
	else
	{
		node = ftlstnew(s);
		ftlstadd_back(sfa, node);
	}
	printf("yo\n");
}

t_arg	*parsing_wildcard(t_arg *arg)
{
	t_arg	*sfa;

	sfa = NULL;
	// while (arg != NULL)
	// {
	// 	if (check_q(arg->data))
	// 	{
	// 		if (check_so(arg->data, '*'))
	// 			diklmzyanalokhra(&sfa, arg->data);
	// 		else
	// 			diklmzyana(&sfa, arg->data);
	// 	}
	// 	else
	// 		diklmzyana(&sfa, arg->data);
	// 	arg = arg->next;
	// }
	////////////////////////////////////////////
//	t_files *files;
	
//	t_arg	*node;
	char	*prefix; // beginning
	char	*suffix; // end

//	files = malloc(sizeof(t_files));
//	if (!files)
//		exit(1);
	while (arg != NULL)
	{
		if (check_q(arg->data))
		{
			if (check_so(arg->data, '*'))
			{
				printf("hi\n");
			//	diklmzyanalokhra(&sfa, arg->data);
				prefix = ft_allocate(arg->data);
				suffix = ft_allocate(arg->data);
				int i=0, j=0;
				while (arg->data[i] != '*' && arg->data[i] != '\0')
				{
					prefix[j] = arg->data[i];
					i++;
					j++;
				}
				prefix[j] = '\0';
				if (arg->data[i] == '*')
					i++;
				else
					exit(0);
				j = 0;
				while (arg->data[i] != '\0')
				{
					suffix[j] = arg->data[i];
					i++;
					j++;
				}
				suffix[j] = '\0';
				printf("prefix %s\n", prefix);
				printf("sufffix %s\n", suffix);
				get_files(&sfa, arg->data, prefix, suffix);
			}
			else
				diklmzyana(&sfa, arg->data);
		}
		else
			diklmzyana(&sfa, arg->data);
		arg = arg->next;
	}
		printf("pp\n");

	
	///////////////////////////////////////////
	return (sfa);
}

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

int	ft_wildstrcmp(char *s1, char *suff, int x)
{
	int	j;

	j = 0;
	while (suff[j])
	{
		if (s1[x] != suff[j])
			return (0);
		x++;
		j++;
	}
	return (1);
}

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
t_files	*fill_files(void)
{
//	t_arg			*node;
	struct dirent	*de;
	DIR				*dr;
	t_files			*my_files;

//	node = NULL;
//	w = 0;
	my_files = NULL;
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
	//	if (prefsuff_checker(de->d_name, prefix, suffix))
	//	{
			printf("file: %s\n", de->d_name);
			ftlstadd_backmf(&my_files, ftlstnewmf(de->d_name));
	//		w = 1;
	//	}
	}
	closedir(dr);
	return (my_files);
}

t_arg	*get_files(t_files *my_files, char **suffix, char *prefix)
{
	t_arg	*arg;
	t_files	**mf;
	int		i;

	arg = NULL;
	mf = &my_files;
	i = 0;
	printf("preffix %s\n", prefix);
	for (int x=0;suffix[x];x++)
		printf("suffix %s\n", suffix[x]);
	if (prefix != NULL)
	{
		while (my_files != NULL)
		{
			i = 0;
			if (ft_strcmp(my_files->file_name, prefix))
				my_files->state = 1;
			else
				my_files->state = 0;
			while (suffix[i] != NULL)
			{
				if (ft_strcmp(my_files->file_name, suffix[i]))
					my_files->state = 1;
				else
					my_files->state = 0;
				i++;
			}
			my_files = my_files->next;
		}
	}
	else
	{
		int	w;
		while (my_files != NULL)
		{
			i = 0;
			w = 0;
			while (suffix[i] != NULL)
			{
				if (ft_strcmp(my_files->file_name, suffix[i]))
					w = 1;
				//	my_files->state = 1;
				else
				/	my_files->state = 0;
				i++;
			}
			my_files = my_files->next;
		}
	}
	while (*mf != NULL)
	{
		printf("hhhi %d\n", (*mf)->state);
		if ((*mf)->state)
		{
			ftlstadd_back(&arg, ftlstnew((*mf)->file_name));
		}
		*mf = (*mf)->next;
	}
	printf("size : %d\n", ftlstsize(arg));
	return (arg);
}

char	*handling_wildcards(char *s, int *i)
{
	char	*t;
	int		j;

	while (s[*i] == '*' && s[*i] != '\0')
		(*i)++;
	j = *i;
	while (s[*i] != '*' && s[*i] != '\0')
		(*i)++;
	t = ft_subtr(s, j, *i);
	return (t);
}

t_arg	*get_prefixsuffix(char *s)
{
	char	*prefix;
	char	**sufffix;
	int		i;
	int		count;

	sufffix = (char **)ft_calloc(100, sizeof(char*));
	count = 0;
	i = 0;
	while (s[i] != '*')
		i++;
	prefix = ft_subtr(s, 0, i);
	while (s[i] != '\0')
	{
		if (s[i] == '*')
		{
			sufffix[count] = handling_wildcards(s, &i);
			count++;
		}
		else
			i++;
	}
	// prefix & suffix
	t_files	*my_files;
	my_files  = fill_files();
	return (get_files(my_files, sufffix, prefix));
}

*/

char	*get_prefix(char *s)
{
	char	*prefix;
	int		i;

	i = 0;
	while (s[i] != '*' && s[i] != '\0')
		i++;
	prefix = ft_subtr(s, 0, i);
	return (prefix);
}

char	**get_suffix(char *s)
{
	char	**suffix;
	int		count;
	int		i;
	int		j;

	suffix = (char **)ft_calloc(sizeof(char *), (9));
	if (!suffix)
		exit (1);
	count = 0;
	i = 0;
	j = 0;
	while (s[i] != '*' && s[i] != '\0')
		i++;
	while (s[i])
	{
		if (s[i] == '*')
		{
			while (s[i] == '*' && s[i] != '\0')
				i++;
			j = i;
			while (s[i] != '*' && s[i] != '\0')
				i++;
			suffix[count] = ft_subtr(s, j, i);
			count++;
		}
	}
	return (suffix);
}

char	*ft_strnstr(char	*haystack, char	*needle, int len)
{
	int		i;
	int		j;

	if (*needle == '\0')
		return ((char *)haystack);
	if (*haystack == '\0' || len == 0)
		return (0);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}	
		i++;
	}
	return (0);
}

int	ft_index(char *s, char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("s %s | needle %s\n", s, needle);
	while (s[i] != '\0')
	{
		j = 0;
		if (s[i] == needle[j])
		{
			while (s[i] == needle[j] && s[i] && needle[j])
			{
				j++;
				i++;
			}
			printf("hi j %d, strln %d\n", j, ft_strln(needle));
			if (j == ft_strln(needle))
			{
				return (i-j);
			}
			else
				j = 0;
		}
		else
			i++;
	}
	// while (s[i] != c && s[i] != '\0')
	// 	i++;
	return (-1);
}

int	prefsuff_checker(char *s, char *prefix, char **suffix)
{
	int	i;
	int	j;
	int	f;
	int	x;

	i = 0;
	j = 0;
	f = 1;
	if (prefix[0] != '\0')
	{
		while (prefix[i] != '\0' && s[i] != '\0')
		{
			if (s[i] != prefix[i])
			{
				f = 0;
				break ;
			}
			i++;
		}
	}
	j = 0;
	while (suffix[j] != NULL)
	{
		x = ft_index(s, suffix[j]);
		if (x != -1)
		{
			if (suffix[j + 1] == NULL)
			{
				if (s[ft_strln(s) - 1] != suffix[j][ft_strln(suffix[j]) - 1])
				{
					f = 0;
					break ;
				}
			}
			if (!ft_wildstrcmp(s, suffix[j], x))
			{
				f = 0;
				break ;
			}
		}
		else
		{
			f = 0;
			break ;
		}
		j++;
	}
	if (f == 1)
		return (1);
	return (0);
}

void	get_files(t_arg **sfa, char *s, char *prefix, char **suffix)
{
	t_arg			*node;
	struct dirent	*de;
	DIR				*dr;
	int				w;

	node = NULL;
	w = 0;
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
			ftlstadd_back(&node, ftlstnew(de->d_name));
			w = 1;
		}
	}
	closedir(dr);
	if (w == 1)
		ftlstadd_back(sfa, node);
	else
	{
		node = ftlstnew(s);
		ftlstadd_back(sfa, node);
	}
}

t_arg	*parsing_wildcard(t_arg *arg)
{
	t_arg	*sfa;
	int		i;
	int		j;

	sfa = NULL;
	i = 0;
	j = 0;
	while (arg != NULL)
	{
		if (check_q(arg->data))
		{
			if (check_so(arg->data, '*'))
				get_files(&sfa, arg->data, get_prefix(arg->data),
					get_suffix(arg->data));
			else
				diklmzyana(&sfa, arg->data);
		}
		else
			diklmzyana(&sfa, arg->data);
		arg = arg->next;
	}
	return (sfa);
}

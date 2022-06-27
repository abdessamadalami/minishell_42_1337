/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_wildcard_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:35:12 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/22 09:35:13 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
	i = just_fileincrement(s, i, 0);
	while (s[i])
	{
		if (s[i] == '*')
		{
			i = just_fileincrement(s, i, 1);
			j = i;
			i = just_fileincrement(s, i, 0);
			suffix[count] = ft_subtr(s, j, i);
			count++;
		}
	}
	suffix[count] = 0;
	return (suffix);
}

int	prefix_checker(char *s, char *prefix)
{
	int	i;
	int	f;

	i = 0;
	f = 1;
	if (prefix[0] != '\0')
	{
		while (prefix[i] != '\0' && s[i] != '\0')
		{
			if (s[i] != prefix[i])
				return (0);
			i++;
		}
	}
	return (1);
}

int	suffix_checker(char *s, char **suffix)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	j = 0;
	f = 1;
	while (suffix[j] != NULL)
	{
		if (ft_index(s, suffix[j]) != -1)
		{
			if (suffix[j + 1] == NULL)
				if (s[ft_strln(s) - 1] != suffix[j][ft_strln(suffix[j]) - 1])
					return (0);
			if (!ft_wildstrcmp(s, suffix[j], ft_index(s, suffix[j])))
				return (0);
		}
		else
			return (0);
		j++;
	}
	if (f == 1)
		return (1);
	return (0);
}

void	get_files(t_arg **sfa, char *s, char **suffix, char *prefix)
{
	t_arg			*node;
	struct dirent	*de;
	DIR				*dr;
	int				w;

	node = NULL;
	w = 0;
	dr = opendir(".");
	if (!dr)
		exit(1);
	while (1)
	{
		de = readdir(dr);
		if (!de)
			break ;
		if ((prefix_checker(de->d_name, prefix)
				&& suffix_checker(de->d_name, suffix))
			|| (prefix[0] == '\0' && suffix[0][0] == '\0'))
		{
		//	printf("file: %s\n", de->d_name);
			ftlstadd_back(&node, ftlstnew(de->d_name));
			w = 1;
		}
	}
	closedir(dr);
	fill_fileslist(sfa, node, s, w);
}

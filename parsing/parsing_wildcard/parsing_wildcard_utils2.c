/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_wildcard_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:28:31 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/22 13:28:32 by ael-asri         ###   ########.fr       */
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

void	fill_fileslist(t_arg **sfa, t_arg *node, char *s, int w)
{
	if (w == 1)
		ftlstadd_back(sfa, node);
	else
		ftlstadd_back(sfa, ftlstnew(s));
}

int	just_fileincrement(char *s, int i, int x)
{
	if (!x)
		while (s[i] != '*' && s[i] != '\0')
			i++;
	else
		while (s[i] == '*' && s[i] != '\0')
			i++;
	return (i);
}

int	ft_index(char *s, char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
			if (j == ft_strln(needle))
				return (i - j);
			else
				j = 0;
		}
		else
			i++;
	}
	return (-1);
}

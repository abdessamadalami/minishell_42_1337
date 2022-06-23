/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:55:49 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/13 18:12:32 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strln(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_subtr(char	*s, int start, int len)
{
	char	*tab;
	int		i;
	int		j;

	tab = NULL;
	if (s == 0)
		return (0);
	if (len >= ft_strln(s))
		tab = malloc(sizeof(char) * (ft_strln(s) + 1));
	else if (len < ft_strln(s))
		tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && i < len)
			tab[j++] = s[i];
		i++;
	}
	tab[j] = '\0';
	return (tab);
}

char	*ft_ssubtr(char	*s, int start, int len)
{
	char	*tab;
	int		i;
	int		j;

	tab = NULL;
	if (s == 0)
		return (0);
	if (len >= ft_strln(s))
		tab = malloc(sizeof(char) * (ft_strln(s) + 1));
	else if (len < ft_strln(s))
		tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
			tab[j++] = s[i];
		i++;
	}
	tab[j] = '\0';
	return (tab);
}

char	*ft_strjn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;

	if (s2 == 0)
		s2 = ft_strdp("");
	if (!s1)
		s1 = ft_strdp("");
	tab = (char *)malloc(sizeof(char) * (ft_strln(s1) + ft_strln(s2) + 1));
	if (!tab)
		return (0);
	i = 0;
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		tab[i++] = s2[j++];
	tab[i] = '\0';
	free(s1);
	free(s2);
	return (tab);
}

char	*ft_strjnnn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;

	if (s2 == 0)
		s2 = ft_strdp("");
	if (s1 == 0)
		s1 = ft_strdp("");
	tab = (char *)malloc(sizeof(char) * (ft_strln(s1) + ft_strln(s2) + 1));
	if (!tab)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		tab[i++] = s2[j++];
	tab[i] = '\0';
	return (tab);
}

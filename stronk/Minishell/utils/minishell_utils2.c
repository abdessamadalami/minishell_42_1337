/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:55:49 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/28 22:35:36 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strln(const char *s)
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
	char	*t;

	i = 0;
	j = 0;
	t = malloc(sizeof(char *) * (ft_strln(s1) + ft_strln(s2) + 2));
	if (!t)
		return (NULL);
	while (s1[i] != '\0')
	{
		t[i] = s1[i];
		i++;
	}
	t[i] = '/';
	i++;
	while (s2[j] != '\0')
	{
		t[i] = s2[j];
		i++;
		j++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_strdp(char *s1)
{
	int		i;
	char	*p;

	p = malloc(sizeof(char) * (ft_strln(s1) + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_sstrcat(char c)
{
	char	*t;

	t = malloc(sizeof(char) * 2);
	if (!t)
		return (NULL);
	t[0] = c;
	t[1] = '\0';
	return (t);
}
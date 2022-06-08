/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:55:49 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/08 11:45:14 by ael-asri         ###   ########.fr       */
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
//	printf("start %d\n", start);
//	printf("len %d\n", len);
	while (s[i] != '\0')
	{
		if (i >= start && i < len)
		{
	//		printf("s[%d]: %c\n", i, s[i]);
			tab[j++] = s[i];
		}
		i++;
	}
	tab[j] = '\0';
//	printf("sbtura -%s-\n", tab);
	return (tab);
}

char	*ft_strjn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;

	if (s2 == 0)
		return (0);
	if (s1 == 0)
		s1 = ft_strdp("");
	tab = malloc (sizeof(char) * (ft_strln(s1) + ft_strln(s2) + 1));
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
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	return (tab);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:37:15 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/12 12:14:17 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_qso(char *s)
{
	int	i;

	i = 0;
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

int	count_q(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	*ft_calloc(int count, int size)
{
	int		i;
	char	*t;

	i = 0;
	t = malloc(count * size);
	if (t == NULL)
		exit(1);
	while (i < (size * count))
	{
		t[i] = '\0';
		i++;
	}
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

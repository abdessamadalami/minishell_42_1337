/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:49:19 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/06 08:23:28 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	set_count(t_gg *gg, char *s, int *x, int *y)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == '<' || s[i] == '>' || s[i] == '|')
		i++;
	count++;
	while (s[i] != '\0')
	{
		if (s[i] == '"')
			(*x)++;
		if (s[i] == '\'')
			(*y)++;
		if (((s[i] == '<') || (s[i] == '>' )
				|| (s[i] == '|')) && ((*x) % 2 == 0 && (*y) % 2 == 0))
		{
			if (s[i + 1] == s[i])
				i++;
				count++;
		}
		i++;
	}
	gg->qq = gg->lock;
	return (count + 2);
}

static char	**ft_del(char **t, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(t[i]);
		i++;
	}
	free(t);
	return (NULL);
}

static char	**chek_and_fill(t_gg *gg, char **t, char *s, int x, int y)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	while (s[i])
	{
		temp = i;
		if (s[i] == '"')
		{
			x--;
			i++;
		}
		if (s[i] == '\'')
		{
			y--;
			i++;
		}
		if ((s[i] == '<' || s[i] == '>' || s[i] == '|')
			&& (x % 2 == 0 && y % 2 == 0))
		{
			if (s[i + 1] == s[i])
				i++;
			i++;
			t[count] = ft_subtr(s, temp, i - temp);
			count++;
			continue ;
		}
		while (s[i])
		{
			if (s[i] == '"')
				x--;
			if (s[i] == '\'')
				y--;
			if (((s[i] == '<' || s[i] == '>' || s[i] == '|')
					&& (x % 2 == 0 && y % 2 == 0)))
				break ;
			i++;
		}
		t[count] = ft_subtr(s, temp, i - temp);
		if (t[count] == NULL)
			return (ft_del(t, count));
		count++;
	}
	t[count] = 0;
	gg->count = count;
	return (t);
}

char	**squsplit(t_gg *gg, char *s)
{
	char	**t;
	int		count;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (s == 0)
		return (0);
	count = set_count(gg, s, &x, &y);
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == NULL)
		return (0);
	return (chek_and_fill(gg, t, s, x, y));
}

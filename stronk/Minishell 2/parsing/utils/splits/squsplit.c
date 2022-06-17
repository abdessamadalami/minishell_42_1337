/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:49:19 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/11 13:28:36 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static int	set_count(t_gg *gg, char *s, t_squsplit *sq)
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
			sq->x++;
		if (s[i] == '\'')
			sq->y++;
		if (((s[i] == '<') || (s[i] == '>' )
				|| (s[i] == '|')) && (sq->x % 2 == 0 && sq->y % 2 == 0))
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

static char	**chek_and_fill(char **t, char *s, t_squsplit *sq)
{
	int	i;
	int	temp;

	i = 0;
	while (s[i])
	{
		temp = i;
		check_sdq(s, sq, &i);
		if ((s[i] == '<' || s[i] == '>' || s[i] == '|')
			&& (sq->x % 2 == 0 || sq->y % 2 == 0))
		{
			random_if(s, &i);
			i++;
			t[sq->count] = ft_ssubtr(s, temp, i - temp);
			sq->count++;
			continue ;
		}
		just_awhile(s, sq, &i);
		t[sq->count] = ft_ssubtr(s, temp, i - temp);
		if (t[sq->count] == NULL)
			return (ft_del(t, sq->count));
		sq->count++;
	}
	t[sq->count] = 0;
	return (t);
}

char	**squsplit(t_gg *gg, char *s)
{
	char		**t;
	t_squsplit	sq;
	int			ct;

	sq.x = 0;
	sq.y = 0;
	sq.count = 0;
	if (s == 0)
		return (0);
	ct = set_count(gg, s, &sq);
	t = (char **)malloc(sizeof(char *) * (ct + 1));
	if (t == NULL)
		return (0);
	return (chek_and_fill(t, s, &sq));
}

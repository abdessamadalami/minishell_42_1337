/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qt_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:32:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/10 19:37:10 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	count_quotes(char *s, int x, int y)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"')
		{
			x++;
			i++;
			i = just_while(s, '"', i);
			if (s[i] == '"')
				x++;
		}
		else if (s[i] == '\'')
		{
			y++;
			i++;
			i = just_while(s, '\'', i);
			if (s[i] == '\'')
				y++;
		}
		i++;
	}
	return (print_if(x, y));
}
/*
int	*count_sdq(char *s, char f, char l)
{
	int	*t;
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	t = malloc(sizeof(int) * 3);
	while (s[i] != '\0')
	{
		if (s[i] == f)
			x++;
		if (s[i] == l && x % 2 == 0)
			y++;
		i++;
	}
	t[0] = x;
	t[1] = y;
	t[2] = '\0';
	return (t);
}
*/

int	check_qt(t_arg *s)
{
	int	x;
	int	y;

	while (s != NULL)
	{
		x = 0;
		y = 0;
		if (!count_quotes(s->data, x, y))
			return (0);
		s = s->next;
	}
	return (1);
}

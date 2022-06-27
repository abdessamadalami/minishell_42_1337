/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_syntax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:28:14 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/10 19:34:04 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	check_red_condition(char *s, int i, int count)
{
	if ((s[i] == '>' || s[i] == '<') && (count % 2 == 0)
		&& (s[i + 1] == '>' || s[i + 1] == '<')
		&& (s[i + 2] == '>' || s[i + 2] == '<'))
		return (1);
	return (0);
}

void	decrement_count(char *s, int i, int *count)
{
	if (s[i] == first_occc(s))
		(*count)--;
}

int	check_red(t_arg *s)
{
	int		i;
	int		count;
	int		w;
	char	r;

	while (s != NULL)
	{
		i = 0;
		w = 0;
		count = count_q(s->data, first_occc(s->data));
		while (s->data[i] != '\0')
		{
			decrement_count(s->data, i, &count);
			if (check_red_condition(s->data, i, count))
			{
				r = s->data[i + 2];
				w++;
			}
			i++;
		}
		if (w > 0)
			return (print_syntax_error(w, r));
		s = s->next;
	}
	return (1);
}

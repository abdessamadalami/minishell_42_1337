/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_syntax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:30:30 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/10 19:30:59 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	check_pip(t_arg *s)
{
	int		i;
	int		count;
	int		p;

	while (s != NULL)
	{
		i = 0;
		p = 0;
		count = count_q(s->data, first_occc(s->data));
		while (s->data[i] != '\0')
		{
			if (s->data[i] == first_occc(s->data))
				count--;
			if ((s->data[i] == '|') && (count % 2 == 0))
				p++;
			i++;
		}
		if (p > 1)
			return (print_syntax_error(p, '|'));
		s = s->next;
	}
	return (1);
}

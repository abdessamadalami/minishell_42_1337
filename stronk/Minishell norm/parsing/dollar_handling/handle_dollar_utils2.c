/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:26:11 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/15 18:31:28 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	lock_malo(char c, int *lock)
{
	if (c == '$')
		(*lock) = 1;
	else
		(*lock) = 0;
}

void	put_z3tindaplaces2(t_arg *sfa, t_arg *z3ta, char *s)
{
	char	*l;
	t_arg	*node;

	l = ft_allocate(s);
	while (z3ta != NULL)
	{
		l = ft_strjn(l, z3ta->data);
		z3ta = z3ta->next;
	}
	if (l[0] != '\0')
	{
		node = ftlstnew(l);
		ftlstadd_back(&sfa, node);
	}
	l = NULL;
}

void	addback_wsf2(t_arg **z3ta, char *s)
{
	t_arg	*node;

	node = ftlstnew(s);
	ftlstadd_back(z3ta, node);
}

char	*check_get_env2(char *var, int *lock)
{
	char	*s;

	if (!getenv(var))
	{
		(*lock) = 0;
		s = ft_strdp("");
		return (s);
	}
	return (NULL);
}

int	is_there_dq(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
			return (0);
		i++;
	}
	return (1);
}

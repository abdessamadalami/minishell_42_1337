/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzzaf_tdollarats2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:39:40 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/15 18:23:55 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	conditions_topassd(char c)
{
	if ((((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
				|| (c >= '0' && c <= '9')) || c == '_') && c != '\0')
		return (1);
	return (0);
}

int	ds_index(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '$' && s[i + 1] == '$')
		{
			count = i;
			i++;
			while (s[i] == '$' && s[i] != '\0')
				i++;
		}
		i++;
	}
	return (count);
}

char	*check_get_env(char *s, char *var, int *lock, int *i)
{
	if (!getenv(var))
	{
		(*lock) = 0;
		(*i) = ft_strln(s);
		return (s);
	}
	return (NULL);
}

char	**getsplitted(char *s)
{
	char	**temp;

	temp = (char **)malloc(sizeof(char *) * (ft_strln(s) + 1));
	if (!temp)
		exit (1);
	temp = dosplit(s, '"');
	if (!temp)
		exit (1);
	return (temp);
}

void	addback_wsf(t_arg *z3ta, char *s)
{
	t_arg	*node;

	node = ftlstnew(s);
	ftlstadd_back(&z3ta, node);
}

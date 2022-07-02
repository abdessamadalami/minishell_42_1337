/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:01:34 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/29 18:01:35 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_alphanum(char c)
{
	if ((((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
				|| (c >= '0' && c <= '9')) || c == '_'))
		return (1);
	return (0);
}

void	ft_lock(char c, int *lock, int *dlock)
{
	if (c == '"' && *dlock)
		*dlock = 0;
	else if (c == '"' && !(*dlock))
		*dlock = 1;
	if (c == '\'' && *lock && (*dlock))
		*lock = 0;
	else if (c == '\'' && !(*lock) && !(*dlock))
		*lock = 1;
}

void	fill_withenv(char **t, char *env, int *j)
{
	char	*tmp;

	tmp = *t;
	*t = ft_strjnnn(*t, env);
	*j += ft_strln(env);
	free(tmp);
}

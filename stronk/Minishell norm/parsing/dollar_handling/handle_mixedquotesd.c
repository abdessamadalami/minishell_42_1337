/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mixedquotesd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:46:38 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/15 18:40:05 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	conditions_topass(char c)
{
	if ((((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
				|| (c >= '0' && c <= '9')) || c == '_') && c != '\0')
		return (1);
	return (0);
}

static char	*check_get_env3(char *var, int *lock)
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

char	*fill_jma3ad(char *s, char *jma3a, int *i, int *lock)
{
	char	*var;
	char	*gg;
	int		j;

	var = ft_allocate(s);
	gg = ft_allocate(s);
	j = 0;
	(*i)++;
	while (conditions_topass(s[*i]))
		var[j++] = s[(*i)++];
	var[j] = '\0';
	if (check_get_env3(var, lock))
		return (check_get_env3(var, lock));
	jma3a = ft_strjn(jma3a, getenv(var));
	j = 0;
	while (s[*i] != '$' && s[*i] != '\0')
		gg[j++] = s[(*i)++];
	jma3a = ft_strjn(jma3a, gg);
	if (s[*i] == '$')
		(*lock) = 1;
	else
		(*lock) = 0;
	gg = NULL;
	var = NULL;
	return (jma3a);
}

void	handle_mixed_quotes(t_arg *sfa, char *s)
{
	int		i;
	int		x;
	char	*t;
	int		lock;
	char	*jma3a;

	i = 0;
	x = 0;
	lock = 1;
	t = ft_allocate(s);
	jma3a = ft_allocate(s);
	while (s[i] != '\0')
	{
		if (s[i] == '$')
		{
			jma3a = ft_strjn(jma3a, t);
			while (lock)
				jma3a = fill_jma3ad(s, jma3a, &i, &lock);
		}
		else
			t[x++] = s[i++];
	}
	if (jma3a[0] != '\0')
		addback_wsf(sfa, jma3a);
	t = NULL;
}

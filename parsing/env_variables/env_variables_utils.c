/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:10:18 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/29 16:40:47 by ael-oual         ###   ########.fr       */
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

void	ques_mark(char **t, char *s, int *i, int *j)
{
	char	*var;
	char	*tmp;
	int		x;

	var = ft_allocate(s);
	x = 0;
	*t = ft_strjnnn(*t, ft_itoa(e_st));
	(*i)++;
	while (s[*i] == '?' && s[*i] != '\0')
		var[x++] = s[(*i)++];
	var[x] = '\0';
	if (var != NULL)
	{
		tmp = *t;
		*t = ft_strjnnn(*t, var);
		*j += ft_strln(ft_itoa(e_st)) + ft_strln(var);
		free(tmp);
	}
	free(var);
}

void	normal_case(char **t, char *s, int *i, int *j)
{
	char	*var;
	char	*tmp;
	int		x;

	var = ft_allocate(s);
	x = 0;
	if (s[*i] == '?')
		ques_mark(t, s, i, j);
	else
	{
		while (is_alphanum(s[*i]) && s[*i] != '\0')
			var[x++] = s[(*i)++];
		var[x] = '\0';
		if (getenv(var) != NULL)
		{
			tmp = *t;
			*t = ft_strjnnn(*t, getenv(var));
			*j += ft_strln(getenv(var));
			free(tmp);
		}
		free(var);
	}
}

void	mult_case(char **t, int count, int *j)
{
	char	*tmp;

	(void)j;
	(*j) += ft_strln("1337") * (count / 2);
	while (count > 0)
	{
		tmp = *t;
		*t = ft_strjnnn(tmp, "1337");
		free(tmp);
		count -= 2;
	}
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

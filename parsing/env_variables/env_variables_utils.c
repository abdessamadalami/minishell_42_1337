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

int	ques_mark(char **t, char *s, int *i)
{
	char	*var;
	char	*tmp;
	int		x;
	int		j;

	var = ft_allocate(s);
	x = 0;
	j = 0;
	*t = ft_strjnnn(*t, ftitoa(g_st));
	(*i)++;
	while (s[*i] == '?' && s[*i] != '\0')
		var[x++] = s[(*i)++];
	var[x] = '\0';
	if (var != NULL)
	{
		tmp = *t;
		*t = ft_strjnnn(*t, var);
		j += ft_strln(ftitoa(g_st)) + ft_strln(var);
		free(tmp);
	}
	free(var);
	return (j);
}

int	ft_check_for_env(char *content, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && content[j] != '=' && content[j] != '\0')
	{
		if (s[i] != content[j])
			return (0);
		j++;
		i++;
	}
	if (content[i] == '=' && s[i] == '\0')
		return (1);
	else
		return (0);
}

char	*get_env(t_list *env_lst, char *s)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	j = 0;
	t = NULL;
	while (env_lst != NULL)
	{
		t = env_lst->content;
		if (ft_check_for_env(t, s))
		{
			while (t[j] != '=' && t[j] != '\0')
				j++;
			if (t[j] == '=')
				j++;
			return (ft_subtr(t, j, ft_strln(t)));
		}
		env_lst = env_lst->next;
	}
	return (NULL);
}

int	normal_case(t_list *env_lst, char **t, char *s, int *i)
{
	char	*var;
	int		x;
	int		j;
	char	*env;

	var = ft_allocate(s);
	x = 0;
	j = 0;
	if (s[*i] == '?')
		j += ques_mark(t, s, i);
	else
	{
		while (is_alphanum(s[*i]) && s[*i] != '\0')
			var[x++] = s[(*i)++];
		var[x] = '\0';
		env = get_env(env_lst, var);
		if (env != NULL)
			fill_withenv(t, env, &j);
		free(var);
		free(env);
	}
	return (j);
}

int	mult_case(char **t, int count)
{
	char	*tmp;
	int		j;

	j = ft_strln("1337") * (count / 2);
	while (count > 0)
	{
		tmp = *t;
		*t = ft_strjnnn(tmp, "1337");
		free(tmp);
		count -= 2;
	}
	return (j);
}

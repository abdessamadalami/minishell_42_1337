/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:23:59 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/16 14:59:54 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_allocate(char *s)
{
	char	*t;

	t = malloc(sizeof(char) * (ft_strln(s) + 1));
	if (!t)
		exit(1);
	return (t);
}

int	env_varhandling(t_list *env_lst, char **t, char *s, int *i)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (s[*i] == '$')
	{
		count++;
		(*i)++;
	}
	if (count > 1)
	{
		if (!(count % 2))
			j += mult_case(t, count);
		else
		{
			j += mult_case(t, count - 1);
			j += normal_case(env_lst, t, s, i);
		}
	}
	else
		j += normal_case(env_lst, t, s, i);
	return (j);
}

char	*ft_putenv_variables(char *s, t_list *env_lst)
{
	char	*t;
	int		i;
	int		j;
	int		lock;
	int		dlock;

	t = ft_calloc((ft_strln(s) + 1), sizeof(char));
	i = 0;
	j = 0;
	lock = 1;
	dlock = 1;
	while (s[i] != '\0')
	{
		ft_lock(s[i], &lock, &dlock);
		if (s[i] == '$' && lock && (is_alphanum(s[i + 1]) || s[i + 1] == '?'))
			j += env_varhandling(env_lst, &t, s, &i);
		else
			t[j++] = s[i++];
	}
	t[j] = '\0';
	return (t);
}

void	ftlstadd_backfff(t_arg **lst, t_arg *new)
{
	t_arg	*list;
	char	*t;

	list = *lst;
	if (*lst == 0)
	{
		t = new->data;
		*lst = ftlstnew(t);
		free(t);
		return ;
	}
	while (list->next != NULL)
	{
		list = list->next;
	}
	list->next = new;
}

t_arg	*check_envvars(t_arg *arg, t_list *env_lst)
{
	t_arg	*sfa;
	char	*t;

	sfa = NULL;
	t = NULL;
	while (arg != NULL)
	{
		if (!(arg->data[0] == '$' && arg->data[1] == '\0')
			&& (check_so(arg->data, '$')))
		{
			t = ft_putenv_variables(arg->data, env_lst);
			if (t[0] != '\0')
				ftlstadd_backfff(&sfa, ftlstnew(t));
			free (t);
			t = NULL;
		}
		else
			ftlstadd_back(&sfa, ftlstnew(arg->data));
		arg = arg->next;
	}
	return (sfa);
}

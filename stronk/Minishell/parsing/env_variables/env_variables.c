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

void	env_varhandling(char **t, char *s, int *i, int *j)
{
	int		count;

	count = 0;
	while (s[*i] == '$')
	{
		count++;
		(*i)++;
	}
/*	if (s[*i] == '?')
	{
		char *gg;
		gg = ft_strdp("?");
		printf("%s\n", getenv(gg));
		*t = ft_strjn(*t, getenv(gg));
	printf("lll\n");
		j += ft_strln(getenv(gg));
		printf("shh\n");
	}
	else*/ if (count > 1)
	{
		if (!(count % 2))
			mult_case(t, count, j);
		else
		{
			mult_case(t, count - 1, j);
			normal_case(t, s, i, j);
		}
	}
	else
		normal_case(t, s, i, j);
}

char	*ft_putenv_variables(char *s)
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
		if (s[i] == '$' && lock)
			env_varhandling(&t, s, &i, &j);
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

t_arg	*check_envvars(t_arg *arg)
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
			t = ft_putenv_variables(arg->data);
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

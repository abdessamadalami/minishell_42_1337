/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzzaf_tdollarats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:50:24 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/15 18:41:15 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
char	*zawji_dollaring(char *s)
{
	char	*t;
	int		i;

	i = 0;
	t = malloc(sizeof(char) * (ft_strln(s) + 1));
	if (!t)
		exit (1);
	while (s[i] != '\0')
	{
		if (i == ds_index(s))
		{
			i++;
			break;
		}
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	if (s[i] != '\0')
	{
		int j = 0;
		while (j < lot_ofthem(s))
		{
			t = ft_strjn(t, ft_itoa(getpid()));
			j += 2;
		}
	}
	t = ft_strjn(t, &s[i + (lot_ofthem(s)-1)]);
	return (t);
}
*/

char	*fill_jma3a_forbzzaf(char *s, char *jma3a, int *i, int *lock)
{
	char	*var;
	char	*gg;
	int		j;

	var = ft_allocate(s);
	gg = ft_allocate(s);
	j = 0;
	(*i)++;
	while (conditions_topassd(s[*i]))
		var[j++] = s[(*i)++];
	var[j] = '\0';
	if (check_get_env(s, var, lock, i))
		return (check_get_env(s, var, lock, i));
	jma3a = ft_strjn(jma3a, getenv(var));
	j = 0;
	while (s[*i] != '$' && s[*i] != '\0')
		gg[j++] = s[(*i)++];
	jma3a = ft_strjn(jma3a, gg);
	lock_malo2(s[*i], s[(*i) + 1], lock);
	gg = NULL;
	var = NULL;
	return (jma3a);
}

char	*putvaluesornot_forbzzaf(char *s)
{
	char	*t;
	char	*jma3a;
	int		i;
	int		x;
	int		lock;

	t = ft_allocate(s);
	jma3a = ft_allocate(s);
	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		lock = 1;
		if (s[i] == '$' && s[i + 1] != '$') // echo $$$5gg
		{
			jma3a = ft_strjn(jma3a, t);
			while (lock)
				jma3a = fill_jma3a_forbzzaf(s, jma3a, &i, &lock);
		}
		else
			t[x++] = s[i++];
	}
	t = NULL;
	return (jma3a);
}

static void	put_z3tindaplaces(t_arg *sfa, t_arg *z3ta, char *s)
{
	t_arg	*node;
	char	*l;

	l = malloc(sizeof(char) * (ft_strln(s) + 1));
	if (!l)
		exit (1);
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

void	bzzaf_tdollarats(t_arg *sfa, char *s)
{
	t_arg	*node;
	t_arg	*z3ta;
	char	**temp;
	int		z;

	z = 0;
	z3ta = NULL;
	temp = getsplitted(s);
	while (temp[z] != NULL)
	{
		if (!check_dollar(temp[z]) && is_there_dq(temp[z]))
		{
			if (putvaluesornot_forbzzaf(temp[z]))
			{
				node = ftlstnew(putvaluesornot_forbzzaf(temp[z]));
				ftlstadd_back(&z3ta, node);
			}
		}
		else
			addback_wsf(z3ta, temp[z]);
		if (temp[z + 1] == NULL)
			put_z3tindaplaces(sfa, z3ta, s);
		z++;
	}
}

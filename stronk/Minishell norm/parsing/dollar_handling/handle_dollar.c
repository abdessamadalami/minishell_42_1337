/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:20:23 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/15 19:09:09 by ael-asri         ###   ########.fr       */
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

char	*fill_jma3a(char *s, char *jma3a, int *i, int *lock)
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
	if (check_get_env2(var, lock))
		return (check_get_env2(var, lock));
	jma3a = ft_strjn(jma3a, getenv(var));
	j = 0;
	while (s[*i] != '$' && s[*i] != '\0')
		gg[j++] = s[(*i)++];
	jma3a = ft_strjn(jma3a, gg);
	lock_malo(s[*i], lock);
	gg = NULL;
	var = NULL;
	return (jma3a);
}

char	*putvaluesornot(char *s)
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
		if (s[i] == '$')
		{
			jma3a = ft_strjn(jma3a, t);
			while (lock)
				jma3a = fill_jma3a(s, jma3a, &i, &lock);
		}
		else
			t[x++] = s[i++];
	}
	t = NULL;
	return (jma3a);
}

void	handle_dollar(t_arg *sfa, char *s)
{
	t_arg	*node;
	t_arg	*z3ta;
	char	**temp;
	int		z;

	z = 0;
	z3ta = NULL;
	temp = getsplitted(s);
	/*for(int r=0;temp[r];r++)
		printf("r %s\n", temp[r]);*/
	while (temp[z] != NULL)
	{
		if (!check_dollar(temp[z]) && is_there_dq(temp[z]))
		{
			if (putvaluesornot(temp[z]))
			{
				node = ftlstnew(putvaluesornot(temp[z]));
				ftlstadd_back(&z3ta, node);
			}
		}
		else
			addback_wsf2(&z3ta, temp[z]);
		if (temp[z + 1] == NULL)
			put_z3tindaplaces2(sfa, z3ta, s);
		z++;
	}
}

t_arg	*check_for_dollar(t_arg *arg)
{
	t_arg	*sfa;

	sfa = NULL;
	while (arg != NULL)
	{
		if (!check_dollar_mark(arg->data))
			addback_wsf2(&sfa, arg->data);
		else if (checki_checki(arg->data))
			handle_mixed_quotes(sfa, arg->data);
		else if (lot_ofthem(arg->data) > 1)
			bzzaf_tdollarats(sfa, arg->data);
		else if (!check_dollar(arg->data) && first_occc(arg->data) != '\'')
			handle_dollar(sfa, arg->data);
		else
			addback_wsf2(&sfa, arg->data);
		arg = arg->next;
	}
	return (sfa);
}

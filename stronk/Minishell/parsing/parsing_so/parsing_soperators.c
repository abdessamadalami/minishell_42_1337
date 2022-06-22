/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_soperators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:05:14 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/10 21:07:01 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	so_counter(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '>' || s[i] == '<' || s[i] == '|')
		{
			if (i > 0)
				count++;
			if (s[i + 1] == '>' || s[i + 1] == '<')
				i++;
			count++;
		}
		if (s[i + 1] == '\0' && s[i] != '>' && s[i] != '<')
		{
			count++;
			break ;
		}
		i++;
	}
	return (count);
}

static void	diklmzyanalokhra(t_arg **sfa, char *s)
{
	char	**temp;
	int		so_c;

	temp = NULL;
	so_c = so_counter(s);
	temp = sosplit(s);
	addbacki_sf(sfa, temp);
}

static void	diklmzyanalokhrawsf(t_arg **sfa, t_gg *gg, char *s)
{
	char	**temp;
	char	**b;
	int		so_c;

	temp = NULL;
	so_c = so_counter(s);
	b = temp;
	temp = squsplit(gg, s);
	addbacki_sf(sfa, temp);
}

t_arg	*parsin_dyalbss7(t_arg *arg, t_gg *gg)
{
	t_arg	*sfa;

	sfa = NULL;
	while (arg != NULL)
	{
		if (check_q(arg->data))
		{
			if ((check_so(arg->data, '<') || check_so(arg->data, '>')
					|| check_so(arg->data, '|')))
			{
				if (ft_strln(arg->data) == 1 || (ft_strln(arg->data) == 2
						&& (arg->data[0] == arg->data[1])
						&& arg->data[0] != '|'))
					ftlstadd_back(&sfa, ftlstnew(arg->data));
				else
					diklmzyanalokhra(&sfa, arg->data);
			}
			else
				ftlstadd_back(&sfa, ftlstnew(arg->data));
		}
		else
			diklmzyanalokhrawsf(&sfa, gg, arg->data);
		arg = arg->next;
	}
	return (sfa);
}

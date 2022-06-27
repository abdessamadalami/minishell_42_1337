/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:04:55 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/16 14:44:45 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*parsing_quotes(char *s)
{
	char	*t;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	t = (char *)malloc(sizeof(char *) * (ft_strln(s) + 1));
	if (!t)
		exit(1);
	while (s[i] != '\0')
	{
		if (s[i] == '"')
			parse_quotes_fordq(s, t, &i, &j);
		if (s[i] == '\'')
			parse_quotes_forsq(s, t, &i, &j);
		else
			parse_quotes_lastone(s, t, &i, &j);
	}
	t[j] = '\0';
	return (t);
}

t_arg	*remove_quotes(t_arg *arg)
{
	int		i;
	int		j;
	t_arg	*sfa;
	char	*s;

	sfa = NULL;
	i = 0;
	j = 0;
	while (arg != NULL)
	{
		if (!check_q(arg->data))
		{
			s = parsing_quotes(arg->data);
			if (*s != '\0')
				ftlstadd_back(&sfa, ftlstnew(s));
			free(s);
			s = NULL;
		}
		else
			ftlstadd_back(&sfa, ftlstnew(arg->data));
		arg = arg->next;
	}
	return (sfa);
}

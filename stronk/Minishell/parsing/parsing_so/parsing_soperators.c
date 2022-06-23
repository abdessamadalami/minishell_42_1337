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

void	parse_so_fordq(char *s, char **t, int *i, t_normsht *normsht)
{
	normsht->init = *i;
	(*i)++;
	while (s[*i] != '"' && s[*i] != '\0')
		(*i)++;
	if (s[*i] == '"')
		(*i)++;
	t[normsht->count] = ft_strjn(t[normsht->count],
			ft_subtr(s, (normsht->init), *i));
	normsht->init = *i;
}

void	parse_so_forsq(char *s, char **t, int *i, t_normsht *normsht)
{
	normsht->init = *i;
	(*i)++;
	while (s[*i] != '\'' && s[*i] != '\0')
		(*i)++;
	if (s[*i] == '\'')
		(*i)++;
	t[normsht->count] = ft_strjn(t[normsht->count],
			ft_subtr(s, (normsht->init), *i));
	normsht->init = *i;
}

void	parse_so_forso(char *s, char **t, int *i, t_normsht *normsht)
{
	if (i != 0 && s[(*i) - 1] != '<'
		&& s[(*i) - 1] != '>' && s[(*i) - 1] != '|')
		normsht->count++;
	normsht->init = *i;
	(*i)++;
	if (s[*i] == s[(*i) - 1] && s[*i] != '|')
		(*i)++;
	t[normsht->count] = ft_subtr(s, (normsht->init), *i);
	normsht->count++;
}

char	**get_parsed_so(char *s)
{
	char		**t;
	t_normsht	normsht;
	int			i;

	i = 0;
	normsht.count = 0;
	normsht.init = 0;
	t = (char **)ft_calloc(sizeof(char *), (so_counter(s) * ft_strln(s)));
	while (s[i] != '\0')
	{
		if (s[i] == '"')
			parse_so_fordq(s, t, &i, &normsht);
		else if (s[i] == '\'')
			parse_so_forsq(s, t, &i, &normsht);
		else if (s[i] == '>' || s[i] == '<' || s[i] == '|')
			parse_so_forso(s, t, &i, &normsht);
		else
		{
			normsht.init = i;
			t[normsht.count] = ft_strjn(t[normsht.count],
					ft_subtr(s, (normsht.init), ++i));
		}
	}
	t[++normsht.count] = 0;
	return (t);
}

t_arg	*parse_so(t_arg *arg)
{
	t_arg		*sfa;
	t_arg		*node;
	char		**t;
	int			i;

	sfa = NULL;
	while (arg != NULL)
	{
		if (check_so(arg->data, '>') || check_so(arg->data, '<')
			|| check_so(arg->data, '|'))
		{
			t = get_parsed_so(arg->data);
			i = 0;
			while (t[i] != '\0')
			{
				node = ftlstnew(t[i]);
				free(t[i]);
				ftlstadd_back(&sfa, node);
				i++;
			}
			free(t);
		}
		else
		{
			node = ftlstnew(arg->data);
			ftlstadd_back(&sfa, node);
		}
		arg = arg->next;
	}
	return (sfa);
}

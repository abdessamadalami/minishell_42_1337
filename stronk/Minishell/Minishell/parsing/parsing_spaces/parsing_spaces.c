/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:49:33 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/12 12:27:38 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	parse_spaces_fordq(char *s, char **t, int *i, t_normsht *normsht)
{
	(*i)++;
	while (s[*i] != '"' && s[*i] != '\0')
		(*i)++;
	(*i)++;
	t[normsht->count] = ft_strjn(t[normsht->count],
			ft_subtr(s, (normsht->init), (*i)));
	normsht->init = *i;
}

void	parse_spaces_forsq(char *s, char **t, int *i, t_normsht *normsht)
{
	(*i)++;
	while (s[*i] != '\'' && s[*i] != '\0')
		(*i)++;
	(*i)++;
	t[normsht->count] = ft_strjn(t[normsht->count],
			ft_subtr(s, (normsht->init), (*i)));
	normsht->init = *i;
}

void	parse_spaces_lastone(char *s, char **t, int *i, t_normsht *normsht)
{
	if (s[(*i) + 1] == '\0')
	{
		t[normsht->count] = ft_strjn(t[normsht->count],
				ft_subtr(s, (normsht->init), (*i) + 1));
		(*i)++;
		return ;
	}
	t[normsht->count] = ft_strjn(t[normsht->count],
			ft_subtr(s, (normsht->init), (*i)));
	normsht->count++;
	while (s[*i] == ' ' && s[*i] != '\0')
		(*i)++;
	normsht->init = *i;
}

t_arg	*parsing_spaces(char *s)
{
	t_normsht	normsht;
	char		**t;
	int			i;

	i = 0;
	normsht.count = 0;
	normsht.init = 0;
	t = (char **)ft_calloc(sizeof(char *),
			((spaces_counter(s) + 1) * ft_strln(s)));
	if (!t)
		exit(1);
	while (s[i] == ' ')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == '"')
			parse_spaces_fordq(s, t, &i, &normsht);
		else if (s[i] == '\'')
			parse_spaces_forsq(s, t, &i, &normsht);
		else if (s[i] == ' ' || s[i + 1] == '\0')
			parse_spaces_lastone(s, t, &i, &normsht);
		else
			i++;
	}
	return (fill_list(t, &normsht));
}

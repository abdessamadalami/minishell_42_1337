/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:18:33 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/14 12:02:50 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	parse_quotes_fordq(char *s, char *t, int *i, int *j)
{
	(*i)++;
	while (s[*i] != '\0' && s[*i] != '"')
	{
		t[*j] = s[*i];
		(*i)++;
		(*j)++;
	}
	(*i)++;
}

void	parse_quotes_forsq(char *s, char *t, int *i, int *j)
{
	(*i)++;
	while (s[*i] != '\0' && s[*i] != '\'')
	{
		t[*j] = s[*i];
		(*i)++;
		(*j)++;
	}
	(*i)++;
}

void	parse_quotes_lastone(char *s, char *t, int *i, int *j)
{
	if (s[*i] != '\0' && s[*i] != '"' && s[*i] != '\'')
	{
		t[*j] = s[*i];
		(*i)++;
		(*j)++;
	}
}

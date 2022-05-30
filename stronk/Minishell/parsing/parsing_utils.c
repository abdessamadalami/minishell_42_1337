/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:35:06 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/30 20:35:31 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_so(char *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_q(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == '"' || s[i] == '\''))
		{
			return (0);
		}
		i++;
	}
		return (1);
}

char	get_token(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '>' || s[i] == '<' || s[i] == '|')
			return (s[i]);
		i++;
	}
	return (0);
}

char	get_qtoken(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"' || s[i] == '\'')
			return (s[i]);
		i++;
	}
	return (0);
}

int	check_qso(char *s)
{
	int	i;

	i = 0;
	if (s[i] )
	while (s[i] != '\0')
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			i++;
			while (s[i] != '"' && s[i] != '\'')
				i++;
		}
		i++;
		if (s[i] == '\0' || s[i] == '>' || s[i] == '<' || s[i] == '|')
			return (0);
		i++;
	}
	return (1);
}
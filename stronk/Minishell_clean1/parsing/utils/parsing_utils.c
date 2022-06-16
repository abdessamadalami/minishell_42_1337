/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:35:06 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/10 18:00:56 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

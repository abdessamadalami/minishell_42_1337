/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:22:20 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/15 19:06:40 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_qdollar(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'' && s[i] != '\0')
			{
				if (s[i] == '$')
					return (0);
				i++;
			}
			if (s[i] == '\0')
				break ;
		}
		i++;
	}
	return (1);
}

int	check_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '$')
			return (0);
		i++;
	}
	return (1);
}

int	check_dollar_mark(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '$')
			if (s[i + 1] == '?')
				return (0);
		i++;
	}
	return (1);
}

int	checki_checki(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"')
		{
			i++;
			while (s[i] != '"' && s[i] != '\0')
			{
				if (s[i] == '\'')
				{
					i++;
					while (s[i] != '\'' && s[i] != '\0')
					{
						if (s[i] == '$')
							return (1);
						i++;
					}
				}
				i++;
			}
		}
		i++;
	}
	return (0);
}

int	lot_ofthem(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '$' && s[i + 1] == '$')
		{
			count = 1;
			i++;
			while (s[i] == '$' && s[i] != '\0')
			{
				count++;
				i++;
			}
		}
		i++;
	}
	return (count);
}


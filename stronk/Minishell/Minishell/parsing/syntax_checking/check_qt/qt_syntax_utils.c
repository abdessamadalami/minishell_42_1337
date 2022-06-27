/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qt_syntax_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:24:41 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/10 19:36:08 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

char	first_occc(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"' || s[i] == '\'')
			return (s[i]);
		i++;
	}
	return ('\0');
}

char	last_occc(char *s)
{
	char	f;

	f = first_occc(s);
	if (f == '"')
		return ('\'');
	return ('"');
}

int	print_if(int x, int y)
{
	if (x % 2 != 0)
		return (print_syntax_error(1, '"'));
	if (y % 2 != 0)
		return (print_syntax_error(1, '\''));
	return (1);
}

int	just_while(char *s, char c, int i)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

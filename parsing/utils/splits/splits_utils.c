/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splits_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:48:56 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/11 13:26:38 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	check_sdq(char *s, t_squsplit *sq, int *i)
{
	if (s[(*i)] == '"')
	{
		sq->x--;
		(*i)++;
	}
	if (s[(*i)] == '\'')
	{
		sq->y--;
		(*i)++;
	}
}

void	just_awhile(char *s, t_squsplit *sq, int *i)
{
	while (s[(*i)])
	{
		if (s[(*i)] == '"')
			sq->x--;
		if (s[(*i)] == '\'')
			sq->y--;
		if (((s[(*i)] == '<' || s[(*i)] == '>' || s[(*i)] == '|')
				&& (sq->x % 2 == 0 || sq->y % 2 == 0)))
			return ;
		(*i)++;
	}
}

void	random_if(char *s, int *i)
{
	if (s[(*i) + 1] == s[(*i)])
		(*i)++;
}

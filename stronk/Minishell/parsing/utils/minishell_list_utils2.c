/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_list_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:07:39 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/10 20:08:39 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strllen(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i][j])
			j++;
		i++;
	}
	return (i);
}

void	addbacki_sf(t_arg **sfa, char **t)
{
	int	i;

	i = 0;
	while (t[i] != 0)
	{
		ftlstadd_back(sfa, ftlstnew(t[i]));
		free(t[i]);
		i++;
	}
	free(t);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzzaf_tdollarats3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:23:14 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/15 18:25:30 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	lock_malo2(char c, char v, int *lock)
{
	if (c == '$' && v != '$')
		(*lock) = 1;
	else
		(*lock) = 0;
}

char	*ft_allocate(char *s)
{
	char	*t;

	t = malloc(sizeof(char) * (ft_strln(s) + 1));
	if (!t)
		exit(1);
	return (t);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:23:19 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/01 09:49:13 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_42_1337.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (!s || !fd)
		return ;
	while (s[index] != '\0')
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:11:41 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/28 16:20:05 by sultan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

int	check_forflag(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '\\')
		i++;
	if (s[0] != '-')
		return (0);
	while (s[i] == '\\')
		i++;
	i++;
	while (s[i] != '\0')
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo_o(char **av)
{
	int	i;
	int	f;

	i = 1;
	f = 0;
	if (av[i] != NULL)
	{
		if (*av != NULL)
		{
			f = check_forflag(av[i]);
			if (f)
				i++;
			while (av[i] != NULL)
			{
				printf("%s", av[i]);
				if (av[i + 1] != 0)
					printf(" ");
				i++;
			}
			if (f)
				return (1);
		}
	}
	printf("\n");
	return (1);
}

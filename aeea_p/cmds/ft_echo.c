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

int	check_forflag(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j] != NULL)
	{
		i = 0;
		if (s[j][0] != '-')
			return (j);
		i++;
		while (s[j][i] != '\0')
		{
			if (s[j][i] != 'n')
				return (j);
			i++;
		}
		j++;
	}
	return (j);
}

int	ft_echo_o(char **av)
{
	int	i;
	int	k;

	i = 1;
	if (av[i] != NULL)
	{
		if (*av != NULL)
		{
			k = check_forflag(&av[i]);
			while (k--)
				i++;
			while (av[i] != NULL)
			{
				printf("%s", av[i]);
				if (av[i + 1] != 0)
					printf(" ");
				i++;
			}
			if (check_forflag(&av[1]))
				return (1);
		}
	}
	printf("\n");
	return (1);
}

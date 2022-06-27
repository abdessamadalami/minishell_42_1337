/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:11:41 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/27 11:55:43 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	ft_echo_o(char **av)
{
	int	i;
	int	f;

	i = 0;
	if (*av != NULL)
	{
		f = check_forflag(*av);
		if (f)
			i++;
		while (av[i] != NULL)
		{
			printf("%s", av[i]);
			if (av[i + 1] != '\0')
				printf(" ");
			i++;
		}
		if (f)
			return ;
	}
	printf("\n");
}

// int	main(int ac, char **av)
// {
// 	ac = 1;
// 	ft_echo(&av[1]);
// }

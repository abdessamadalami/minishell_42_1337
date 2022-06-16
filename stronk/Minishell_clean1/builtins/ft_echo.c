/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:11:41 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/10 18:13:00 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_flag(int i, int *p)
{
	*p = i;
	if (i)
		return (1);
	return (0);
}

int	ft_check_arg(char **s, int *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != NULL)
	{
		j = 0;
		if (s[i][0] != '-')
			return (check_flag(i, p));
		j++;
		while (s[i][j] != '\0')
		{
			if (s[i][j] != 'n')
				return (check_flag(i, p));
			j++;
		}
		*p = i;
		i++;
	}
	if (i)
		return (1);
	return (0);
}

void	ft_echo(char **av, int x)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		printf("%s", av[i]);
		if (av[i + 1] != '\0')
			printf(" ");
		i++;
	}
	if (!x)
		printf("\n");
}

int	main(int ac, char **av)
{
	int	p;

	p = 0;
	if (ft_check_arg(*(&av) + 1, &p))
	{
		ft_echo(*(&av) + p + 1, 1);
	}
	else
		ft_echo(*(&av) + 1, 0);
	return (0);
}

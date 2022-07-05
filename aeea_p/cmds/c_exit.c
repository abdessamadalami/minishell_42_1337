/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 07:56:11 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/01 07:51:10 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../excuting_headr.h"

static int	index_fun(const char *nbr, int *s)
{
	int	i;

	i = 0;
	while (nbr[i] == ' ' || nbr[i] == '\t' || nbr[i] == '\v'
		|| nbr[i] == '\n' || nbr[i] == '\f' || nbr[i] == '\r')
		i++;
	if (nbr[i] == '+' || nbr[i] == '-' )
	{
		if (nbr[i] == '-')
			(*s) *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi_l(const char *nbr)
{
	int					i;
	unsigned long long	nb;
	int					s;

	nb = 0;
	s = 1;
	i = index_fun(nbr, &s);
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{			
		nb = nb * 10 + nbr[i] - '0';
		if (nb > 9223372036854775807)
			return (255);
		i++;
	}
	return ((nb * s) & 255);
}

int	ft_isnbr(char *str)
{
	int	index;

	index = 0;
	if (str[index] == '-')
		index++;
	while (str[index] != '\0')
	{
		if (!ft_isdigit(str[index]))
			exit(255);
		index++;
	}
	return (1);
}

void	c_exit(char **args)
{
	int	f;

	f = 0;
	if (args[1] == 0)
	{
		free_function(args);
		exit(0);
	}
	if (args[1] != 0)
	{
		if (ft_isnbr(args[1]))
		{
			if (args[2] != 0)
			{
				printf("exit: too many arguments\n");
				g_st = 1;
				return ;
			}
			f = ft_atoi_l(args[1]);
			free_function(args);
			exit(f);
		}
	}
}

//good work//? mini long long and negative number 
/*
	bash-3.2$ cat > file << ss
	> alami
	> elouali
	> ss
	bash-3.2$ cat file
	alami
	elouali
	bash-3.2$ 
*/
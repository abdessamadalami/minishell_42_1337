/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 07:56:11 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/01 11:55:20 by ael-oual         ###   ########.fr       */
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

int	ft_atoi(const char *nbr)
{
	int	i;
	int	nb;
	int	s;

	nb = 0;
	s = 1;
	i = index_fun(nbr, &s);
	while (nbr[i] >= '0' && nbr[i] <= '9' )
	{			
		nb = nb * 10 + nbr[i] - '0';
		i++;
	}
	return (nb * s);
}

void c_exit(char **args)
{
    int a;
    printf("_%s_ \n",args[1]);
    a = ft_atoi(args[1]) & 255;
    printf("a %d\n", a);
    ft_putstr_fd("exit\n",1);
    exit(a);
}//good work
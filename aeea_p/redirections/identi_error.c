/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identi_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:05:44 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/28 11:40:41 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

int	error_handling(char *str)
{
	int		i;
	char	s;

	i = 0;
	s = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (((!ft_isalnum(str[i])) && str[i] != '_' )
			|| (str[0] <= '9' && str[0] >= '0'))
		{
			e_st = 1;
			printf("error: `%s': not a valid identifier \n", str);// we need cmd
			return (1);
		}
		i++;
	}
	return (0);
}

int	error_handlin_g(char *str, int f)
{
	int		i;
	char	s;

	i = 0;
	s = 0;
	if (!str)
	    return (0);
	// if (str[0] <= '9' && str[0] >= '0')
	//if (str[0] == '$' && p == 0)  // for dolar handling
	//  i++;
	if (!f)
	{
		if (str[0] <= '9' && str[0] >= '0')
			return (0);
	}
	while (str[i])
	{
		if ((!ft_isalnum(str[i])) && str[i] != '_')
		{
			e_st = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

int	error_handling_e(char *str, int p)
{
	int		i;
	int		j;
	char	s;

	i = 0;
	s = 0;
	j = 0;
	if (str[p - 1] == '+')
		j++;
		str[p - j] = 0;
	if (!error_handlin_g(str, 0))
	{
		if (j == 0)
			str[p - j] = '=';
		else
			str[p - j] = '+';
		// printf(" _dd %c_", str[p]);
		printf("error: `%s': not a valid identifier \n", str);
		return (1);
	}
	return (0);
}

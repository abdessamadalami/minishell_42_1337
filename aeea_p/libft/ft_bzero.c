/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:34:19 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/04 11:23:59 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

// int main()
// {
//    char *tab;

//    tab = strdup("abdessamad alami SULTAN ALAMI ");
//     // bzero(tab,2);
//     //ft_bzero(tab,2);
// 	printf("%s\n",tab);
// 	system("leaks a.out");
// }

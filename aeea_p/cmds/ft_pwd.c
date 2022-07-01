/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:33:22 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/30 22:22:59 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

void	del(void *ptr)
{
	free(ptr);
}

void	ft_pwd(void)
{
	char	*ptr;

	ptr = getcwd(0, 0);
	printf("%s\n", ptr);
	free(ptr);
	ptr = 0;
}

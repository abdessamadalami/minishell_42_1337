/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:07:14 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/01 09:49:51 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "pipex_42_1337.h"

//int	ft_strncmp(char *s1, char *s2, unsigned int n)
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
/*
int main()
{
     printf(" %d  %d ",ft_strncmp("abè","abè",3),strncmp("abè","abè",3));

}
*/

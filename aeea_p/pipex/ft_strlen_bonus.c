/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:10:17 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/14 12:13:11 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "pipex_42_1337.h"
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include <string.h>
#include<sys/wait.h>

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	ptr = malloc((len + 1) * sizeof (char));
	if (ptr == NULL)
		return (0);
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int	chec_slash(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == 47)
			return (1);
	i++;
	}
	return (0);
}

char	*access_func(char **str)
{
	if (access(str[0], F_OK) == 0 && chec_slash(str[0]) != 0)
	{
		if (access(str[0], X_OK) == 0)
			return (ft_strdup(str[0]));
		else
		{
			perror(str[0]);
			free_function(str);
			exit(0);
		}
	}
	return (0);
}

void	error_print(char **str)
{
	ft_putstr_fd(str[0], 2);
	if (chec_slash(str[0]))
	{
		ft_putstr_fd(": no such file or directory\n", 2);
	}
	else
		ft_putstr_fd(": command not found\n", 2);
}

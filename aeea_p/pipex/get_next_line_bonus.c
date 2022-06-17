/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+
 *                                                #+#+#+   +#+           */
/*   Created: 2021/11/18 08:10:04 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/18 09:18:31 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_42_1337.h"

int	check_fun(char *s)
{
	int	index;

	if (!s)
		return (-1);
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

char	*line_remainder(char *src, int startindex)
{
	char	*tmp;
	char	*line;

	tmp = src;
	line = ft_strdup(src + startindex + 1);
	free(tmp);
	return (line);
}

char	*read_join(int fd, char *str, int *k)
{
	char	*ptr;

	*k = 1;
	ptr = malloc(2);
	while (check_fun(str) == -1 && *k != 0)
	{
		*k = read(fd, ptr, 1);
		if (*k == -1)
		{
			free(ptr);
			return (NULL);
		}
		ptr[*k] = '\0';
		str = ft_strjoin(str, ptr);
	}
	free(ptr);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	int			k;
	char		*line;
	int			index_line;

	
	str = read_join(fd, str, &k);
	if (str == NULL)
		return (0);
	if (ft_strlen(str) == 0 && k == 0)
	{
		free(str);
		str = NULL;
		return (0);
	}
	index_line = check_fun(str);
	if (index_line == -1)
	{
		line = str;
		str = (NULL);
		return (line);
	}
	line = ft_substr(str, 0, index_line + 1);
	str = line_remainder(str, index_line);
	return (line);
}

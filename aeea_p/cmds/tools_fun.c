/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:11:46 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/30 22:22:43 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

static char	*ft_strcat_p(char *dest, const char *src, int position)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (dest[i] != '\0' && position != 0)
		i++;
	while (src[len] != '\0')
	{
		dest[i] = src[len];
		i++;
		len++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_n(char *s1, char *s2)
{
	int		index;
	int		length;
	char	*ptr;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	index = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(length + 1);
	if (ptr == NULL)
		return (0);
	ft_strcat_p(ptr, s1, 0);
	ft_strcat_p(ptr, s2, 1);
	free(s1);
	free(s2);
	s1 = 0;
	s2 = 0;
	return (ptr);
}

void	*f(void *ptr)
{
	char	*ptr2;
	char	*s;
	int		i;

	if (ft_strchr(ptr, '=') != NULL)
	{
		i = ft_strchr(ptr, '=') - (char *)ptr;
		s = ft_strdup_n(ptr, i);
		ptr2 = ft_strrchr(ptr, '=') + 1;
		ptr2 = ft_strjoin_n(ft_strdup("\""), ft_strdup (ptr2));
		ptr2 = ft_strjoin_n(ptr2, ft_strdup("\""));
		ptr2 = ft_strjoin_n(ft_strjoin_n(s, ft_strdup("=")), ptr2);
		return (ptr2);
	}
	ptr2 = ft_strdup(ptr);
	return (ptr2);
}

int	check_redirec(char *red)
{
	if (red[0] == '>' && red[1] == 0)
		return (1);
	else if (red[0] == '<' && red[1] == 0)
		return (1);
	else if (red[0] == '>' && red[1] == '>' && red[3] == 0)
		return (1);
	return (0);
}

int	check_for_pipe(char *str)
{
	if (str[0] == '|' && str[1] == '\0')
		return (1);
	return (0);
}

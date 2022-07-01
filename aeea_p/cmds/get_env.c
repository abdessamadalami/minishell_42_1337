/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:16:51 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/01 09:23:39 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

// (a == 1)//for remplace
//(a == 2)// a= 2 for += var
//(a == 5)//for replace with out value
//(a == 5)//for replace with out value
//(a == 3)// for dolar

static char	*getenv_statment(int a, char *content, char *str, int len)
{
	char	*tem;

	if (a == 1)//for remplace
	{
		str[ft_strlen(str)] = '=';
		tem = content;
		content = ft_strdup(str);
		free(tem);
		tem = 0;
		return (str);
	}
	else if (a == 2)// a= 2 for += var
	{
		str[ft_strlen(str)] = '=';
		if (ft_strchr(content, '=') == NULL)
			len--;
		content = ft_strjoin(content, str + len + 1);
	}
	// else if (a == 5)//for replace with out value
	// 	content = ft_strdup(str);
	else if (a == 3)// for dolar
		return (content + len + 1);
	return (content);
}

char	*ft_getenv(t_list *list, char *str, int a)
{
	int		len;
	char	*ptr;

	while (list)
	{
		len = ft_strlen(str);
		ptr = (char *)list -> content;
		if ((ft_strncmp(str, ptr, len)) == 0)
		{
			list->content = getenv_statment(a, list->content, str, len);
			return (list->content);
		}
		list = list->next;
	}
	return (0);
}

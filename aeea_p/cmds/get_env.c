/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:16:51 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/01 23:21:19 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

// (a == 1)//for remplace
//(a == 2)// a= 2 for += var
//(a == 5)//for replace with out value
//(a == 5)//for replace with out value
//(a == 3)// for dolar
/*
	tem = content;
	content = ft_strdup(str);
	free(tem);
	free(content);
	tem = 0;
	the first if is for a=1: /for remplace // look up
	the second if for add a=2  a= 2 for += var
	the third id for // for dolar
*/
static char	*getenv_statment(int a, char *content, char *str, int len)
{
	char	*tem;

	if (a == 1)
	{
		str[ft_strlen(str)] = '=';
		free(content);
		return (str);
	}
	else if (a == 2)
	{
		str[ft_strlen(str)] = '=';
		if (ft_strchr(content, '=') == NULL)
			len--;
		tem = content;
		content = ft_strjoin(content, str + len + 1);
		free(tem);
		free(str);
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:39:36 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/28 17:19:11 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../excuting_headr.h"

char	*get_path_env(t_list *env, char *cmd)
{
	int		i;
	char	*str;
	char	*ptr;
	char	**str1;
	char    *ptr2;

	i = 0;
	ptr2 = ft_getenv(env, "PATH", 0);
	if (ptr2 == NULL)
		return 0;
	str1 = ft_split(ptr2, ':');
	while (str1[i] != 0)
	{
		str = str1[i];
		str1[i] = ft_strjoin(str1[i], "/");
		free (str);
		ptr = ft_strjoin(str1[i], cmd);
		if (access(ptr, 0) != 0)
		{
			free(ptr);
			ptr = 0;
		}
		else
			break;
		i++;
	}
	free_function(str1);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_remplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:22:02 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/02 20:01:21 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"
#include <stdio.h>
#include <string.h>

char	*bezero_seprateur(char *str)
{
	int		index;
	char	*ptr;

	index = 0;
	ptr = 0;
	while (str[index])
	{
		if (!ft_isalnum(str[index]) && str[index] != '_')
		{
			ptr = ft_strdup(str + index);
			str[index] = '\0';
			break ;
		}
		index++;
	}
	return (ptr);
}
/*
char	*env_var(char *arg, t_list **env, int a)
{
	char	*check_d;
	char	**do_str;
	char	*new_arg;
	char	*s;
	int		i;

	a = 0;
	i = 0;
	s = 0;
	do_str = NULL;
	check_d = strchr(arg, '$');
	if (check_d == NULL)
		return (NULL);
	if (check_d != NULL && check_d - arg != 0)
		s = ft_strdup_n(arg, check_d - arg);
	if (check_d != NULL)
		do_str = ft_split(check_d, '$');
	while (do_str[i])
	{
		check_d = bezero_seprateur(do_str[i]);
		new_arg = ft_getenv(*env, do_str[i], 3);
		if (new_arg)
			s = ft_strjoin(s, new_arg);
		if (check_d != NULL)
			s = ft_strjoin(s, check_d);
		i++;
		free(check_d);
	}
	return (s);
}
*/
// int main(int argc, char *argv[], char **env)
// {
//   printf(" %s ", env_var("$var",env));
//   perror("><<");
// }
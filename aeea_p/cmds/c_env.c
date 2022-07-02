/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:53:11 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/21 19:19:25 by sultan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

// this is the environment for cmd env and for the current prossece 
t_list	*env_list(char **env)
{
	int		index;
	t_list	*list;
	t_list	*node;

	index = 0;
	list = 0;
	while (env[index] != NULL)
	{
		node = ft_lstnew(ft_strdup(env[index]));
		ft_lstadd_back(&list, node);
		index++;
	}
	return (list);
}

t_list	*c_env(char **env)
{
	return (env_list(env));
}

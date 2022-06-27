/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:41:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/16 20:46:32 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ftlstclear(t_arg **lst, void (*del)(void	*))
{
	t_arg	*list;

	list = *lst;
	while (*lst != NULL)
	{
		*lst = list->next;
		del(list->data);
		free(list);
		list = *lst;
	}
}

int	main(int ac, char **av)
{
	char	*s;
	t_arg	*mr;

	mr = NULL;
	(void)*av;
	if (ac == 1)
	{
		while (1)
		{
			s = readline("$>prompt ");
			if (!s)
				break ;
			if (s[0] == '\0')
				continue ;
			mr = ft_parsing(s);
			if (mr != NULL)
				add_history(s);
			// while (mr != NULL)
			// {
			// 	printf("--[%s\n", mr->data);
			// 	mr = mr->next;
			// }
			ftlstclear(&mr, free);
			free(s);
			// system("leaks minishell");
		}
		return (0);
	}
}

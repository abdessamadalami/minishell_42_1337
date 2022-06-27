/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:41:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/26 16:13:57 by ael-oual         ###   ########.fr       */
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
// void merge(t_arg *pa, char **env)
// {
// 	t_list *list;
// 	t_list *node;
// 	t_list *env_lst;

// 	list = 0;
// 	node = 0;
// 	env_lst = c_env(env);
// 	while (pa)
// 	{
// 		node =  ft_lstnew(ft_strdup(pa->data));
// 		ft_lstadd_back(&list, node);
// 		//printf(" %s ", node -> content);
// 		pa = pa->next;
// 	}
// 	//executing(list, &env_lst);
// 	executing(list,&env_lst);
// }

int	main(int ac, char **av, char **env)
{
	char	*s;
	t_arg	*mr;

	mr = NULL;
	(void)*av;
	if (ac == 1)
	{
		while (1)
		{
			s = readline("\e[0;32m$>prompt \e[0m");
			if (!s)
				break ;
			if (s[0] == '\0')
				continue ;
			mr = ft_parsing(s);
			//exit(0);
			//merge(mr, env);
			if (mr != NULL)
				add_history(s);
			while (mr != NULL)
			{
				printf("--[%s\n", mr->data);
				mr = mr->next;
			}
			ftlstclear(&mr, free);
			free(s);
		}
		return (0);
	}
}

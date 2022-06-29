/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:41:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/28 23:47:37 by sultan           ###   ########.fr       */
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

void handler_sig(int sig)
{
	if (sig == SIGINT)
    {
        // rl_on_new_line();
        // rl_replace_line("", 0);
        // rl_redisplay();
    }
}

void	merge(t_arg *pa, t_list *env)
{
	t_list	*list;
	t_list	*node;
	

	list = 0;
	node = 0;
	while (pa)
	{
		node = ft_lstnew(ft_strdup(pa->data));
		ft_lstadd_back(&list, node);
		//printf(" %s ", node -> content);
		pa = pa->next;
	}
	//executing(list, &env_lst);
	executing(list, &env);
}

int	main(int ac, char **av, char **env)
{
	char	*s;
	t_arg	*mr;
	t_list	*env_lst;
	
	
    c.sa_handler = &handler_sig;
    c.sa_flags = SA_RESTART;
	sigaction(SIGINT, &c, 0);
	mr = NULL;
	(void)*av;
	env_lst = c_env(env);
	if (ac == 1)
	{
		while (1)
		{
			s = readline("$>prompt ");
			if (!s)
				break ;
			if (s[0] == '\0')
				continue ;
			mr = ft_parsing(s, env_lst);
			if (mr != NULL)
				merge(mr,env_lst);
			add_history(s);
			// while (mr != NULL)
			// {
			// 	printf("--[%s\n", mr->data);
			// 	mr = mr->next;
			// }
			ftlstclear(&mr, free);
			free(s);
			//system("leaks minishell");
		}
		return (0);
	}
}

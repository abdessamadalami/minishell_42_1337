/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:41:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/07/01 23:20:53 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_sig(int sig)
{
	if (e_st == 1)
	{
		e_st = 1337;
		close(0);
	}
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
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
		pa = pa->next;
	}
	executing(list, &env);
	ft_lstclear(&list, del);
}

void	sigg(void)
{
	struct sigaction	c;

	c.sa_handler = &handler_sig;
	c.sa_flags = SA_RESTART;
	sigaction(SIGINT, &c, 0);
	sigaction(SIGQUIT, &c, 0);
}

void	ft_freelistands(t_arg *mr, char *s)
{
	ftlstclear(&mr, free);
	free(s);
}

int	main(int ac, char **av, char **env)
{
	char				*s;
	t_arg				*mr;
	t_list				*env_lst;

	mr = NULL;
	(void)*av;
	sigg();
	env_lst = c_env(env);
	if (ac == 1)
	{
		while (1)
		{
			s = readline("$>prompt ");
			if (!s)
				break ;
			if (!check_s(s))
				continue ;
			mr = ft_parsing(s, env_lst);
			// system("leaks minishell");
			// exit(1);
			if (mr != NULL)
				merge(mr, env_lst);
			add_history(s);
			ft_freelistands(mr, s);
		}
	}
	return (0);
}

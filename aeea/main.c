/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:52:46 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/29 19:11:39 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "excuting_headr.h"
//#include "../stronk/minishell.h"

static void header_inline(char *s, t_list *env)
{
	exit(0);
//	s = ft_strdup("dkfkfkf");
}
void handler_sig(int sig)
{
	if (sig == SIGINT)
    {
        printf("\n");
        // rl_on_new_line();
        // rl_replace_line("", 0);
        // rl_redisplay();
    }
}


int main(int argc, char **argv, char **env)
{	
    t_list *env_lst;
	t_list *par;
	int exit_s;
	int id;
	struct sigaction c;
   	static int x;
	
    c.sa_handler = &handler_sig;
    c.sa_flags = SA_RESTART;
	char	*s;
	env_lst = c_env(env);
	sigaction(SIGINT, &c, NULL);
	while (1)
	{
		//list = ft_new_parsing(s);
		s = readline("$>prompt ");
		printf("_________(%s)________\n", s);
		if (s == 0)
			header_inline(s, env_lst);
		if (ft_strlen(s) != 0)
		{
			par = c_env(ft_split(s, ' '));
			executing(par ,env_lst);
		}
		add_history(s);
	}
	return (0);
	}

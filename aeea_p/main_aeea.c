/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_aeea.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:52:46 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/26 18:05:45 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "excuting_headr.h"
//#include "../stronk/minishell.h"

static void header_inline(char *s, t_list *env)
{  
	printf("\n");
	exit(e_st);
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
	char **str;

	str = 0;
	s = 0;
	env_lst = c_env(env);
	sigaction(SIGINT, &c, 0);
	while (1)
	{
		//list = ft_new_parsing(s);
		// printf("\033[1;33m");
		s = readline("\e[0;32m$>prompt \e[0m");
		//printf("_________(%s)________\n", s);
		if (s == 0)
			header_inline(s, env_lst);
		if (ft_strlen(s) != 0)
		{
			str = ft_split(s, ' ');
			par = c_env(str);
			// exit(0);
			executing(par, &env_lst);
			system("leaks minishell.a");
		}
		add_history(s);
		str = 0;
		free(s);
		s = 0;
	}
	printf("\033[13m");
	return (0);
}

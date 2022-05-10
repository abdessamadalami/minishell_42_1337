/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:41:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/10 13:26:18 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_arg(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av, char **env)
{
	char	*s;
	t_cmd	cmds;

	(void)*av;
	if (ac == 1)
	{
		while ((s = readline("$>prompt ")) != 0)
		{
			if (!ft_parsing(&cmds, s, env))
				return (0);
			// printf("$%s$\n", s);
			// if (ft_arg(s,"echo"))
			// {
				
			//	s = readline(">");
			//	ft_exec(av, );
			//	ft_echo(s, env);
			//	if (execve(s, cmd, envp) == -1)
			//		return (0);
			// }
			//	printf("this is echo\n");
			add_history(s);
			
		//	printf(">minishell$");
			
			
		//	if (s)
		//		add_history(s);
		//	readline(av[1]);
		//	if (ft_arg(av[1], "echo"))
		//		ft_echo();

		}
		return (0);
		
	}
	
}

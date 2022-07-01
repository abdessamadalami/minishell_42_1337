/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:34:28 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/01 17:10:40 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"
#include "../../minishell.h"
// read from  here_doc to fd (we can choise between write to pipe or file or terminal) here is to pipe
int    ft_strcmpp(char *s1, char *s2)
{
    int    i;

    i = -1;
    while (s1[++i] && s2[i] && s1[i] == s2[i])
        ;
    return (s1[i] + s2[i]);
}
static int	here(int *pi_pe)
{
	
	// if (e_st == 1337)
	// {
	// 	close(pi_pe[0]);
	// 	close(pi_pe[1]);
	// 	e_st = 1;
	// 	return (1337);
	// }
	close(pi_pe[1]);
	//system("leaks minishell");
	return (pi_pe[0]);
}

int	here_doc(char *lim, t_list *env)
{
	char	*line;
	int		pi_pe[2];

	env = 0;
	pipe(pi_pe);
	line = 0;
	while (1)
	{
		e_st = 1;
		line = readline("> ");//signels
		if (e_st == 1337)
			return 1337;
		if (line == 0)
		{
			printf("\n");
			break ;
		}
		if (ft_strcmpp(lim, line) == 0)
			break ;
		line =ft_strjoin_n(line,ft_strdup("\n"));
		ft_putstr_fd(line, pi_pe[1]);
		free(line);	
	}
	// line = 0;
	//printf("%p \n", lim);
	free(line);
	return (here(pi_pe));
}

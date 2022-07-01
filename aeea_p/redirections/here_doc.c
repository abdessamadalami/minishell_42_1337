/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:34:28 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/30 19:59:28 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"
#include "../../minishell.h"
// read from  here_doc to fd (we can choise between write to pipe or file or terminal) here is to pipe
static int	here(int *pi_pe, char *line)
{
	if (e_st == 1337)
	{
		close(pi_pe[0]);
		close(pi_pe[1]);
		free(line);
		e_st = 1;
		return (1337);
	}
	free(line);
	close(pi_pe[1]);
	return (pi_pe[0]);
}

int	here_doc(char *lim, t_list *env)
{
	char	*line;
	int		pi_pe[2];

	env = 0;
	pipe(pi_pe);
	lim = ft_strjoin(lim, "\n");
	while (1 && e_st != 1337)
	{
		e_st = 1;
		line = readline("> ");//signels
		if (line == 0)
		{
			printf("\n");
			break ;
		}
		line = ft_strjoin_n(line, ft_strdup("\n"));
		if (ft_strncmp(lim, line, ft_strlen(lim)) == 0)
			break ;
		ft_putstr_fd(line, pi_pe[1]);
		free(line);
	}
	free(lim);
	return (here(pi_pe, line));
}

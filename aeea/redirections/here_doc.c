/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:34:28 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/05 14:26:51 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"
// read from  here_doc to fd (we can choise between write to pipe or file or terminal) here is to pipe
void	here_doc(char *lim, t_list *env)
{
	char	*line;
	char	*limtter;
	int		pi_pe[2];

	pipe(pi_pe);
	limtter = ft_strjoin(lim, "\n");
	printf(" %s \n",limtter);
	while (1)
	{
		 
		ft_putstr_fd("here_doc> ", 1);
		line = get_next_line(0);
		if (line == 0 || ft_strncmp(limtter, line, ft_strlen(limtter)) == 0)
			break ;
		if (env_var(line, &env , 2))
			line = env_var(line, &env , 2);
		ft_putstr_fd(line, pi_pe[1]);
	}
	free(limtter);
	free(line);
	close(pi_pe[1]);
	dup2(pi_pe[0],0);
}

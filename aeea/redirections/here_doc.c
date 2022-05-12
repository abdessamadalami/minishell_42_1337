/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:34:28 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/11 19:46:48 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// read from  here_doc to fd (we can choise between write to pipe or file or terminal) here is to pipe
void	here_doc(char **argc)
{
	char	*line;
	char	*limtter;
	int		pi_pe[2];

	pipe(pi_pe);
	limtter = ft_strjoin(argc[2], "\n");
	while (1)
	{
		ft_putstr_fd("pipe here_doc> ", 2);
		line = get_next_line(0);
		if (line == 0 || ft_strncmp(limtter, line, ft_strlen(limtter)) == 0)
			break ;
		ft_putstr_fd(line, pi_pe[1]);
	}
	free(limtter);
	free(line);
	close(pi_pe[1]);
}
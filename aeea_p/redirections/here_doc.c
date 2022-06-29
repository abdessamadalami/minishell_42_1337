/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:34:28 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/29 18:05:45 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"
// read from  here_doc to fd (we can choise between write to pipe or file or terminal) here is to pipe

int	here_doc(char *lim, t_list *env)
{
	char	*line;
	char	*limtter;
	int		pi_pe[2];

	pipe(pi_pe);
	limtter = ft_strjoin(lim, "\n");
	while (1)
	{
		line = readline("> ");//signels
		if (line == 0 || ft_strncmp(limtter, line, ft_strlen(limtter)) == 0)
			break ;
		if (env_var(line, &env, 2))
			line = env_var(line, &env, 2);
		ft_putstr_fd(line, pi_pe[1]);
	}
	free(limtter);
	free(line);
	close(pi_pe[1]);
	return (pi_pe[0]);
}

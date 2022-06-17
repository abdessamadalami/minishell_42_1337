/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 07:56:01 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/19 11:19:45 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_42_1337.h"

void	here_doc_function(int argv, char **argc, char **env)
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
	pipex_42(argv, argc, env, pi_pe[0]);
}

// int	main(int argv, char **argc, char **env)
// {
// 	int	file;
// 	int	i;

// 	i = 0;
// 	file = 0;
// 	if ((ft_strncmp(argc[1], "here_doc", 9) == 0 && argv < 6))
// 	{
// 		write(1, "Error\n", 6);
// 		exit(0);
// 	}
// 	if (ft_strncmp(argc[1], "here_doc", 9) == 0)
// 	{			
// 		here_doc_function(argv, argc, env);
// 		return (1);
// 	}
// 	pipex_42(argv, argc, env, file);
// 	return (0);
// }

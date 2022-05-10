/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:44:15 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/10 16:34:58 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    output_in(char **env,char **cmd)
{
    
}

int main(int argc, char **argv , char **env)
{
    char	*line;
	char	**split;
    char	**envig;
	int		pi_pe[2];
    char *path;

	while (1)
	{
		ft_putstr_fd("read for > ", 2);
		line = get_next_line(0);
        break ;
	}
    line[ft_strlen(line) - 1] = 0;
    int index_of = ft_strchr(line, '<') - line;
    printf(" %d ", index_of);
    split = ft_split(line, ' ');
    envig = ft_split(path, ' ');
    path = get_path(env, split[0]);
    if(path == NULL)
        error_print(split);
    
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:10:10 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/06 07:12:09 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

void redirect_input(char *std_in)
{
	int fd_input;
	int pid;

	fd_input = open(std_in, O_RDONLY);
	if (fd_input == -1)
	{
		perror(std_in); // chmod error 
		exit(1);// exit just the child you must check if a pipe exists or no
	}
    dup2(fd_input,0);
}

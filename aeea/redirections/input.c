/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:10:10 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/07 12:11:37 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

int redirect_input(char *std_in)
{
	int fd_input;

	fd_input = open(std_in, O_RDONLY);
	printf("jfjfjfjfj\n");
	if (fd_input == -1)
		perror(std_in);
	return (fd_input);	
}

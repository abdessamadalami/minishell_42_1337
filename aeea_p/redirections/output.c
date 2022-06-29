/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:08:30 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/29 18:15:02 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

int	redirect_output(char *std_out, char c)
{
	int	fd_input;

	fd_input = 0;
	if (c == 'r')
		fd_input = open(std_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (c == 'a')
		fd_input = open(std_out, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd_input == -1)
	{
		perror(std_out);
	}
	return (fd_input);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:08:30 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/26 11:06:46 by sultan           ###   ########.fr       */
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
		perror(std_out);// chmod error for w permission
		//exit(1);// exit just the child you must check if a pipe exists or no
	}
	return (fd_input);
}

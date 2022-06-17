/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_redirections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:21:34 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/11 12:47:56 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

/*
red string is about the signed of redirections signed : < or > or << or >> 
std_in is path name  of input file : read from pipe or stdin of file 
std_out is path name of output file : file or stdout
*/
int g_redirections(char *f_name,char *red, t_list *env,int *std_in, int *std_out)
{
    //check_file_name();
    int fd_file;/// fd_file  for this < we need the fd of the file after < 
    if (red[0] == '>' && red[1] == 0)
    {
        *std_out = redirect_output(f_name, 'r');
        return (*std_out);
    }
    else if (red[0] == '<' && red[1] == 0)
    {
        *std_in = redirect_input(f_name);
        if (*std_in == -1)
        return(*std_in);
    }
	else if (red[0] == '>' && red[1] == '>' && red[3] == 0)
    {
         *std_out = redirect_output(f_name, 'a');
        return (*std_out);
    }
    return 0;
}


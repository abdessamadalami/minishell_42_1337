/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_redirections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:21:34 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/10 16:48:48 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void redirect_output(int std_out)
{
    dup2(std_out,1);
}
// red string is about the signed of redirections signed : < or > or << or >> 
// std_in is file descriptor of input file : read from pipe or stdin of file 
// std_out is file descriptor of output file : file or stdout
void g_redirections()
{
    int std_in;
    int std_out;
    char *red = "<";
    int fd_file;/// fd_file  for this < we need the fd of the file after < 
    if (red[0] == '>' && red[1] == 0)
    {
        dup2(std_out,1);
    }
    else if (red[0] == '<' && red[1] == 0)
    {
        
        dup2(fd_file,0);
    }
    
    

}
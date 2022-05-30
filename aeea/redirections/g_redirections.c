/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_redirections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:21:34 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/21 15:36:26 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

/*
red string is about the signed of redirections signed : < or > or << or >> 
std_in is path name  of input file : read from pipe or stdin of file 
std_out is path name of output file : file or stdout
*/
void g_redirections(char *f_name,char *red)
{
    //check_file_name();
    int fd_file;/// fd_file  for this < we need the fd of the file after < 
    if (red[0] == '>' && red[1] == 0)
        redirect_output(f_name, 'r');
    else if (red[0] == '<' && red[1] == 0)
        redirect_input(f_name);
    else if (red[0] == '<' && red[1] == '<' && red[2] == 0)
        here_doc(f_name);//read from here_doc 
	else if (red[0] == '>' && red[1] == '>' && red[3] == 0)
        redirect_output(f_name, 'a');// add the std in to a file
	//execve(cmd,eng,env);// if this cmd is exists n: zsh is not bash a big deffirent here 
}


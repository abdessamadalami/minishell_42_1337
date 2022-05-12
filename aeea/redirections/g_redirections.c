/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_redirections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:21:34 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/12 08:31:13 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void redirect_output(char *std_out, char c)
{
	int fd_input;
	if (c == 'r')
		fd_input = open(std_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (c == 'a')
		fd_input = open(std_out, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd_input == -1)
	{
		perror(std_out); // chmod error for w permission
		exit(1);// exit just the child you must check if a pipe exists or no
	}
	dup2(fd_input,1);
}

void redirect_input(char *std_in)
{
	int fd_input;

	fd_input = open(std_in, O_RDONLY);
	if (fd_input == -1)
	{
		perror(std_in); // chmod error 
		exit(1);// exit just the child you must check if a pipe exists or no
	}
    dup2(fd_input,0);
}

void	here_doc(char **argc)
{
	char	*line;
	char	*limtter;
	int		pi_pe[2];

	pipe(pi_pe);
	limtter = ft_strjoin(argc[0], "\n");
	printf("%s\n", limtter);
	while (1)
	{
		ft_putstr_fd("here_doc> ", 2);
		line = get_next_line(0);
		if (line == 0 || ft_strncmp(limtter, line, ft_strlen(limtter)) == 0)
			break ;
		ft_putstr_fd(line, pi_pe[1]);
	}
	free(limtter);
	free(line);
	close(pi_pe[1]);
	dup2(pi_pe[0],0);
	// read from pipe
}
/*
red string is about the signed of redirections signed : < or > or << or >> 
std_in is path name  of input file : read from pipe or stdin of file 
std_out is path name of output file : file or stdout
*/
void g_redirections(char *cmd,char **eng,char **env,char *red)
{
	
	char *f_name = "file";

    int fd_file;/// fd_file  for this < we need the fd of the file after < 
    if (red[0] == '>' && red[1] == 0)
        redirect_output(f_name, 'r');
    else if (red[0] == '<' && red[1] == 0)
        redirect_input(f_name);
    else if (red[0] == '<' && red[1] == '<' && red[2] == 0)
        here_doc(eng);//read from here_doc 
	else if (red[0] == '>' && red[1] =='>' && red[3] == 0)
        redirect_output(f_name, 'a');// add the std in to a file
	execve(cmd,eng,env);// if this cmd is exists n: zsh is not bash a big deffirent here 
}

/*
int main(int argc, char **argv,char **env)
{
	//redirect_output("file", 'r');
	char *cmd = "/usr/bin/head";
	char *eng[5];
	eng[0] = "head";
	eng[1] = "-3";
	eng[2] = "file";
	eng[3] = "minishell.h";
	eng[4] = 0;
	g_redirections(cmd, eng, env, "<<");
	//redirect_input("file");
	//redirect_output("file", 'r');
}
*/
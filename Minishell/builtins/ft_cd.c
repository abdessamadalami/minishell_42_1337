/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:29:43 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/28 20:01:48 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(char *path)
{
	char	*h;
	h = malloc(sizeof(char)*999);
	char	*s;
	s = malloc(sizeof(char)*999);
	char	*gg;
	gg = malloc(sizeof(char)*999);
	if (!path)
	{
		//  HOME
		h = getenv("HOME");
		printf("home %s\n", h);
		chdir(h);
	}
	else
	{
		// LSS9 AV M3A PWD
		getcwd(h, 1000);
	//	printf("dakchi %s\n", h);
	//	printf("av %s\n", path);
		gg = ft_strjn(h,path);
	//	printf("gg %s\n", gg);
		chdir(gg);
	}
//	free(h);
//	free(gg);
	//	A path is absolute if the first character is a /; otherwise, it's a relative path.

	//		/ 

	
/*	if (!s[1] || s[1][0] == '~' || s[1][0] == ' ' || s[1][0] == '\0')
	{
		// HOME
	}
	else
	{
		// path
	}*/
//	printf("path %s\n", path);
//	chdir(path);
//	printf("new path %s", path);
}

int main(int ac, char **av)
{
	char	*s;

	s = malloc(sizeof(char));
	
	printf("%s\n", getcwd(s, 1000));
	ft_cd(av[1]);
	printf("%s\n", getcwd(s, 1000));
	// printf("%s", getenv("PATH"));
}
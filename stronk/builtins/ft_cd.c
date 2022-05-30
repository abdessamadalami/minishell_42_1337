/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:29:43 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/26 14:39:23 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(char *path)
{
/*	if (!s[1] || s[1][0] == '~' || s[1][0] == ' ' || s[1][0] == '\0')
	{
		// HOME
	}
	else
	{
		// path
	}*/
//	printf("path %s\n", path);
	chdir(path);
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
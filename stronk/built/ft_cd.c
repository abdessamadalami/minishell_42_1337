/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:29:43 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/10 19:14:48 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(char *path)
{
	chdir(path);
}

int main()
{
	char	*s;

	s = malloc(sizeof(char));
	printf("%s\n", getcwd(s, 1000));
	ft_cd("commands");
	printf("%s\n", getcwd(s, 1000));
	// printf("%s", getenv("PATH"));
}
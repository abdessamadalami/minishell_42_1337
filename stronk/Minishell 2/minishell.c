/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:41:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/16 20:46:32 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_arg(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*s;
	t_arg	*mr;

	mr = malloc(sizeof(t_arg));
	if (!mr)
		exit(1);
	(void)*av;
	if (ac == 1)
	{
		while (1)
		{
			s = readline("$>prompt ");
			if (!s)
				break ;
			if (s[0] == '\0')
				continue ;
			mr = ft_parsing(s);
			while (mr != NULL)
			{
				printf("--[%s\n", mr->data);
				mr = mr->next;
			}
			add_history(s);
			while (mr != NULL)
			{
				free(mr->data);
				mr = mr->next;
			}
		}
		return (0);
	}
}

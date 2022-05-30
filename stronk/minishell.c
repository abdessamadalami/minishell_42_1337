/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:41:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/25 15:25:08 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include"../aeea/excuting_headr.h"

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

int main(int ac, char **av, char **env)
{
	char	*s;
	t_list *list;

	(void)*av;
	(void)*env;
	if (ac == 1)
	{
		while ((s = readline("$>prompt ")) != 0)
		{
			list = ft_new_parsing(s);
			add_history(s);

		}
		return (0);
		
	}
	
}

//char **envg[3][2]; > >> < << |> |<
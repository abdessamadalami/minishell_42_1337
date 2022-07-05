/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:11:30 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/02 20:02:33 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

static void	str_f(char **str, char *content)
{
	*str = ft_strjoin_n(*str, ft_strdup(content));
	*str = ft_strjoin_n(*str, ft_strdup(" "));
}

static int	statment_f(t_var1 *nor, char *content, t_list *env, t_list **list)
{
	env = 0;
	if (ft_strncmp(content, "-la", 4) != 0 && !nor->gg)
		nor->bol2 = 1;
	if (content[0] == '.' && nor->bol2)
	{
		*list = (*list)->next;
		return (-13);
	}
	if (check_for_pipe(content))
		return (1);
	return (0);
}

static char	**sp_str(char *str)
{
	char	**argv;

	argv = ft_split(str, ' ');
	free(str);
	str = 0;
	return (argv);
}

void	init_var(t_var1 *nor)
{
	nor->str = 0;
	nor->bol = 1;
	nor->bol2 = 0;
	nor->gg = 0;
}

char	**make_argv(t_list *list, t_list *env, int *std_in, int *std_out)
{
	t_var1	nor;

	init_var(&nor);
	while (list)
	{
		if (ft_strncmp(list->content, "cd", 3) == 0)
			nor.gg = 1;
		nor.rturnv = statment_f(&nor, list->content, env, &list);
		if (nor.rturnv == -13)
			continue ;
		else if (nor.rturnv == 1)
			break ;
		if (check_redirec(list ->content))
		{
			redir(&list, &nor.bol, std_in, std_out);
			if (list == 0 || *std_in == -1)
				break ;
		}
		else
			nor.bol = 1;
		if (nor.bol == 1)
			str_f(&nor.str, list->content);
		list = list -> next;
	}
	return (sp_str(nor.str));
}

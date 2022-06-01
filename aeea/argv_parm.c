/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:11:30 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/31 20:22:59 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "excuting_headr.h"



static int redir(t_list **list,int *bol, t_list *env)
{
    g_redirections((*list)->next->content, (*list)->content,env);
    if ((*list)->next->next == NULL)
        return (0);
    else
        *list = (*list)->next;
    *bol = 0;
    return (1);
}

char  **make_argv(t_list *list, t_list *env)
{
	char *str;
	char **argv;
	int bol;

	str = 0;
	argv = 0;
	bol = 1;
	while (list)
	{
		if(ft_strncmp(list ->content,"$?\0",4) == 0)
			list ->content = ft_itoa(e_st);
		if(env_var(list ->content, &env ,0) && ft_strncmp(list ->content,"$?\0",4))// for dollar sign
			list -> content = env_var(list ->content, &env ,3);
		if (check_for_pipe(list ->content))
				break;
		if (check_redirec(list ->content)) 
		{ 			
			if(redir(&list, &bol, env) == 0)
				break;
		}
        else
			bol = 1;
		if (bol == 1)
		{
			str = ft_strjoin(str, list->content);
			str = ft_strjoin(str, " ");
		}
		list = list -> next;
	}
	argv = ft_split(str, ' ');
	return (argv);
}

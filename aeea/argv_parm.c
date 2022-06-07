/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:11:30 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/07 12:05:38 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "excuting_headr.h"

static int redir(t_list **list,int *bol, t_list *env)
{
	int fd;// just test for 

	
	fd  = g_redirections((*list)->next->content, (*list)->content,env);
    if(fd == -1)
		return -1;
	dup2(fd,0);
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
	int k;

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
			k = redir(&list, &bol, env);
			if(k == 0)
				break;//!why
			else if(k == -1)
				return 0;
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

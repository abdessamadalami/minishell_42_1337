/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:11:30 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/16 13:48:38 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

static int redir(t_list **list,int *bol, t_list *env, int *std_in, int *std_out)
{
	int fd;// just test for 

	 fd = g_redirections((*list)->next->content, (*list)->content,env, std_in, std_out);
    if(fd == -1)
		return -1;
    if ((*list)->next->next == NULL)
	{
		 *list = 0;
        return (2);
	}
    else
        *list = (*list)->next;
    *bol = 0;
	
    return (1);
}

char  **make_argv(t_list *list, t_list *env, int *std_in,int *std_out)
{
	char *str;
	char **argv;
	int bol;
	char *temp;
	t_list *node;

	str = 0;
	argv = 0;
	bol = 1;
	node = list;
	while (list)
	{
		if(ft_strncmp(list ->content,"$?\0",4) == 0)
			list ->content = ft_itoa(e_st);
		if(env_var(list ->content, &env ,0) && ft_strncmp(list ->content,"$?\0",4))// for dollar sign
			list -> content = env_var(list ->content, &env ,3);
		if (check_for_pipe(list ->content))
			break;
		if (check_redirec(list ->content)) // good idea abou 
		{
			redir(&list, &bol, env ,std_in, std_out);
			if (list == NULL || *std_in == -1)
				break;
		}
		else
			bol = 1;
		if (bol == 1)
		{
			str = ft_strjoin_n(str, list->content);
			str = ft_strjoin_n(str, ft_strdup(" "));
			temp = 0;
		}
		list = list -> next;//about k we need to delete if
	}
	argv = ft_split(str, ' ');
	free(str);
	 str = 0;
	//ft_lstclear(&node,del);
	return (argv);
}
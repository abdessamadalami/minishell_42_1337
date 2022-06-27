/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:11:30 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/27 13:43:45 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

static int redir(t_list **list,int *bol, int *std_in, int *std_out)
{
	int fd;// just test for 

	 fd = g_redirections((*list)->next->content, (*list)->content, std_in, std_out);
    if(fd == -1)
		return (-1);
    if ((*list)->next->next == 0)
	{
		 *list = 0;
        return (2);
	}
    else
        *list = (*list)->next;
    *bol = 0;
    return (1);
}

static void str_f(char **str, char *content)
{
	*str = ft_strjoin_n(*str, content);
	*str = ft_strjoin_n(*str, ft_strdup(" "));
}

static int statment_f(char *content, t_list *env)
{
	//char *ptr;
	if (env_var(content, &env, 0) && ft_strncmp(content, "$?\0", 4))// for dollar sign
		content = env_var(content, &env, 3);
	if (check_for_pipe(content))
		return (1);
	return (0);
}
		// if(ft_strncmp(list ->content,"$?\0",4) == 0)
		// 	list ->content = ft_itoa(e_st);
		// if(env_var(list ->content, &env ,0) && ft_strncmp(list ->content,"$?\0",4))// for dollar sign
		// 	list -> content = env_var(list ->content, &env ,3);
		// if (check_for_pipe(list ->content))
		// 	break;

static char **sp_str(char *str)
{
	char **argv;
	
	argv = ft_split(str, ' ');
	free(str);
	str = 0;
	//print_tab(argv);
	return (argv);
}

char  **make_argv(t_list *list, t_list *env, int *std_in,int *std_out)
{
	char	*str;
	int		bol;

	str = 0;
	bol = 1;
	while (list)
	{
		if (statment_f(list->content, env))
				break ;
		if (check_redirec(list ->content)) // good idea abou 
		{
			redir(&list, &bol, std_in, std_out);
			if (list == 0 || *std_in == -1)
				break ;
		}
		else
			bol = 1;
		if (bol == 1)
			str_f(&str, list -> content);
		list = list -> next;
	}
	return (sp_str(str));
}
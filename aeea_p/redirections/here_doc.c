/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:34:28 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/01 23:23:05 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"
#include "../../minishell.h"

/*read from  here_doc to fd (we can choise between write to pipe
	or file or terminal) here is to pipe*/

int	ft_strcmpp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] && s2[i] && s1[i] == s2[i])
		;
	return (s1[i] + s2[i]);
}

static int	here(int *pi_pe)
{
	close(pi_pe[1]);
	return (pi_pe[0]);
}

void	ftlstclearrrrr(t_list **lst, void (*del)(void	*))
{
	t_list	*list;

	list = *lst;
	while (*lst != NULL)
	{
		*lst = list->next;
		del(list->content);
		free(list);
		list = *lst;
	}
}

int	here_doc(char *lim, t_list *env)
{
	char	*line;
	int		pi_pe[2];
	char	*ptr;

//	env = 0;
	pipe(pi_pe);
	line = 0;
	ptr = 0;
	while (1)
	{
		e_st = 1;
		line = readline("> ");
		if (e_st == 1337)
			return (1337);
		if (line == 0)
		{
			printf("\n");
			break ;
		}
		if (ft_strcmpp(lim, line) == 0)
			break ;
		ptr = ft_strchr(line, '$');
		if (ptr != 0)
		{
			ptr++;
			ptr = get_env(env, ptr);
			free(line);
			line = 0;
			if (ptr != NULL)
				line = ft_strjoin_n(ptr, ft_strdup("\n"));
		}
		else
			line = ft_strjoin_n(line, ft_strdup("\n"));
		ft_putstr_fd(line, pi_pe[1]);
		free(line);
	}
	free(line);
	free(ptr);
	return (here(pi_pe));
}

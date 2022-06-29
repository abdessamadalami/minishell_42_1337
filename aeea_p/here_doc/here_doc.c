/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:24:48 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/29 17:54:01 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

void	printf_err(t_list *str)
{
	t_list	*head;

	head = str;
	while (str)
	{
		perror(str -> content);
		str = str -> next;
	}
	ft_lstclear(&str, del);
}

static void	here_docc(int *fd, char *str, t_list *env)
{
	int	a;

	a = 0;
	if (*fd == -1)
	{
		a = here_doc(str, env);
		close(a);
	}
	else
	{
		if (*fd != 0)
			close(*fd);
		*fd = here_doc(str, env);
	}
}
//! file input q// the content in the fd vaiable is the the fd of the last one 

static void	input(int *fd, char *str)
{
	if (*fd != 0)
		close(*fd);
	*fd = redirect_inpu(str);
}

t_list	*chec_for_here_doc(t_list **lst, t_list *env)
{
	t_list	*list;
	t_list	*fds;
	t_list	*str;
	int		fd;

	list = *lst;
	fds = 0;
	fd = 0;
	str = NULL;
	while (list)
	{
		if (ft_strncmp(list->content, "|\0", 3) == 0)
		{
			ft_lstadd_back(&fds, ft_lstnew(ff(fd)));
			fd = 0;
		}
		if (ft_strncmp(list->content, "<<\0", 4) == 0)
			here_docc(&fd, list->next->content, env);
		if (ft_strncmp(list->content, "<\0", 3) == 0)
		{
			input(&fd, list->next->content);
			if (fd == -1)
				ft_lstadd_back(&str, ft_lstnew(list->next->content));
		}
		list = list->next;
	}
	ft_lstadd_back(&fds, ft_lstnew(ff(fd)));
	printf_err(str);
	delete_here(lst);
	return (fds);
}

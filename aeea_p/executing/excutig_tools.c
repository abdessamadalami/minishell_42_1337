/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excutig_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:12:50 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/01 23:23:35 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

void	fr(t_list *fds)
{
	if (fds != NULL)
	{
		ft_lstclear(&fds, del);
		fds = 0;
	}
}

int	pip_number(t_list *list)
{
	int		index;
	char	*str;

	index = 0;
	while (list)
	{
		str = list->content;
		if (str[0] == '|' && str[1] == '\0')
			index++;
		list = list ->next;
	}
	return (index);
}

void	wait_exit_status(int *ids, int n_p)
{
	int	i;
	int	exit_s;

	i = 0;
	while (i <= n_p)
	{
		waitpid(ids[i], &exit_s, 0);
		if (WIFEXITED(exit_s))
			g_st = WEXITSTATUS(exit_s);
		i++;
	}
	free(ids);
	ids = 0;
}

void	make_ne(t_list **pars_il, t_list **fds_std_in)
{
	while (1)
	{
		if (*pars_il == 0)
			break ;
		if (*(int *)(*fds_std_in)->content != -1)
		{
			if ((*fds_std_in)->next != 0)
				(*fds_std_in) = (*fds_std_in)->next;
			break ;
		}
		else
		{
			if (*fds_std_in != 0)
				(*fds_std_in) = (*fds_std_in)->next;
			if (*pars_il == 0)
				break ;
			*pars_il = make_list_fork(*pars_il);
		}
	}
}

void	dup_parm(t_list **pars_il, int *fd, t_list **std_in)
{
	t_list	*lst;

	lst = make_list_fork(*pars_il);
	if (lst == 0)
		return ;
	if (*std_in != 0)
	{
		if (*(int *)(*std_in)->content != 0)
		{
			*fd = *(int *)(*std_in)->content;
			if ((*std_in)->next)
				*std_in = (*std_in)->next;
		}
		if (*(int *)(*std_in)->content == 0)
		{
			if ((*std_in)->next != 0)
				*std_in = (*std_in)->next;
			else
				*std_in = 0;
		}
	}
	*pars_il = lst;
}

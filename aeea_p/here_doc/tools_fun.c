/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 10:15:05 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/29 17:54:24 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

int	check_redirec_d(t_list *lst)
{
	while (lst)
	{
		if (ft_strncmp(lst->content, "<<\0", 4) == 0
			|| ft_strncmp(lst->content, "<\0", 3) == 0)
			return (1);
		lst = lst -> next;
	}
	return (0);
}

int	check_redirec_list(t_list *lst)
{
	while (lst)
	{
		if (ft_strncmp(lst->content, "<<\0", 4) == 0)
			return (1);
		lst = lst -> next;
	}
	return (0);
}

int	redirect_inpu(char *std_in)
{
	int	fd_input;

	fd_input = open(std_in, O_RDONLY);
	return (fd_input);
}

int	*ff(int a)
{
	int	*ptr;

	ptr = (int *)malloc(4);
	*ptr = a;
	return (ptr);
}

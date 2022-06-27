/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:57:25 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/26 11:09:50 by sultan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

t_list	*make_list_fork(t_list *list)
{
	t_list	*head;
	char	*str;

	while (list)
	{
		str = list -> content;
		if (str[0] == '|' && str[1] == '\0')
		{
			head = list -> next;
			return (head);
		}
		list = list -> next;
	}
	return (0);
}

int	chec_for_pipe(t_list *list)
{
	char	*str;

	while (list)
	{
		str = list -> content;
		if (str[0] == '|' && str[1] == '\0')
			return (1);
		list = list -> next;
	}
	return (0);
}

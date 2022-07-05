/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:25:23 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/29 17:41:26 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

void	error_printf(char	*cmd)
{
	if (ft_strchr(cmd, 47) == NULL)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		g_st = 127;
	}
	else if (ft_strchr(cmd, 47))
	{
		ft_putstr_fd(cmd, 2);
		g_st = 1;
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	exit(g_st);
}

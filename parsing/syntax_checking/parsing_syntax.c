/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:44:02 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/10 19:30:54 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_syntax(t_arg *arg)
{
	if (!check_qt(arg) || !check_red(arg) || !check_pip(arg))
	{
		ftlstclear(&arg, free);
		return (0);
	}
	while (arg->next != NULL)
		arg = arg->next;
	if (arg->data[ft_strln(arg->data) - 1] == '>'
		|| arg->data[ft_strln(arg->data) - 1] == '<')
	{
		printf("syntax error near unexpected token `newline'\n");
		ftlstclear(&arg, free);
		return (0);
	}
	return (1);
}

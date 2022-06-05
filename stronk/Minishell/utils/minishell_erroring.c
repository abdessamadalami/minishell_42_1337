/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_erroring.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:09:24 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/05 17:11:59 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_syntax_error(int x, char c)
{
	if (x == 1)
		printf("syntax error near unexpected token `%c'\n", c);
	else
		printf("syntax error near unexpected token `%c%c'\n", c, c);
	exit(1);
}
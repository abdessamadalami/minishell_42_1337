/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:44:02 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/31 18:19:20 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_syntax(char *s)
{
	int	i;

	i = 0;
	while(s[i+1] != '\0')
		i++;
	
	if ((s[0]=='<' && s[1] == '>' && s[2] == '\0') || (s[i] == '>' || s[i] == '<'))
	{
		printf("syntax error near unexpected token `newline'\n");
		exit(1);
	}
}
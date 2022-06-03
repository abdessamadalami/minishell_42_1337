/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:44:02 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/03 19:50:53 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	first_occc(char *s)
{
	int	i;

	i = 0;
	printf("s `%s`\n", s);
	while(s[i] != '\0')
	{
		if (s[i] == '"' || s[i] == '\'')
			return (s[i]);
		i++;
	}
	return ('\0');
}

void	check_syntax(t_arg *arg)
{
	t_arg	*s;
	int		i;
	int		x;
	int		y;
//	char	c;
	char	f;
	char	l;

	i = 0;
	x = 0;
	y = 0;
	s = arg;
	
/*	while(s[i+1] != '\0')
		i++;
	
	if ((s[0]=='<' && s[1] == '>' && s[2] == '\0') || (s[i] == '>' || s[i] == '<'))
	{
		printf("syntax error near unexpected token `newline'\n");
		exit(1);
	}*/
	printf("wa blaati db\n");
	while (s != NULL)
	{
		i = 0;
		x = 0;
		f = first_occc(s->data);
		if (f == '"')
			l = '\'';
		else
			l = '"';
//		printf("f %c\n", f);
		while (s->data[i])
		{
		//	if (s->data[i] == '>' || s->data[i] == '<' || s->data[i] == '|')
			if (s->data[i] == f)
			{
				x++;
				// c = s->data[i];
			}
			if (s->data[i] == l && x%2 == 0)
			{
				y++;
				// c = s->data[i];
			}
			i++;
		}
//		printf("x %d\n", x);
	//	if (x>2)
		if (x % 2 != 0)
		{
			printf("syntax error near unexpected token `%c'\n", f);
			exit(1);
		}
		if (y % 2 != 0)
		{
			printf("syntax error near unexpected token `%c'\n", l);
			exit(1);
		}
//		printf("%s\n", s->data);
		s = s->next;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:44:02 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/04 17:34:23 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	first_occc(char *s)
{
	int	i;

	i = 0;
//	printf("s `%s`\n", s);
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
	int		w;
	int		p;
	char	r;
	int		count;

	i = 0;
	x = 0;
	y = 0;
	w = 0;
	p = 0;
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
		count = count_q(s->data, f);
		if (f == '"')
			l = '\'';
		else
			l = '"';
//		printf("f %c\n", f);
		while (s->data[i] != '\0')
		{
			if (s->data[i] == f)
				count--;
			if ((s->data[i] == '>' || s->data[i] == '<') && (count % 2 == 0))
			{
				r = s->data[i];
				w++;
			}
			i++;
		}
		if (w > 2)
		{
		//	printf("hi\n");
			if (w == 3)
				printf("syntax error near unexpected token `%c'\n", r);
			else
				printf("syntax error near unexpected token `%c%c'\n", r, r);
			exit(1);
		}
		i = 0;
		while (s->data[i] != '\0')
		{
			if (s->data[i] == '|')
				count--;
			if ((s->data[i] == '|') && (count%2 == 0))
				p++;
			i++;
		}
		if (p > 1)
		{
			if (p == 2)
				printf("syntax error near unexpected token `|'\n");
			else
				printf("syntax error near unexpected token `||'\n");
			exit(1);
		}
		i = 0;
		while (s->data[i])
		{
		//	if (s->data[i] == '>' || s->data[i] == '<' || s->data[i] == '|')
			if (s->data[i] == f)
			{
				x++;
				// c = s->data[i];
			}
			if (s->data[i] == l && x % 2 == 0)
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
		printf("%s\n", s->data);
		s = s->next;
	}
}
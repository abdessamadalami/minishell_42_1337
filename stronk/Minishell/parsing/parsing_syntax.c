/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:44:02 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/05 13:37:14 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	first_occc(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"' || s[i] == '\'')
			return (s[i]);
		i++;
	}
	return ('\0');
}

void	check_qt(t_arg *s)
{
//	t_arg	*s;
	int		i;
	int		count;
	char	f;
	char	l;
	int		x;
	int		y;

//	s = arg;
	while (s != NULL)
	{
		i = 0;
		x = 0;
		y = 0;
		f = first_occc(s->data);
		count = count_q(s->data, f);
		if (f == '"')
			l = '\'';
		else
			l = '"';
		while (s->data[i])
		{
			if (s->data[i] == f)
			{
				x++;
			}
			if (s->data[i] == l && x % 2 == 0)
			{
				y++;
			}
			i++;
		}
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
		s = s->next;
	}
}

void	check_red(t_arg *s)
{
	int		i;
	int		count;
	int		w;
	char	r;

	while (s != NULL)
	{
		i = 0;
		w = 0;
		count = count_q(s->data, first_occc(s->data));
		while (s->data[i] != '\0')
		{
			if (s->data[i] == first_occc(s->data))
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
			if (w == 3)
				printf("syntax error near unexpected token `%c'\n", r);
			else
				printf("syntax error near unexpected token `%c%c'\n", r, r);
			exit(1);
		}
		s = s->next;
	}
}

void	check_pip(t_arg *s)
{
	int		i;
	int		count;
	int		p;

	while (s != NULL)
	{
		i = 0;
		p = 0;
		count = count_q(s->data, '|');
		while (s->data[i] != '\0')
		{
			if (s->data[i] == '|')
				count--;
			if ((s->data[i] == '|') && (count % 2 == 0))
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
		s = s->next;
	}
}

void	check_syntax(t_arg *arg)
{
	printf("wa blaati db\n");

	check_qt(arg);
	check_red(arg);
	check_pip(arg);
	while (arg->next != NULL)
	{
		arg = arg->next;
	}
	// printf("data %s\n", arg->data);
	// printf("%d\n", ft_strln(arg->data));
	// printf("hadi hya -%c-\n", arg->data[ft_strln(arg->data)-1]);
	if (arg->data[ft_strln(arg->data)-1] == '>' || arg->data[ft_strln(arg->data)-1] == '<')
	{
		printf("syntax error near unexpected token `newline'\n");
		exit(1);
	}
}

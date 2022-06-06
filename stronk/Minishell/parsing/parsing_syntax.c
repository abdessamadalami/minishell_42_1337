/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:44:02 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/06 17:37:15 by ael-asri         ###   ########.fr       */
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

char	last_occc(char *s)
{
	char	f;

	f = first_occc(s);
	if (f == '"')
		return ('\'');
	return ('"');
}

void	count_quotes(char *s)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"')
		{
			x++;
			i++;
			while (s[i] != '"' && s[i] != '\0')
				i++;
			if (s[i] == '"')
				x++;
			i++;
		}
		else if (s[i] == '\'')
		{
			y++;
			i++;
			while (s[i] != '\'' && s[i] != '\0')
				i++;
			if (s[i] == '\'')
				y++;
			i++;
		}
		else
			i++;
	}
//	printf("d %d\n", y);
	if (x % 2 != 0)
		print_syntax_error(1, '"');
	if (y % 2 != 0)
		print_syntax_error(1, '\'');
}

int	*count_sdq(char *s, char f, char l)
{
	int	*t;
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	t = malloc(sizeof(int) * 3);
	while (s[i] != '\0')
	{
		if (s[i] == f)
		{
			x++;
		}
		if (s[i] == l && x % 2 == 0)
		{
			y++;
		}
		i++;
	}
	// printf("x %d\n", x);
	// printf("y %d\n", y);
	t[0] = x;
	t[1] = y;
	t[2] = '\0';
	return (t);
}

void	check_qt(t_arg *s)
{
	// int		*t;
	// int		count;
	// char	f;
	// char	l;

	while (s != NULL)
	{
	//	f = first_occc(s->data);
	//	count = count_q(s->data, f);
		// if (f == '"')
		// 	l = '\'';
		// else
		// 	l = '"';
		// t = malloc(sizeof(int) * 3);
		count_quotes(s->data);
		// if (t[0] % 2 != 0)
		// 	print_syntax_error(1, f);
		// if (t[1] % 2 != 0)
		// 	print_syntax_error(1, l);
		s = s->next;
	}
//	printf("wah\n");
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
			if ((s->data[i] == '>' || s->data[i] == '<') && (count % 2 == 0)
				&& (s->data[i + 1] == '>' || s->data[i + 1] == '<')
				&& (s->data[i + 2] == '>' || s->data[i + 2] == '<'))
			{
				r = s->data[i+2];
				w++;
			}
			i++;
		}
		if (w > 0)
			print_syntax_error(w, r);
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
		count = count_q(s->data, first_occc(s->data));
		while (s->data[i] != '\0')
		{
			if (s->data[i] == first_occc(s->data))
				count--;
			if ((s->data[i] == '|') && (count % 2 == 0))
				p++;
			i++;
		}
		if (p > 1)
			print_syntax_error(p, '|');
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
	if (arg->data[ft_strln(arg->data) - 1] == '>'
		|| arg->data[ft_strln(arg->data) - 1] == '<')
	{
		printf("syntax error near unexpected token `newline'\n");
		exit(1);
	}
}

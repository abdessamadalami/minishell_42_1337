/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 09:04:55 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/06 16:22:32 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_clean_one(char *data)
{
	int		i;
	int		j;
	char	*s;
	int		count;

	i = 0;
	j = 0;
	s = malloc(sizeof(char) * (ft_strln(data) - 1));
	if (!s)
		exit(1);
	count = count_q(data, first_occc(data));
	while (data[i] != '\0')
	{
		if (data[i] == first_occc(data))
			count--;
		if (data[i] != first_occc(data))
		{
			if (data[i] == last_occc(data) && (count % 2 == 0))
			{
				i++;
				continue ;
			}
			s[j] = data[i];
			j++;
		}
		else if (data[i] == last_occc(data) && (count % 2 != 0))
		{
			s[j] = data[i];
			j++;
		}
		i++;
	}
	s[j] = '\0';
	return (s);
}

char	*parsing_quotes(char *s)
{
	char	*t;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	t = (char *)malloc(sizeof(char *) * 9999);
	if (!t)
		exit(1);
	while (s[i] != '\0')
	{
	//	j = i;
		if (s[i] == '"')
		{
			i++;
			printf("c $%c$ %d\n", s[i], j);
			while (s[i] != '\0' && s[i] != '"')
			{
				// printf("c $%c$ %d\n", s[i], j);
				t[j] = s[i];
				i++;
				j++;
			}
			i++;
			
		}
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\0' && s[i] != '\'')
			{
		//		printf("c $%c$ %d\n", s[i], j);
				t[j] = s[i];
				i++;
				j++;
			}
			i++;
		}
		else
		{
		//	printf("c $%c$ %d\n", s[i], j);
			if (s[i] != '\0' && s[i] != '"' && s[i] != '\'')
			{
				t[j] = s[i];
				i++;
				j++;
			}
			else
				i++;
		}
	}
	t[j] = '\0';
//	printf("s-%s-\n", t);
	return (t);
}

t_arg	*remove_quotes(t_arg *arg)
{
	int		i;
	int		j;
	t_arg	*sfa;
	t_arg	*node;
	char	*s;

	sfa = NULL;
	i = 0;
	j = 0;
	while (arg != NULL)
	{
		if (!check_q(arg->data))
		{
			printf("hi %s\n", arg->data);
			s = parsing_quotes(arg->data);
			if (*s != '\0')
			{
				node = ftlstnew(s);
				ftlstadd_back(&sfa, node);
			}
		}
		else
		{
			node = ftlstnew(arg->data);
			ftlstadd_back(&sfa, node);
		}
		arg = arg->next;
	}
	return (sfa);
}

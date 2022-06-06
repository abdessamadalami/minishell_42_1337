/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:49:33 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/06 16:11:57 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_arg	*fill_list(char **t)
{
	t_arg	*arg;
	t_arg	*node;
	int		i;

	i = 0;
	arg = NULL;
	while (t[i] != NULL)
	{
		node = ftlstnew(t[i]);
	//	printf("t %s\n", t[i]);
		ftlstadd_back(&arg, node);
		i++;
	}
	return (arg);
}

t_arg	*parsing_spaces(char *s)
{
	char	**t;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	t = (char **)malloc(sizeof(char *) * 9999);
	if (!t)
		exit(1);
	while (s[i] != '\0')
	{
		j = i;
		if (s[i] == '"')
		{
			i++;
			while (s[i] != '\0' && s[i] != '"')
				i++;
		//	printf("%c\n", s[i]);
			i++;
		//	printf("--%c\n", s[i]);
			t[count] = ft_subtr(s, j, i - j);
		}
		else if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\0' && s[i] != '\'')
				i++;
			i++;
			t[count] = ft_subtr(s, j, i - j);
		}
		else
		{
			while (s[i] == ' ')
				i++;
			j = i;
			while (s[i] != ' ' && s[i] != '\0')
				i++;
			t[count] = ft_subtr(s, j, i - j);
			i++;
		}
		count++;
	}
	t[count] = 0;
	return (fill_list(t));
}

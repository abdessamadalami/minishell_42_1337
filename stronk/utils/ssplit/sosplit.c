/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sosplit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:42:22 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/25 13:06:07 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	set_count(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == '<' || s[i] == '>' || s[i] == '|')
		i++;
	count++;
	while (s[i])
	{
		if ((s[i] == '<' || s[i] == '>' || s[i] == '|') && (s[i + 1] != '\0'))
		{
			if (s[i + 1] == '<' || s[i + 1] == '>' || s[i + 1] == '|')
				i++;
			count++;
		}
		i++;
	}
	return (count + 2);
}

static char	**ft_del(char **t, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(t[i]);
		i++;
	}
	free(t);
	return (NULL);
}

static char	**chek_and_fill(char **t, char *s)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	
	while (s[i] != '\0')
	{
		
		temp = i;
		if (s[i] == '<' || s[i] == '>'|| s[i] == '|')
		{
			if (s[i + 1] == s[i])
				i++;
			i++;
			t[count] = ft_subtr(s, temp, i - temp);
			count++;
			continue ;
		}
		while (s[i] != '<' && s[i] != '>' && s[i] != '|' && s[i])
		{
			i++;
		}
		t[count] = ft_subtr(s, temp, i - temp);
		if (t[count] == NULL)
			return (ft_del(t, count));
		count++;
	}
	t[count] = 0;
	return (t);
}

char	**sosplit(char *s)
{
	char	**t;
	int		count;

	if (s == 0)
		return (0);
	count = set_count(s);
	if (count < 0)
	{
		printf("go to heredoc\n");
		exit(1);
	}
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == NULL)
		return (0);
	return (chek_and_fill(t, s));
}
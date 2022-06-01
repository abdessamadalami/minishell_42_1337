/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qusplit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:21:21 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/01 13:01:40 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	set_count(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != '\0')
		{
			if (s[i + 1] == c)
				i++;
			count++;
		}
		i++;
	}
	return (count+1);
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

static char	**chek_and_fill(char **t, char *s, char c)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	
	while (s[i] != '\0')
	{
		
		temp = i;
		if (s[i] == c )
		{
			if (s[i + 1] == c)
				i++;
			i++;
			t[count] = ft_subtr(s, temp, i - temp);
			count++;
			continue ;
		}
		while (s[i] != c && s[i])
		{
			i++;
		}
		t[count] = ft_subtr(s, temp, i - temp);
		if (t[count] == NULL)
			return (ft_del(t, count));
		count++;
	}
	count++;
	t[count] = 0;
	return (t);
}

char	**qusplit(char *s, char c)
{
	char	**t;
	int		count;

	if (s == 0)
		return (0);
	count = set_count(s, c);
	if (count < 0)
	{
		printf("Error tmma\n");
		exit(1);
	}
	t = (char **)malloc(sizeof(char *) * 9999/*(count + 1)*/);
	if (t == NULL)
		return (0);
	return (chek_and_fill(t, s, c));
}
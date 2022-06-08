/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:08:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/07 19:56:16 by ael-asri         ###   ########.fr       */
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
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
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
	int	dq;

	i = 0;
	count = 0;
	dq = 0;
	while (s[i])
	{
		if (dq == 0 && s[i] == '"')
		{
			printf("hi dq\n");
			dq = 1;
			// init = i;
		}
		else if (dq == 1 && s[i] == '"')
		{
			printf("hi dq-end\n");
			dq = 0;
			i++;
			// end = i;
		}
		temp = i;
		if (s[i] == c && dq == 0)
		{
			i++;
			continue ;
		}
		while (s[i] != c && s[i] && (dq == 0))
		{
			if (dq == 0 && s[i] == '"')
			{
				printf("hi dq\n");
				dq = 1;
				// init = i;
			}
			else if (dq == 1 && s[i] == '"')
			{
				printf("hi dq-end\n");
				dq = 0;
				// end = i;
			}
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

char	**ft_split(char *s, char c)
{
	char	**t;
	int		count;

	if (s == 0)
		return (0);
	count = set_count(s, c);
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == NULL)
		return (0);
	return (chek_and_fill(t, s, c));
}

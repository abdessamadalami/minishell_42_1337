/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sosplit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:42:22 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/10 18:26:19 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

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

static int	just_anwhile(char *s, int i)
{
	while (s[i] != '<' && s[i] != '>' && s[i] != '|' && s[i])
		i++;
	return (i);
}

static int	just_anif(char *s, int i)
{
	if (s[i + 1] == s[i] && s[i] != '|')
		i++;
	return (i);
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
		if (s[i] == '<' || s[i] == '>' || s[i] == '|')
		{
			i = just_anif(s, i);
			i++;
			t[count] = ft_ssubtr(s, temp, i - temp);
			count++;
			continue ;
		}
		i = just_anwhile(s, i);
		t[count] = ft_ssubtr(s, temp, i - temp);
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
	count = so_counter(s);
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == NULL)
		return (0);
	return (chek_and_fill(t, s));
}

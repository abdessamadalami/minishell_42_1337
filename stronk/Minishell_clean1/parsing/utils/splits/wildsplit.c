/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:41:31 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/10 19:48:26 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static int	set_count(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == '*')
		i++;
	count++;
	while (s[i])
	{
		if (s[i] == '*' && s[i + 1] != '\0')
			count++;
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
		if (s[i] == '*')
		{
			i++;
			t[count] = ft_ssubtr(s, temp, i - temp);
			count++;
			continue ;
		}
		while (s[i] != '*' && s[i])
			i++;
		t[count] = ft_ssubtr(s, temp, i - temp);
		if (t[count] == NULL)
			return (ft_del(t, count));
		count++;
	}
	t[count] = 0;
	return (t);
}

char	**wildsplit(char *s)
{
	char	**t;
	int		count;

	if (s == 0)
		return (0);
	count = set_count(s);
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == NULL)
		return (0);
	return (chek_and_fill(t, s));
}

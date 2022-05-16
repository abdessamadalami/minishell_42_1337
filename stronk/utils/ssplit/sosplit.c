/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sosplit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:42:22 by ael-asri          #+#    #+#             */
/*   Updated: 2022/05/16 18:46:25 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	set_count(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] == '>')
		i++;
	count++;
	while (s[i])
	{
	//	if (s[i] == '"' || s[i] == '\''/* || s[i] == '>' || s[i] == '<'*/)
	//		gg->lock++;
		if (s[i] == '>' && s[i + 1] != '>' && s[i + 1] != '\0')
			count++;
		i++;
	}
//	printf("count %d\n", gg->lock);
//	if (gg->lock % 2 != 0)
//		return (-1);
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

char	*ft_add(char *s, char c)
{
	char	*t;
	int	i;

	i = 0;
	t = malloc(sizeof(char) * ft_strlen(s) + 2);
	if (!t)
		return (NULL);
	while (s[i] != '\0')
	{
		t[i] = s[i];
		i++;
	}
	t[i] = c;
	i++;
	t[i] = '\0';
	return (t);
}

static char	**chek_and_fill(char **t, char *s)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	
	while (s[i])
	{
		
		temp = i;
		if (s[i] == '>')
		{
			i++;
			
		//	t[count] = ft_strdup(">");
		/*	if (s[i+1] == s[i])
			{
				i++;
				t[count] = ft_substr(s, temp, i - temp);
			//	i ++;
			}
			else*/
			printf("HAAAAADA TOKEN %s\n", ft_substr(s, temp, i - temp));
				t[count] = ft_substr(s, temp, i - temp);
				printf("tttttt-%s-\n", t[count]);
			//	i++;
			count++;
	//		if (s[i] == '"' || s[i] == '\'')
	//			gg->lock--;
		//	i++;
			continue ;
		}
		// printf("lock %d\n", cmds->lock);
		while (s[i] != '>' && s[i])
		{
		//	if (s[i] == '"' || s[i] == '\'')
		//		break;
			//	cmds->lock--;
			i++;
			// cmds->lock--;
		}
		t[count] = ft_substr(s, temp, i - temp);
		printf("tttttt-%s-\n", t[count]);
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
		// return (NULL);
		printf("go to heredoc\n");
		exit(1);
	}
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (t == NULL)
		return (0);
	return (chek_and_fill(t, s));
}
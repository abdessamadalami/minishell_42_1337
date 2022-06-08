/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:49:33 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/08 11:47:10 by ael-asri         ###   ########.fr       */
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
		printf("t %s\n", t[i]);
		ftlstadd_back(&arg, node);
		i++;
	}
	return (arg);
}

t_arg	*parsing_z3t(char *s)
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
	while (s[i] == ' ')
		i++;
	while (s[i] != '\0')
	{
		j = i;
		if (s[i] == '"')
		{
			i++;
			while (s[i] != '\0' && s[i] != '"')
				i++;
		//	printf("%c\n", s[i]);
		//	i++;
		//	printf("--%c\n", s[i]);
		//	t[count] = ft_subtr(s, j, i - j);
		}
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\0' && s[i] != '\'')
				i++;
		//	i++;
		//	printf("$ %s\n", ft_subtr(s, j, i - j));
		//	t[count] = ft_subtr(s, j, i - j);
		}
	//	else
		if (s[i] != ' ')
		{
			// while (s[i] == ' ')
			// 	i++;
			// j = i;
			while (s[i] != ' ' && s[i] != '\0')
				i++;
			i++;
		}
		t[count] = ft_subtr(s, j, i - j);
		count++;
	}
	t[count] = 0;
	return (fill_list(t));
}

t_arg	*parsing_sta9ata9(char *s)
{
	char	**t;
	int		i;
	int		j;
	int		count;
	int		dq;
	int		sq;
	int		init;
	int		end;

	i = 0;
	j = 0;
	dq = 0;
	sq = 0;
	init = 0;
	end = 0;
	count = 0;
	t = (char **)malloc(sizeof(char *) * 9999);
	while (i < 10)
	{
		t[i] = malloc(sizeof(char) * (ft_strln(s) + 1));
		i++;
	}
	i = 0;
	if (!t)
		exit(1);
	while (s[i] == ' ')
		i++;
	while (s[i] != '\0')
	{
		if (dq == 0 && s[i] == '"' && sq == 0)
		{
			printf("hi dq\n");
			dq = 1;
			// init = i;
		}
		else if (dq == 1 && s[i] == '"' && sq == 0)
		{
			printf("hi dq-end\n");
			dq = 0;
			// end = i;
		}
		//////////////////////
		else if (sq == 0 && s[i] == '\'' && dq == 0)
		{
			// printf("hi sq\n");
			sq = 1;
			// init = i;
		}
		else if (sq == 1 && s[i] == '\'' && dq == 0)
		{
			// printf("hi sq-end\n");
			sq = 0;
		//	end = i;
		}
		///////////////////////
		// if ((s[i] == ' ' && dq == 0 && sq == 0) || (s[i+1] != '\0' && dq == 0 && sq == 0))
		// {
		// 	t[count][j] = '\0';
		// 	printf ("t[%d] = |%s|\n", count, t[count]);
		// 	exit (0);
		// 	count++;
		// 	j = 0;
		// }
		// else
		// {
		// 	// printf("count: %d | j: %d\n", count, j);
		// 	t[count][j] = s[i];
		// 	// printf("%c", s[i]);
		// 	j++;
		// }
		if (dq == 0 && sq == 0)
		{
			if (s[i+1] == '\0')
			{
				printf("subjn %s\n", ft_strjn(t[count], ft_subtr(s, init, i+1)));
				t[count] = ft_strjn(t[count], ft_subtr(s, init, i+1));
			//	exit(1);
			}
			if (s[i + 1] == ' ')
			{
				i++;
				continue ;
			}
				printf("sub %s\n", ft_subtr(s, init+1, i+1));
				t[count] = ft_subtr(s, init, i+1);
				count++;
				init = i;
			
		}
		
		//	t[count][j] = '\0';
		//	count++;
	// /*	else
	// 	{
	// 		printf("s[%d] = %c\n", i , s[i]);
	// 		t[count][j] = s[i];
	// 		j++;
	// 	}*/
		i++;
	}
//	t[count] = 0;
//	exit(1);
	return (fill_list(t));
}
//"gg ff"

t_arg	*parsing_spaces(char *s)
{
	char	**t;
	int		i;
	int		count;
	int		init;

	i = 0;
	count = 0;
	init = i;
	t = (char **)malloc(sizeof(char *) * 9999);
	if (!t)
		exit(1);
	while (s[i] == ' ')
		i++;
	while (s[i] != '\0')
	{
		printf("sba7 llah %c\n", s[i]);
		if (s[i] == '"')
		{
			printf("space %c | count : %d | init %d | i: %d\n", s[i], count, init, i);
			i++;
			while (s[i] != '"' && s[i] != '\0')
				i++;
			i++;
			printf("quote %c after\n", s[i]);
			t[count] = ft_strjn(t[count], ft_subtr(s, init, i));
			init = i;
		}
		else if (s[i] == '\'')
		{
			printf("space %c | count : %d | init %d | i: %d\n", s[i], count, init, i);
			i++;
			while (s[i] != '\'' && s[i] != '\0')
				i++;
			i++;
			t[count] = ft_strjn(t[count], ft_subtr(s, init, i));
			init = i;
		}
		else if (s[i] == ' ' || s[i + 1] == '\0')
		{
			printf("space %c | count : %d | init %d | i: %d\n", s[i], count, init, i);
			if (s[i + 1] == '\0')
			{
				t[count] = ft_strjn(t[count], ft_subtr(s, init, i+1));
				break ;
			}
			t[count] = ft_strjn(t[count], ft_subtr(s, init, i));
		//	printf("sub $%s$\n", ft_subtr(s, init, i));
			printf("t[%d]: $%s$\n", count, t[count]);
			count++;
			while (s[i] == ' ' && s[i] != '\0')
				i++;
			init = i;
		}
		else
			i++;
	}
	return (fill_list(t));
}

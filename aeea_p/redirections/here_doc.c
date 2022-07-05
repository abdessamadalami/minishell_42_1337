/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:34:28 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/02 23:28:24 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"
#include "../../minishell.h"

/*read from  here_doc to fd (we can choise between write to pipe
	or file or terminal) here is to pipe*/

int	ft_strcmpp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] && s2[i] && s1[i] == s2[i])
		;
	return (s1[i] + s2[i]);
}

static int	here(int *pi_pe, char *line)
{
	free(line);
	line = 0;
	close(pi_pe[1]);
	return (pi_pe[0]);
}

void	ff_nor(char **ptr_s, char **ptr, char **s, int index)
{
	if (*ptr != NULL)
	{
		if (*s == 0)
			*s = *ptr;
		else
			*s = (ft_strjoin_n(*s, *ptr));
		free(ptr_s[index]);
	}
	else
	{
		if (*s == 0)
			*s = ptr_s[index];
		else
			*s = ft_strjoin_n(*s, ptr_s[index]);
	}
}

char	*ft_help(t_list *env, char *line, int *pi_pe)
{
	char	*ptr;
	char	**ptr_s;
	int		index;
	char	*s;

	ptr_s = ft_split(line, '$');
	free(line);
	line = 0;
	index = 0;
	s = 0;
	while (ptr_s[index])
	{
		ptr = get_env(env, ptr_s[index]);
		ff_nor(ptr_s, &ptr, &s, index);
		index++;
	}
	s = (ft_strjoin_n(s, ft_strdup("\n")));
	ft_putstr_fd(s, pi_pe[1]);
	free(s);
	free(ptr_s);
	s = 0;
	return (0);
}

int	here_doc(char *lim, t_list *env)
{
	char	*line;
	int		pi_pe[2];

	pipe(pi_pe);
	line = 0;
	while (1)
	{
		g_st = 1;
		line = readline("> ");
		if (g_st == 1337)
			return (1337);
		if (line == 0)
		{
			printf("\n");
			break ;
		}
		if (ft_strcmpp(lim, line) == 0)
			break ;
		ft_help(env, line, pi_pe);
	}
	return (here(pi_pe, line));
}

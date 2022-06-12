/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:29:38 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/12 12:26:14 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_dollar(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '$')
			return (0);
		i++;
	}
	return (1);
}

t_arg	*check_for_dollar(t_arg *arg)
{
	t_arg	*sfa;

	sfa = arg;
	while (arg != NULL)
	{
		if (!check_dollar(arg->data))
			printf("kayna l3iba %s\n", arg->data);
		arg = arg->next;
	}
	return (sfa);
}

t_arg	*ft_parsing(char *s)
{
	t_arg	*arg;
	t_gg	*gg;
	char	**line;
	t_arg	*mr;
	t_arg	*dv;
	t_arg	*sd;
	t_arg	*ms;

	gg = malloc(sizeof(t_gg));
	line = malloc(sizeof(char) * ft_strln(s));
	gg->lock = 0;
	gg->count = 0;
	gg->qq = 0;
	arg = parsing_spaces(s);
	check_syntax(arg);
	gg->lock = 0;
	mr = parsin_dyalbss7(arg, gg);
	sd = check_for_dollar(mr);
	ms = parsing_wildcard(sd);
	dv = remove_quotes(ms);
//	system("leaks minishell");
	


	///// echo "don't freak out buddy!">'don"t freak out buddy!'
	
	return (dv);
}

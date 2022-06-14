/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:29:38 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/14 12:23:10 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	//// echo "'$gg'""gg"
	return (dv);
}

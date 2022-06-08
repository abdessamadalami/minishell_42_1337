/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:29:38 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/08 10:31:09 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_arg	*ft_parsing(char *s)
{
	t_arg	*arg;
	// t_arg	*node;
	t_gg	*gg;
	char	**line;
	int		i;
	t_arg	*mr;
	t_arg	*dv;
	t_arg	*ms;

	
	//	printf("rra -%s-\n", s);
//	arg = malloc(sizeof(t_arg));
//	node = malloc(sizeof(t_arg));
	gg = malloc(sizeof(t_gg));
	line = malloc(sizeof(char) * ft_strln(s));
	gg->lock = 0;
	gg->count = 0;
	gg->qq = 0;
	i = 0;

	
	// line = ft_split(s, ' ');
	arg = parsing_spaces(s);
	// for(int k=0;line[k];k++)
		// printf("line %s\n", line[k]);
	/*arg = ftlstnew(line[i]);
	i++;
	
	while (line[i])
	{
		node = ftlstnew(line[i]);
		ftlstadd_back(&arg, node);
		i++;
	}*/
//	free(gg);
//	free(node);
	check_syntax(arg);
	//////////////////////////
//	printf("lstsize dyal arg %d\n", ftlstsize(arg));
	gg->lock = 0;
	mr = parsin_dyalbss7(arg, gg);
//	free(line);
	// while (mr != NULL)
	// {
	// 			printf("mr--[%s\n", mr->data);
	// 			mr = mr->next;
	// 		}
	//////////////////////////
	
	ms = parsing_wildcard(mr);
	dv = remove_quotes(ms);
	
	// while (node != NULL)
	// {
	// 	free(node->data);
	// 	node = node->next;
	// }
//	free(gg);
//	free(line);
//	free(mr);
// free(arg);
	
//	arg = mr;
	// while (mr != NULL)
	// {
	// 	printf("--[%s\n", mr->data);
	// 	mr = mr->next;
	// }
	// printf("everything good\n");
//	system("leaks minishell");
	
	return (dv);
}

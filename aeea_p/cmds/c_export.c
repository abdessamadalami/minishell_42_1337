/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 07:32:13 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/25 15:14:37 by sultan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"
#include <stdio.h>

//getenv this function sherch about str in linkedlist and if the
// a = 1 and str in the linked list should change it and other if a = 0
// just return the str if is exist in it 
void	ft_shift_plus(char *str)
{
	int	index;
	int	t;

	t = 0;
	index = 0;
	while (str[index + 1] != 0)
	{
		if ((str[index] == '+' || t == 1) && (str[index + 1] != 0))
		{
			str[index] = str[index + 1];
			t = 1;
		}
		index++;
	}
	str[index] = '\0';
}

/*
*/
char	*ft_getenv(t_list *list, char *str, int a)
{
	int		len;
	char	*ptr;
	char	*tem;

	while (list)
	{
		len = ft_strlen(str);
		ptr = (char *)list -> content;
		if ((ft_strncmp(str, ptr, len)) == 0)
		{
			//printf("<%d> <%s> <%s> \n", len ,str,ptr);
			if (a == 1)//for remplace
			{
				//printf(" i am here for remplace %s \n", str);
				str[ft_strlen(str)] = '=';
				//printf(" i am here for remplace %s \n", str);
				// free(list-> content);
				tem = list->content;
				//printf("</ %p >\n", tem);
				list->content = ft_strdup(str);
				free(tem);
				tem = 0;
				return (str);
			}
			else if (a == 2)// a= 2 for += var
			{
				str[ft_strlen(str)] = '=';
				list->content = ft_strjoin(list->content, str + ft_strlen(str) + 1);
			}
			else if (a == 3)// for dolar
				return (ptr + len + 1);
			ptr = 0;
			return (list->content);
		}
		list = list->next;
	}
	return (0);
}

void	c_export(t_list *env, char *var)
{
	char	*check;
	char	*env_var;
	char	*str_return;
	int		p;
	int		re;

	p = 1;
	// printf ("error_handling %s\n", var);
	if (var == 0)
	{
		// printf(" i am here in export 0");
		ft_merge_sort_u(env);// nor work as i am need
		//system("leaks -list minishell");        
		return ;
	}
	env_var = strdup(var);
	check = strchr(var, '=');//error checking
	if (ft_strncmp(var, "=\0", 3) == 0)
	{
		printf("error: `=': not a valid identifier \n");// we need cmd
		return ;
	}
	if (check == NULL )
		re = error_handling(var);
	else
		re = error_handling_e(var, check - var);
	if (re)
		return ;
	// env_var = var;
	if (check)
	{
		//printf("error: check failed_function %s\n", env_var);
		env_var[check - var] = '\0';
		// printf("check failed_function %s \n", env_var);
		if (env_var[check - var - 1] == '+')
		{
			env_var[check - var - 1] = '\0';
			ft_shift_plus(var);
			p = 2;
		}
		//  printf(" %s %ld \n",env_var,check - var);
		str_return = ft_getenv(env, var, p);
		// printf("str_return from getenv %s , and the p par is : %d +\n" ,str_return, p);
		//  exit(1); //
		if (str_return == NULL)
		{
			var [check - var] = '=';
			printf("env %s\n", var);
			ft_lstadd_back(&env, ft_lstnew(ft_strdup(var)));
		}
		//system("leaks -list minishell");
	}
	else if (!check && var != NULL)
	{
		printf(" i am here %s\n", var);
		if (ft_getenv(env, env_var, 2) == NULL)
			ft_lstadd_back(&env, ft_lstnew(ft_strdup(env_var)));
	}
	free(env_var);
}

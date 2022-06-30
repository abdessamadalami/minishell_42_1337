/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 07:32:13 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/28 23:49:54 by sultan           ###   ########.fr       */
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
	// printf("ptr %p\n", ptr);
			// if (a == 1)//for remplace
			// {
			// 	str[ft_strlen(str)] = '=';
			// 	tem = list->content;
			// 	list->content = ft_strdup(str);
			// 	free(tem);
			// 	tem = 0;
			// 	return (str);
			// 	// list->content = a_one(&str, &ptr);
			// 	// return (list->content);
			// }
			// else if (a == 2)// a= 2 for += var
			// {
			// 	str[ft_strlen(str)] = '=';
			// 	if (ft_strchr(list->content, '=') == NULL)
			// 		len--;
			// 	list->content = ft_strjoin(list->content, str + len + 1);
			// }
			// else if (a == 5)//
			// 	list->content = ft_strdup(str);
			// else if (a == 3)// for dolar
			// 	return (ptr + len + 1);
			// ptr = 0;
			// return (list->content);
*/
char	*getenv_statment(int a, char *content, char *str, int len)
{
	char	*tem;

	if (a == 1)//for remplace
	{
		str[ft_strlen(str)] = '=';
		tem = content;
		content = ft_strdup(str);
		free(tem);
		tem = 0;
		return (str);
	}
	else if (a == 2)// a= 2 for += var
	{
		str[ft_strlen(str)] = '=';
		if (ft_strchr(content, '=') == NULL)
			len--;
		content = ft_strjoin(content, str + len + 1);
	}
	else if (a == 5)//
		content = ft_strdup(str);
	// else if (a == 3)// for dolar
	// 	return (content + len + 1);
	return (content);
}

char	*ft_getenv(t_list *list, char *str, int a)
{
	int		len;
	char	*ptr;

	while (list)
	{
		len = ft_strlen(str);
		ptr = (char *)list -> content;
		if ((ft_strncmp(str, ptr, len)) == 0)
		{
			list->content = getenv_statment(a, list->content, str, len);
			return(list->content);
		}
		list = list->next;
	}
	return (0);
}

static int	non_arg(char *var, char **check, char **env_var, t_list *env)
{
	int		re;

	re = 0;
	if (var == 0)
	{
		ft_merge_sort_u(env);
		return (1);
	}
	*env_var = ft_strdup(var);
	*check = ft_strchr(var, '=');
	if (ft_strncmp(var, "=\0", 3) == 0)
	{
		printf("error: `=': not a valid identifier \n");// we need cmd
		return (1);
	}
	if (*check == NULL )
		re = error_handling(var);
	else
		re = error_handling_e(var, *check - var);
	if (re)
		return (1);
	return (0);
}

void	add_replace(int *p, t_list *env, char *check, char *var, char *env_var)
{
	char	*str_return;
	char	*c;

	c = ft_strdup(env_var);
	str_return = 0;
	if (c[check - var - 1] == '+')
	{
		ft_shift_plus(c);
		c[check - var - 1] = '\0';
		*p = 2;
	}
	else
		c[check - var] = '\0';
	str_return = ft_getenv(env, c, *p);
	if (str_return == NULL)
	{
		var[check - var] = '=';
		ft_lstadd_back(&env, ft_lstnew(ft_strdup(var)));
		free(c);
	}
}

void	c_export(t_list *env, char *var)
{
	char	*check;
	char	*env_var;
	char	*str_return;
	int		p;

	p = 1;
	str_return = 0;
	if (non_arg(var, &check, &env_var, env))
		return ;
	if (check)
		add_replace(&p, env, check, var, env_var);
	else if (!check && var != NULL)
		if (ft_getenv(env, env_var, 5) == NULL)
			ft_lstadd_back(&env, ft_lstnew(ft_strdup(env_var)));
	free(env_var);
	//system("leaks minishell");

}

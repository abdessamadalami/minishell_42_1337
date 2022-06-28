/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 07:32:13 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/28 15:13:51 by ael-oual         ###   ########.fr       */
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
				str[ft_strlen(str)] = '=';
				tem = list->content;
				list->content = ft_strdup(str);
				free(tem);
				tem = 0;
				return (str);
			}
			else if (a == 2)// a= 2 for += var
			{
				//printf("in  %s ", str);
				str[ft_strlen(str)] = '=';
				list->content = ft_strjoin(list->content, str + ft_strlen(str) + 1);
			//	printf("in  %s ", list -> content);
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
static int non_arg(char *var, char **check, char **env_var , t_list *env)
{
	int		re;
	
	re = 0;
	if (var == 0)
	{
		ft_merge_sort_u(env);
		return (1);
	}
	*env_var = ft_strdup(var);
	*check = strchr(var, '=');
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

// void add_replace(int *p, t_list *env, char *check, char **var, char **env_var)
// {
// 	char	*str_return;

// 	str_return = 0;
// 	*env_var[check - var] = '\0';
// 	if (*env_var[check - var - 1] == '+')
// 	{
// 		*env_var[check - var - 1] = '\0';
// 		ft_shift_plus(*var);
// 		*p = 2;
// 	}
// 	str_return = ft_getenv(env, var, *p);	
// 	if (str_return == NULL)
// 	{
// 		var[check - var] = '=';
// 		ft_lstadd_back(&env, ft_lstnew(ft_strdup(var)));
// 	}
// }

void	c_export(t_list *env, char *var)
{
	char	*check;
	char	*env_var;
	char	*str_return;
	int		p;

	p = 1;
	str_return = 0;
	if (non_arg(var, &check ,&env_var, env))
		return ;
	if (check)
	{
		//add_replace(&p,env, check, var, &env_var);
		
		if (env_var[check - var - 1] == '+')
		{
			//printf(" i am here\n");
			//printf(" _%s_ \n", env_var);
		    // env_var	= env_var + (check - var) ;
		//	printf(" _%s_ \n", env_var);
			ft_shift_plus(env_var);
			//printf("dd_%s_ \n", env_var);
			p = 2;
		}
		env_var[check - var] = '\0';
	//	printf(" _%s_ \n", env_var);
		str_return = ft_getenv(env, env_var, p);
		if (str_return == NULL)
		{
			var[check - var] = '=';
			ft_lstadd_back(&env, ft_lstnew(ft_strdup(var)));
		}
	}
	else if (!check && var != NULL)
		if (ft_getenv(env, env_var, 2) == NULL)
			ft_lstadd_back(&env, ft_lstnew(ft_strdup(env_var)));
	//free(env_var);
}

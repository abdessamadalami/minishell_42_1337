/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:20:23 by ael-asri          #+#    #+#             */
/*   Updated: 2022/06/14 22:11:54 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	conditions_topass(char c)
{
	if ((((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9')) || c == '_') && c != '\0')
			return (1);
	return (0);
}

char	*fill_jma3a(char *s, char *jma3a, int *i, int *lock)
{
	char	*var;
	char	*gg;
	int		j;

	var = malloc(sizeof(char)*9999);
	gg = malloc(sizeof(char)*9999);
	j = 0;
	(*i)++;
	while (conditions_topass(s[*i]))
		var[j++] = s[(*i)++];
	var[j] = '\0';
	if (!getenv(var))
	{
		(*lock) = 0;
		return (jma3a);
	}
	jma3a = ft_strjn(jma3a, getenv(var));
	j = 0;
	while (s[*i] != '$' && s[*i] != '\0')
		gg[j++] = s[(*i)++];
	jma3a = ft_strjn(jma3a, gg);
	if (s[*i] == '$')
		(*lock) = 1;
	else
		(*lock) = 0;
	gg = NULL;
	return (jma3a);
}

char	*putvaluesornot(char *s)
{
	char	*t;
	char	*jma3a;
	int		i;
	int		x;
	int		lock;

	t = malloc(sizeof(char)* (ft_strln(s) + 1));
	jma3a = malloc(sizeof(char)* (ft_strln(s) + 1));
	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		lock = 1;
		if (s[i] == '$')
		{
			jma3a = ft_strjn(jma3a, t);
			while (lock)
				jma3a = fill_jma3a(s, jma3a, &i, &lock);
		}
		else
			t[x++] = s[i++];
	}
	// printf("jma3a %s\n", jma3a);
	t = NULL;
	return (jma3a);
}

void	handle_dollar(t_arg  *sfa, char *s)
{
	t_arg	*node;
	t_arg	*z3ta;
	char	**temp;
	char	*l;
	int		z;

	z = 0;
	z3ta = NULL;
	l = malloc(sizeof(char)*9999);
	temp = (char **)malloc(sizeof(char *)*9999);
	printf("hii %s\n", s);
	temp = dosplit(s, '"');
	if (!temp)
		exit (1);
	for(int r=0;temp[r];r++)
		printf("r %s\n", temp[r]);
	while (temp[z] != NULL)
	{
		if (!check_dollar(temp[z]) && is_there_dq(temp[z]))
		{
			if (putvaluesornot(temp[z]))
			{
				node = ftlstnew(putvaluesornot(temp[z]));
				ftlstadd_back(&z3ta, node);
			}
		}
		else
		{
			node = ftlstnew(temp[z]);
			ftlstadd_back(&z3ta, node);
		}
		if (temp[z + 1] == NULL)
		{
			while (z3ta != NULL)
			{
				l = ft_strjn(l, z3ta->data);
				z3ta = z3ta->next;
			}
			if (l[0] != '\0')
			{
				node = ftlstnew(l);
				ftlstadd_back(&sfa, node);
			}
		}
		z++;
	}
	l = NULL;
}

void	handle_mixed_quotes(t_arg *sfa, char *s)
{
	int		i;
	int		j;
	int		x;
	t_arg	*node;
	char	*t;
	char	*gg;
	char	*var;
	int		lock;
	char	*jma3a;

	j = 0;
	i = 0;
	x = 0;
	lock = 0;
	t = malloc(sizeof(char) * 9999);
	gg = malloc(sizeof(char) * 9999);
	jma3a = malloc(sizeof(char) * 9999);
	var = malloc(sizeof(char) * 9999);
	printf("mal mha hadi %s\n", s);
	while (s[i] != '\0')
	{
		if (s[i] == '$')
		{
			while (!lock)
			{
				i++;
				j = 0;
				while ((((s[i] >= 'a' && s[i] <= 'z')
							|| (s[i] >= 'A' && s[i] <= 'Z')
							|| (s[i] >= '0' && s[i] <= '9'))
						|| s[i] == '_') && s[i] != '\0')
				{
					var[j] = s[i];
					i++;
					j++;
				}
				var[j] = '\0';
				printf("vara %s\n", var);
				if (!getenv(var))
					// exit(1);
					break;
				t = ft_strjn(t, getenv(var));
				printf("t1 %s\n", t);
				jma3a = ft_strjn(jma3a, t);
				j = 0;
				// printf("bbbffd %c\n", s[i+1]);
				while (s[i] != '$' && s[i] != '\0')
				{
					gg[j] = s[i];
					printf("c %c\n", gg[j]);
					i++;
					j++;
				}
				gg[j] = '\0';
				// printf("gg before jma3a %s\n", gg);
				printf("gg -%s-\n", gg);
				jma3a = ft_strjn(jma3a, gg);
				printf("jma3a %s\n", jma3a);
			//	gg = ft_strjn(t, gg);
			//	printf("before quitin %c\n", s[i]);
				if (s[i] == '$')
				{
					t = NULL;
					// var = NULL;
					// gg = NULL;
					lock = 0;
				}
				else
				{
					lock = 1;
					printf("nghyroha %s\n", gg);
				}
			}
			// printf("gg %s\n",  gg);
			i++;
		}
		else
		{
			// t[x] = s[i];
			jma3a[x] = s[i];
		//	printf("t %c\n", t[x]);
			x++;
		}
		i++;
	}
	printf("final gg %s\n", gg);
	node = ftlstnew(jma3a);
	ftlstadd_back(&sfa, node);
	t = NULL;
	gg = NULL;
}
/*
char	*till_dollars(char *s)
{
	char	*t;
	int		i;
	int		j;
	int		lock;

	i = 0;
	j = 0;
	lock = 0;
	t = malloc(sizeof(char) * (ft_strln(s) + 1));
	if (!t)
		exit (1);
	while (s[i] != '\0')
	{
		if (s[i] == '$' && s[i + 1] == '$')
		{
			i++;
			while (s[i] == '$')
			{
				t[j] = s[i];
				i++;
				j++;
			}
			lock = 1;
		}
		else if (lock == 0)
		{
			t[j] = s[i];
			j++;
		}
		i++;
	}
}
*/
int	ds_index(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '$' && s[i + 1] == '$')
		{
			count = i;
			i++;
			while (s[i] == '$' && s[i] != '\0')
				i++;
		}
		i++;
	}
	return (count);
}

char *zawji_dollaring(char *s)
{
	char	*t;
	int		i;

	i = 0;;
	t = malloc(sizeof(char) * (ft_strln(s) + 1));
	if (!t)
		exit (1);
	while (s[i] != '\0')
	{
		if (i == ds_index(s))
		{
			i++;
			break;
		}
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	if (s[i] != '\0')
	{
		int j = 0;
		while (j < lot_ofthem(s))
		{
			t = ft_strjn(t, ft_itoa(getpid()));
			j += 2;
		}
	}
	t = ft_strjn(t, &s[i+(lot_ofthem(s)-1)]);
	return (t);
}

char	*fill_jma3a_forbzzaf(char *s, char *jma3a, int *i, int *lock)
{
	char	*var;
	char	*gg;
	int		j;

	var = malloc(sizeof(char)*9999);
	gg = malloc(sizeof(char)*9999);
	j = 0;
	(*i)++;
	while (conditions_topass(s[*i]))
		var[j++] = s[(*i)++];
	var[j] = '\0';
	printf("var %s\n", getenv(var));
	if (!getenv(var))
	{
		(*lock) = 0;
		// if (jma3a != NULL)
		// 	return (ft_strjn(jma3a, &s[(*i)]));
		// else
			return (s);
	}
	jma3a = ft_strjn(jma3a, getenv(var));
	j = 0;
	while (s[*i] != '$' && s[*i] != '\0')
		gg[j++] = s[(*i)++];
	jma3a = ft_strjn(jma3a, gg);
	if (s[*i] == '$' && s[(*i) + 1] != '$')
		(*lock) = 1;
	else
		(*lock) = 0;
	gg = NULL;
	printf("jjjjma3a %s\n", jma3a);
	return (jma3a);
}

char	*putvaluesornot_forbzzaf(char *s)
{
	char	*t;
	char	*jma3a;
	int		i;
	int		x;
	int		lock;

	t = malloc(sizeof(char)* (ft_strln(s) + 1));
	jma3a = malloc(sizeof(char)* (ft_strln(s) + 1));
	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		lock = 1;
		if (s[i] == '$' && s[i + 1] != '$')
		{
			if (s[i + 1] >= '0' && s[i + 1] <= '9') // echo $$$5gg
				i++;
			printf("hola\n");
			jma3a = ft_strjn(jma3a, t);
			while (lock)
				jma3a = fill_jma3a_forbzzaf(s, jma3a, &i, &lock);
		}
		else
		{
			t[x] = s[i];
			printf("tx %c\n", t[x]);
			x++;
			i++;
		}
	}
	printf("jma3a %s\n", jma3a);
	t = NULL;
	return (jma3a);
}

void	bzzaf_tdollarats(t_arg  *sfa, char *s)
{
	t_arg	*node;
	t_arg	*z3ta;
	char	**temp;
	char	*l;
	int		z;

	z = 0;
	z3ta = NULL;
	l = malloc(sizeof(char)*9999);
	temp = (char **)malloc(sizeof(char *)*9999);
	printf("hii %s\n", s);
	temp = dosplit(s, '"');
	if (!temp)
		exit (1);
	for(int r=0;temp[r];r++)
		printf("r %s\n", temp[r]);
	while (temp[z] != NULL)
	{
		if (!check_dollar(temp[z]) && is_there_dq(temp[z]))
		{
			if (putvaluesornot_forbzzaf(temp[z]))
			{
				node = ftlstnew(putvaluesornot_forbzzaf(temp[z]));
				ftlstadd_back(&z3ta, node);
			}
		}
		else
		{
			node = ftlstnew(temp[z]);
			ftlstadd_back(&z3ta, node);
		}
		if (temp[z + 1] == NULL)
		{
			while (z3ta != NULL)
			{
				l = ft_strjn(l, z3ta->data);
				z3ta = z3ta->next;
			}
			if (l[0] != '\0')
			{
				node = ftlstnew(l);
				ftlstadd_back(&sfa, node);
			}
		}
		z++;
	}
	l = NULL;
}

t_arg	*check_for_dollar(t_arg *arg)
{
	t_arg	*sfa;
	t_arg	*node;

	sfa = NULL;
	while (arg != NULL)
	{
		printf("hadi %d, dyal %s\n", checki_checki(arg->data), arg->data);
		if (!check_dollar_mark(arg->data))
		{
			printf("hadchi khsso ytparssa\n");
			node = ftlstnew(arg->data);
			ftlstadd_back(&sfa, node);
		}
		else if (checki_checki(arg->data))
			handle_mixed_quotes(sfa, arg->data);
		else if (lot_ofthem(arg->data) > 1)
		{
			printf("AH SHIT! HERE WE GO AGAIN!\n");
			bzzaf_tdollarats(sfa, arg->data);
		//	exit(1);
		/*	if (lot_ofthem(arg->data) % 2 == 0)
			{
				printf("zawji w/ value, i mean everythin no convert\n");
			//	printf("-%s-\n", zawji_dollaring(arg->data));
				node = ftlstnew(zawji_dollaring(arg->data));
				ftlstadd_back(&sfa, node);
				// break;
				// exit(1);
			}
			else
			{
				printf("fardi w/ no value, but real value if exists\n");
				node = ftlstnew(arg->data);
				ftlstadd_back(&sfa, node);
			}*/
		}
		else if (/*check_qdollar(arg->data) && */!check_dollar(arg->data) && first_occc(arg->data) != '\'')
			handle_dollar(sfa, arg->data);
		else
		{
			node = ftlstnew(arg->data);
			ftlstadd_back(&sfa, node);
		}
		arg = arg->next;
	}
	return (sfa);
}

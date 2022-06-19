/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:11:46 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/18 10:42:35 by sultan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

static char	*ft_strcat_p(char *dest, const char *src, int position)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (dest[i] != '\0' && position != 0)
		i++;
	while (src[len] != '\0')
	{
		dest[i] = src[len];
		i++;
		len++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_n(char *s1, char *s2)
{
	int		index;
	int		length;
	char	*ptr;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	index = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(length + 1);
	if (ptr == NULL)
		return (0);
	ft_strcat_p(ptr, s1, 0);
	ft_strcat_p(ptr, s2, 1);
	free(s1);
	free(s2);
	s1 = 0;
	s2 = 0;
	return (ptr);
}

void *f(void *ptr)
{
    char *ptr2;
    char *s;
    int i;
    if (ft_strchr(ptr,'=')!= NULL)
    {    
        i =  ft_strchr(ptr, '=') - (char *)ptr;
        s = ft_strdup_n(ptr ,i); 
        ptr2 = ft_strrchr(ptr,'=') + 1;
        ptr2 = ft_strjoin_n(ft_strdup("\"") ,ft_strdup (ptr2));
        ptr2 = ft_strjoin_n(ptr2,ft_strdup("\""));
        ptr2 = ft_strjoin_n(ft_strjoin_n(s,ft_strdup("=")),ptr2);
        return (ptr2);
    }
	return(ptr);
}

void del(void *ptr)
{
	 free(ptr);
}

void print_list(t_list *list,int a)//s= 0 || s=1 print wirh order
{
    while(list != NULL)
    {
        if(ft_strchr(list -> content,'=') && a == 0)
            printf("%s\n", (char *)list->content);
        else if (a == 1 && ft_strchr(list -> content,'=') != NULL) 
            printf("%s \n", (char *)list->content);
        else if(a ==4)
            printf("%d \n", *(int *)list->content);
        else if ( a > 10)
             printf("%s \n", (char *)list->content);
        list = list->next;
    }
}

void print_tab(char **str)
{
    int index = 0;

    while (str[index])
    {
        printf("element %d %s \n", index, str[index]);
        index++;
    }
}

int check_redirec(char *red)
{
    if (red[0] == '>' && red[1] == 0)
        return (1);
    else if (red[0] == '<' && red[1] == 0)
        return (1);
	else if (red[0] == '>' && red[1] == '>' && red[3] == 0)
        return (1);
	return (0);
}

int check_for_pipe(char *str)
{
	if (str[0] == '|' && str[1] == '\0')
		return 1;
	return 0;
}
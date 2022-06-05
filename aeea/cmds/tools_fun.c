/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:11:46 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/05 14:43:35 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

void del(void *ptr)
{
	 free(ptr);
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
        ptr2 = ft_strjoin("\"",ptr2);
        ptr2 = ft_strjoin(ptr2,"\"");
        ptr2 = ft_strjoin(ft_strjoin(s,"="),ptr2);
        return (ptr2);
    }
	return(ptr);
}

void print_list(t_list *list,int a)//s= 0 || s=1 print wirh order
{
    while(list != NULL)
    {
        if(ft_strchr(list -> content,'=') && a == 0)
            printf("%s\n", list->content);
        else if (a == 1 && ft_strchr(list -> content,'=') != NULL) 
            printf("%s \n", list->content);
        else
            printf("%s \n", list->content);
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
    // else if (red[0] == '<' && red[1] == '<' && red[2] == 0)
    //    return (1);
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
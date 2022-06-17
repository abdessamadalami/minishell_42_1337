/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:31:51 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/28 18:23:59 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"
#include <signal.h>
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

char	*ft_strjoin_m(char *s1, char *s2)
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
	return (ptr);
}

void handler_sig()
{
    char *buf = ft_strdup("eloualialami");
    char *buf2 = ft_strdup("abdessamad");
    char *str = ft_strjoin_m(buf,buf2);
    free(str);
}

int main(int argc, char **argv)
{
    handler_sig();
    system("leaks a.out");
    return 0;
    // struct sigaction c;
    // int x;
    // c.sa_handler = &handler_sig;
    // c.sa_flags = SA_RESTART;
    // sigaction(SIGINT,&c, NULL);
    // printf("%d",x); 
    // printf("nbr \n");
    // scanf("%d",&x);
   
}
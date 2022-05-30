/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identi_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:05:44 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/25 08:59:18 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

// void error_handling(char *str, int p)
// {
//     int i;
    
//     i = 0;
//     if (!str)
//         return;
//     if (p != 0)
//         i = p;
//     if (str[0] == '$' && p == 0)  // for dolar handling
//         i++;
//     if ((!ft_isalnum(str[i])) && str[i] != '_')
//     {
//         printf("error: `%s': not a valid identifier \n",str);// we need cmd 
//         exit(1); // chiled
//     } 
// }
void error_handling(char *str, int p)
{
    int i;
    
    i = 0;
    if (!str)
        return;
    if (p != 0)
        i = p;
    if (str[0] == '$' && p == 0)  // for dolar handling
    {
        i++;
    } 
    if ((!ft_isalnum(str[i])) && str[i] != '_' && str[i] != '+')
    {
        printf("error: `%s': not a valid identifier \n",str);// we need cmd
        exit(1); // chiled
    }
}
// int main(int argc, char **argv , char **env)
// {
//     char *cmd;
//     char *eng[3];
//     eng[0] = "ls";
//     eng[1] = "-ls";
//     eng[2] = 0;
//      //execve("/bin/ls",eng,0);
// }
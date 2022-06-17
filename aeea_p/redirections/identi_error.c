/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identi_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:05:44 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/16 13:34:04 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"

int error_handling(char *str, int p)
{
    int i;
    
    i = 0;
    if (!str)
        return 0;
    if (p != 0)
        i = p;
    if (str[0] == '$' && p == 0)  // for dolar handling
        i++;
    if ((!ft_isalnum(str[i])) && str[i] != '_' && str[i] != '+')
    {
        e_st = 1;
        printf("error: `%s': not a valid identifier \n",str);// we need cmd
        return 1;
    }
    return 0;
}

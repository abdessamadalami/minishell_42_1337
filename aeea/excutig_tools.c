/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excutig_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:12:50 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/30 16:24:36 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "excuting_headr.h"

int pip_number(t_list *list)
{
    int index;
    char *str;

    index = 0;
    while(list)
    {
        str = list->content;
        if (str[0] == '|' && str[1] == '\0')
            index++;
        list = list ->next;
    }
    return (index);
}

void wait_exit_status(int *ids, int n_p)
{
    int i;
    int exit_s;

    i = 0;
    while (i <= n_p)
    {
        waitpid(ids[i],&exit_s, 0);
        if (WIFEXITED(exit_s))
            e_st = WEXITSTATUS(exit_s);
        i++;
    }
}

void close_aff(t_var *v_pipe)
{
    close(v_pipe->fd[1]);
    if (v_pipe->to_close)
        close(v_pipe->to_close);
    v_pipe->std_in = v_pipe->fd[0];
    v_pipe->to_close = v_pipe->std_in;
}

int dup_parm(t_list **pars_il, int *fd)
{
    t_list *lst;
    int a;
    
    lst = make_list_fork(*pars_il);
        if (lst == NULL)
            return 0;
    *pars_il = lst;
    return 1;
}
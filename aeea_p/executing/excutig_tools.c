/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excutig_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:12:50 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/16 13:48:45 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../excuting_headr.h"


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

int dup_parm(t_list **pars_il, int *fd, t_list **std_in)
{
    t_list *lst;
    static int a;

    printf("dup_parm %d\n", *fd);
    // char buf[100];
    // int k = read(*fd, buf, sizeof(buf));

    
    lst = make_list_fork(*pars_il);
    if (*std_in != NULL)
    {
        if (*(int *)(*std_in) -> content != -1 && 
         *(int *)(*std_in) -> content != 0
        )
        {
            printf(" fdf %d \n", *(int *)(*std_in) -> content);
            close(*fd);
            *fd = *(int *)(*std_in) -> content;
        }
        // if (*(int *)(*std_in) -> content == -1)
        // {
        //    // lst = make_list_fork(lst);
        //     printf("std in -1 %d\n", *fd);
        //     	print_list(lst,23);
        // }
        if((*std_in) -> next != NULL)
            *std_in = (*std_in) -> next;
    }
    printf("std in -1 %d\n",*fd);
    //  printf(" %d std_in of pipe %d\n", a , *fd);
    // print_list(lst, 434);
    a++;
    *pars_il = lst;
    // char buf[100];
    // int k = read(*fd, buf, sizeof(buf));
    // buf[k] = '\0';
    // printf("%s \n",buf);
    
    if (lst != NULL)
        return 1;
    return 0;
}
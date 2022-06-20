/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excutig_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:12:50 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/20 12:54:30 by sultan           ###   ########.fr       */
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

void make_ne(t_list **pars_il, t_list **fds_std_in)
{
    while(1)
	{
		if (*pars_il == NULL)
			break;
		if (*(int *)(*fds_std_in) -> content != -1)
		{
            printf("the content of node is = %d\n", *(int *)(*fds_std_in) -> content);
			if ((*fds_std_in) -> next != NULL)
				    (*fds_std_in) = (*fds_std_in)->next;
           // ft_lstadd_front(fds_std_in,ft_lstnew("|"));
			break;
		}
		else
		{
				printf("warning\n");
                if (*fds_std_in != NULL) 
				    (*fds_std_in) = (*fds_std_in)->next;
                if (*pars_il == NULL)
                {
			        break;
                }
				*pars_il = make_list_fork(*pars_il);
                
		}
	}
  //  printf(" in the new function ");
    if (*pars_il == NULL)
        printf(" null \n");
    else
        print_list(*pars_il , 434);
}

int dup_parm(t_list **pars_il, int *fd, t_list **std_in)
{
    t_list *lst;
    //int fd[2];
   static int a;
    

    printf(" the std in  %d\n", *fd);
    // char buf[100];
    // int k = read(*fd, buf, sizeof(buf));
    lst = make_list_fork(*pars_il);
    if (lst == NULL)
            return 0;     
    if (*std_in != NULL)
    {
        if (*(int *)(*std_in) -> content != 0)
        {
            printf(" std_in becaam  %d \n", *(int *)(*std_in) -> content);
           // close(*fd);
            *fd = *(int *)(*std_in) -> content;
            if((*std_in) -> next) 
                *std_in = (*std_in) -> next;
        }
        if (*(int *)(*std_in) -> content == 0)
        {
            if ((*std_in) -> next != NULL)
                    *std_in = (*std_in) -> next;
            else
                *std_in = 0;
        }       
    }
    *pars_il = lst;
}
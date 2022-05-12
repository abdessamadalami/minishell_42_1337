/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:41:41 by ael-oual          #+#    #+#             */
/*   Updated: 2022/05/11 19:43:13 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
#include<stdio.h>
#include "../pipex/pipex_42_1337.h"
#include "../libft/libft.h"

void std_files(char *std_out, int fd);//minishell intra video
void	here_doc(char **argc);
#endif
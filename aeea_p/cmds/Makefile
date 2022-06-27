# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/06/27 11:19:50 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BS = c_exit.c ft_pwd.c chec_for_cmds.c merg_sort.c c_cd.c c_export.c exit_status.c tools_fun.c biulding_cmd_x.c c_env.c c_unset.c get_path_env.c ft_echo.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
OBJB = $(BS:.c=.o)
all: $(OBJB)
clean: 
	rm -f $(OBJB)
fclean:clean
re: fclean all

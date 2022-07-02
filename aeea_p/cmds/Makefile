# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/07/02 12:31:51 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BS = get_env.c c_exit.c ft_pwd.c chec_for_cmds.c merg_sort.c c_cd.c c_export.c exit_status.c tools_fun.c biulding_cmd_x.c c_env.c c_unset.c get_path_env.c ft_echo.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = cmds.a
OBJB = $(BS:.c=.o)
all: $(OBJB)
	ar -rc $(NAME) $(OBJB) 
clean: 
	rm -f $(OBJB)
fclean:clean
re: fclean all

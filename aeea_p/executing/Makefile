# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/06/26 20:00:09 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BS = argv_parm.c errors_d.c excutig_tools.c executing.c pipe_f.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJB = $(BS:.c=.o)
all: $(OBJB)
clean: 
	rm -f $(OBJB)
fclean:clean
re: fclean all

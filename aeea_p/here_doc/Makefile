# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sultan <sultan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/06/26 10:55:45 by sultan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BS = delete_heredoc.c here_doc.c tools_fun.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJB = $(BS:.c=.o)
all: $(OBJB)
clean: 
	rm -f $(OBJB)
fclean:clean
re: fclean all
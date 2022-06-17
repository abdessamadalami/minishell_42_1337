# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/06/16 08:22:34 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BS =  ft_strlen_bonus.c help_fun_bonus.c ft_strncmp_bonus.c ft_putchar_fd_bonus.c ft_putstr_fd_bonus.c ft_split_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
NAME2 = pipex_bonus
OBJB = $(BS:.c=.o)
all: $(NAME2)
$(NAME2): $(OBJB)
clean: 
	rm -f $(OBJB)
fclean:clean
	rm -f $(NAME) $(NAME2)
re:  fclean all

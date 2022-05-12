# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/05/11 07:04:34 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  mondatory/ft_strlen.c   mondatory/get_next_line_utils.c mondatory/help_fun.c mondatory/ft_strncmp.c  mondatory/ft_putchar_fd.c mondatory/ft_putstr_fd.c  mondatory/ft_split.c mondatory/main.c mondatory/pipex_42_1337.c
BS =  ft_strlen_bonus.c help_fun_bonus.c ft_strncmp_bonus.c   ft_putchar_fd_bonus.c ft_putstr_fd_bonus.c ft_split_bonus.c main_bonns.c pipex_42_1337_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
NAME2 = pipex_bonus
OBJ = $(SRC:.c=.o)
OBJB = $(BS:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
bonus: $(NAME2)
$(NAME2): $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $(NAME2)
clean: 
	rm -f $(OBJ) $(OBJB)
fclean:clean
	rm -f $(NAME) $(NAME2)
re:  fclean bonus all

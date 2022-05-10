# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/05/10 07:44:40 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  redirections/main.c pipx/bonus/*.c libft/*.c 
BS =  bonus/ft_strlen_bonus.c bonus/help_fun_bonus.c bonus/ft_strncmp_bonus.c   bonus/ft_putchar_fd_bonus.c bonus/ft_putstr_fd_bonus.c  bonus/ft_split_bonus.c bonus/main_bonns.c bonus/pipex_42_1337_bonus.c bonus/get_next_line_utils_bonus.c bonus/get_next_line_bonus.c
CC = gcc
CFsLAGS = -Wall -Wextra -Werror
NAME = minishell
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/05/26 18:39:17 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = redirections/input.c redirections/output.c redirections/g_redirections.c redirections/here_doc.c redirections/identi_error.c redirections/pipe_tools.c redirections/var_remplace.c
BS =  bonus/ft_strlen_bonus.c bonus/help_fun_bonus.c bonus/ft_strncmp_bonus.c  bonus/ft_putchar_fd_bonus.c bonus/ft_putstr_fd_bonus.c  bonus/ft_split_bonus.c bonus/main_bonns.c bonus/pipex_42_1337_bonus.c bonus/get_next_line_utils_bonus.c bonus/get_next_line_bonus.c
CC = gcc 
CFsLAGS = -Wall -Wextra -Werror
NAME = minishell
NAME2 = pipex_bonus
OBJ = $(SRC:.c=.o)
OBJB = $(BS:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) *.c cmds/*.c libft/*.o pipex/*.o -lreadline -L /goinfre/$(USER)/.brew/opt/readline/lib -I /goinfre/$(USER)/.brew/opt/readline/include -o $(NAME)
bonus: $(NAME2)
$(NAME2): $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $(NAME2)
clean: 
	rm -f $(OBJ) $(OBJB)
fclean:clean
	rm -f $(NAME) $(NAME2)
re:  fclean bonus all

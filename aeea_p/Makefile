# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sultan <sultan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/06/25 19:57:42 by sultan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  here_doc/here_doc.c  here_doc/delete_heredoc.c ar -rc $(NAME) redirections/*.o pipex/*.o libft/*.o cmds/*.o here_doc/*.o executing/*.o

CFLAsdGS = -Wall -Wextra -Werror #-fsanitize=address -g
CC = gcc 
CFsLAGS = -Wall -Wextra -Werror
NAME = minishell.a
all: $(NAME)
$(NAME):
		cd redirections && make;
		cd pipex && make;
		cd libft && make;
		cd cmds && make;
		cd here_doc && make;
		cd executing && make;
	cc $(CFLAGS) main_aeea.c redirections/*.o pipex/*.o libft/*.o cmds/*.o here_doc/*.o executing/*.o -lreadline -L /usr/local/opt/readline/lib/include -I /usr/local/opt/readline/lib/include  -o $(NAME)
clean:
	cd pipex && make clean;
	cd libft && make clean;
	cd cmds && make clean;
	cd here_doc && make clean;
	cd executing && make clean;
	cd redirections && make clean;
	rm -f $(OBJS)
fclean:clean
	rm -f $(NAME)
re:  fclean bonus all

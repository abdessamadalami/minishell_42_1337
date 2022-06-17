# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/06/16 12:11:53 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BS = g_redirections.c here_doc.c identi_error.c input.c output.c pipe_tools.c tests.c var_remplace.c
CC = gcc
CFkLAGS = -Wall -Wextra -Werror
OBJB = $(BS:.c=.o)
all: $(OBJB)
clean: 
	rm -f $(OBJB)
fclean:clean
re: fclean all

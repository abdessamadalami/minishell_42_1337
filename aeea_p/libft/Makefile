# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sultan <sultan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/06/25 15:46:21 by sultan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c    ft_isalpha.c ft_memchr.c  ft_memset.c  ft_strlcat.c ft_strnstr.c ft_bzero.c   ft_isascii.c ft_memcmp.c  ft_strchr.c  ft_strlcpy.c ft_strrchr.c ft_itoa.c ft_isdigit.c ft_memcpy.c ft_isalnum.c ft_isprint.c ft_memmove.c ft_tolower.c ft_toupper.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putendl_fd.c ft_putnbr_fd.c
BS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
OBJ = $(SRC:.c=.o)
OBJB = $(BS:.c=.o)
all: $(OBJ) $(OBJB)
clean: 
	rm -f $(OBJ) $(OBJB)
fclean:clean
re:fclean all

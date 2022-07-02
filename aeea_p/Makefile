# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/07/02 13:39:23 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	
#  here_doc/here_doc.o  here_doc/delete_heredoc.o ar -rc $(NAME) redirections/*.o pipex/*.o libft/*.o cmds/*.o here_doc/*.o executing/*.o | gcc  main_aeea.o redirections/*.o pipex/*.o libft/*.o cmds/*.o here_doc/*.o executing/*.o -lreadline -L /goinfre/$(USER)/.brew/opt/readline/lib -I/goinfre/$(USER)/.brew/opt/readline/include
cmd = cmds/get_env.o cmds/c_exit.o cmds/ft_pwd.o cmds/chec_for_cmds.o cmds/merg_sort.o cmds/c_cd.o cmds/c_export.o cmds/exit_status.o cmds/tools_fun.o cmds/biulding_cmd_x.o cmds/c_env.o cmds/c_unset.o cmds/get_path_env.o cmds/ft_echo.o
excu = executing/argv_parm.o executing/errors_d.o executing/excutig_tools.o executing/executing.o executing/pipe_f.o
here = here_doc/delete_heredoc.o here_doc/here_doc.o here_doc/tools_fun.o
red = redirections/g_redirections.o redirections/here_doc.o redirections/identi_error.o redirections/input.o redirections/output.o redirections/pipe_tools.o redirections/var_remplace.o
lib = libft/ft_atoi.o libft/ft_memchr.o libft/ft_bzero.o libft/ft_memcmp.o libft/ft_isalnum.o libft/ft_memcpy.o libft/ft_isalpha.o libft/ft_memmove.o libft/ft_isascii.o libft/ft_memset.o libft/ft_isdigit.o libft/ft_putendl_fd.o libft/ft_isprint.o libft/ft_putnbr_fd.o libft/ft_itoa.o	libft/ft_strchr.o libft/ft_lstadd_back_bonus.o libft/ft_striteri.o libft/ft_lstadd_front_bonus.o libft/ft_strlcat.o libft/ft_lstclear_bonus.o libft/ft_strlcpy.o libft/ft_lstdelone_bonus.o libft/ft_strmapi.o libft/ft_lstiter_bonus.o libft/ft_strnstr.o libft/ft_lstlast_bonus.o libft/ft_strrchr.o libft/ft_lstmap_bonus.o libft/ft_strtrim.o libft/ft_lstnew_bonus.o libft/ft_tolower.o libft/ft_lstsize_bonus.o libft/ft_toupper.o
pipe = pipex/ft_strlen_bonus.o pipex/help_fun_bonus.o pipex/ft_strncmp_bonus.o pipex/ft_putchar_fd_bonus.o pipex/ft_putstr_fd_bonus.o pipex/ft_split_bonus.o pipex/get_next_line_utils_bonus.o

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
		ar -rc $(NAME) $(cmd) $(excu) $(here) $(red) $(lib) $(pipe) 
clean:
	cd pipex && make clean;
	cd libft && make clean;
	cd cmds && make clean;
	cd here_doc && make clean;
	cd executing && make clean;
	cd redirections && make clean;
	rm -f $(NAME)
fclean:clean
	rm -f $(NAME)
re:  fclean bonus all

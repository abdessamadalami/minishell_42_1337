# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 14:09:14 by ael-asri          #+#    #+#              #
#    Updated: 2022/07/01 17:04:17 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

GG = aeea_p/here_doc/delete_heredoc.c\
		aeea_p/here_doc/here_doc.c\
		aeea_p/here_doc/tools_fun.c\
		aeea_p/redirections/g_redirections.c\
		aeea_p/redirections/here_doc.c\
		aeea_p/redirections/identi_error.c\
		aeea_p/redirections/input.c\
		aeea_p/redirections/output.c\
		aeea_p/redirections/pipe_tools.c\
		aeea_p/redirections/var_remplace.c\
		aeea_p/libft/ft_atoi.c\
		aeea_p/libft/ft_memchr.c\
		aeea_p/libft/ft_bzero.c\
		aeea_p/libft/ft_memcmp.c\
		aeea_p/libft/ft_isalnum.c\
		aeea_p/libft/ft_memcpy.c\
		aeea_p/libft/ft_isalpha.c\
		aeea_p/libft/ft_memmove.c\
		aeea_p/libft/ft_isascii.c\
		aeea_p/libft/ft_memset.c\
		aeea_p/libft/ft_isdigit.c\
		aeea_p/libft/ft_putendl_fd.c\
		aeea_p/libft/ft_isprint.c\
		aeea_p/libft/ft_putnbr_fd.c\
		aeea_p/libft/ft_itoa.c\
		aeea_p/libft/ft_strchr.c\
		aeea_p/libft/ft_lstadd_back_bonus.c\
		aeea_p/libft/ft_striteri.c\
		aeea_p/libft/ft_lstadd_front_bonus.c\
		aeea_p/libft/ft_strlcat.c\
		aeea_p/libft/ft_lstclear_bonus.c\
		aeea_p/libft/ft_strlcpy.c\
		aeea_p/libft/ft_lstdelone_bonus.c\
		aeea_p/libft/ft_strmapi.c\
		aeea_p/libft/ft_lstiter_bonus.c\
		aeea_p/libft/ft_strnstr.c\
		aeea_p/libft/ft_lstlast_bonus.c\
		aeea_p/libft/ft_strrchr.c\
		aeea_p/libft/ft_lstmap_bonus.c\
		aeea_p/libft/ft_strtrim.c\
		aeea_p/libft/ft_lstnew_bonus.c\
		aeea_p/libft/ft_tolower.c\
		aeea_p/libft/ft_lstsize_bonus.c\
		aeea_p/libft/ft_toupper.c\
		aeea_p/pipex/ft_strlen_bonus.c\
		aeea_p/pipex/help_fun_bonus.c\
		aeea_p/pipex/ft_strncmp_bonus.c\
		aeea_p/pipex/ft_putchar_fd_bonus.c\
		aeea_p/pipex/ft_putstr_fd_bonus.c\
		aeea_p/pipex/ft_split_bonus.c\
		aeea_p/pipex/get_next_line_utils_bonus.c\

SRCS =  minishell.c\
		parsing/utils/minishell_utils.c\
		parsing/utils/minishell_utils2.c\
		parsing/utils/minishell_utils3.c\
		parsing/utils/minishell_list_utils.c\
		parsing/utils/minishell_list_utils2.c\
		parsing/errors/minishell_erroring.c\
		parsing/utils/splits/sosplit.c\
		parsing/utils/splits/dosplit.c\
		parsing/utils/splits/wildsplit.c\
		parsing/utils/splits/splits_utils.c\
		parsing/utils/parsing_utils.c\
		parsing/utils/parsing_utils2.c\
		parsing/parsing.c\
		parsing/parsing_spaces/parsing_spaces.c\
		parsing/parsing_spaces/parsing_spaces_utils.c\
		parsing/parsing_wildcard/parsing_wildcard.c\
		parsing/parsing_wildcard/parsing_wildcard_utils.c\
		parsing/parsing_wildcard/parsing_wildcard_utils2.c\
		parsing/parsing_quotes/parsing_quotes.c\
		parsing/parsing_quotes/parsing_quotes_utils.c\
		parsing/parsing_so/parsing_soperators.c\
		parsing/parsing_so/parsing_soperators_utils.c\
		parsing/env_variables/env_variables.c\
		parsing/env_variables/env_variables_utils.c\
		parsing/env_variables/env_variables_utils2.c\
		parsing/syntax_checking/parsing_syntax.c\
		parsing/syntax_checking/check_pip/pip_syntax.c\
		parsing/syntax_checking/check_qt/qt_syntax.c\
		parsing/syntax_checking/check_qt/qt_syntax_utils.c\
		parsing/syntax_checking/check_red/red_syntax.c\
		aeea_p/cmds/get_env.c\
		aeea_p/cmds/c_exit.c\
		aeea_p/cmds/ft_pwd.c\
		aeea_p/cmds/chec_for_cmds.c\
		aeea_p/cmds/merg_sort.c\
		aeea_p/cmds/c_cd.c\
		aeea_p/cmds/c_export.c\
		aeea_p/cmds/exit_status.c\
		aeea_p/cmds/tools_fun.c\
		aeea_p/cmds/biulding_cmd_x.c\
		aeea_p/cmds/c_env.c\
		aeea_p/cmds/c_unset.c\
		aeea_p/cmds/get_path_env.c\
		aeea_p/cmds/ft_echo.c\
		aeea_p/executing/argv_parm.c\
		aeea_p/executing/errors_d.c\
		aeea_p/executing/excutig_tools.c\
		aeea_p/executing/executing.c\
		aeea_p/executing/pipe_f.c
		

OBJS = $(SRCS:.c=.o)
GOBJS = $(GG:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
export LDFLAGS="-L/goinfre/ael-asri/.brew/opt/readline/lib"
export CPPFLAGS="-I/goinfre/ael-asri/.brew/opt/readline/include"
$(NAME): $(OBJS) $(GOBJS)
		cc $(CFLAGS) $(OBJS) $(GOBJS) -lreadline -L /goinfre/$(USER)/.brew/opt/readline/lib -I /goinfre/$(USER)/.brew/opt/readline/include -o $(NAME)
clean:
	rm -f $(OBJS) $(GOBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

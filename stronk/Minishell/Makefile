NAME = minishell

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
		parsing/syntax_checking/parsing_syntax.c\
		parsing/syntax_checking/check_pip/pip_syntax.c\
		parsing/syntax_checking/check_qt/qt_syntax.c\
		parsing/syntax_checking/check_qt/qt_syntax_utils.c\
		parsing/syntax_checking/check_red/red_syntax.c\

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJS)
		cc $(CFLAGS) -lreadline -L /goinfre/$(USER)/.brew/opt/readline/lib -I/goinfre/$(USER)/.brew/opt/readline/include $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
NAME = minishell

SRCS =  minishell.c\
		utils/minishell_utils.c\
		utils/minishell_utils2.c\
		utils/minishell_list_utils.c\
		utils/minishell_erroring.c\
		utils/ssplit/ssplit.c\
		utils/ssplit/sosplit.c\
		utils/ssplit/qusplit.c\
		utils/ssplit/squsplit.c\
		utils/ssplit/wildsplit.c\
		parsing/parsing.c\
		parsing/parsing_spaces.c\
		parsing/parsing_wildcard.c\
		parsing/parsing_quotes.c\
		parsing/parsing_soperators.c\
		parsing/parsing_utils.c\
		parsing/parsing_syntax.c\

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
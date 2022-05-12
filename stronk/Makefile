NAME = minishell

SRCS =  minishell.c\
		utils/minishell_utils.c\
		utils/get_path.c\
		utils/ssplit/ssplit.c\
		parsing/parsing.c\
	
		

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		cc $(CFLAGS) -lreadline -L /goinfre/$(USER)/.brew/opt/readline/lib -I/goinfre/$(USER)/.brew/opt/readline/include $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
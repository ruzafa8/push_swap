SRCS		= src/parse_args.c src/stack.c src/utils.c\
			  src/list_instr.c src/simple_resolver.c\
			  src/longest_increasing_subsequence.c\
			  src/greedy_sort.c src/less_5_resolver.c src/parse.c\
			  src/delete_stack.c
SRCS_BONUS	= src/read_instr_bonus.c
OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}
NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
RM			= rm -f

all: $(NAME)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

libft:
	make bonus -C ./libft

$(NAME): libft $(OBJS) main.o
	$(CC) $(CFLAGS) $(OBJS) main.o -o $(NAME) -lft -Llibft

clean:
	make clean -C ./libft
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) main.o checker.o

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) checker

re: fclean all

bonus: all $(OBJS_BONUS) checker.o
	make bonus -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) checker.o -o checker -lft -Llibft
	

.PHONY: all clean fclean re bonus libft

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

libft.a:
	make -C ./libft
	cp libft/libft.a libft.a

$(NAME): libft.a $(OBJS) main.o
	$(CC) $(CFLAGS) $(OBJS) main.o -o $(NAME) -lft -L.

clean:
	make clean -C ./libft
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) main.o checker.o

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) checker

re: fclean all

checker: libft.a ${OBJS} $(OBJS_BONUS) checker.o
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) checker.o -o checker -lft -L.

bonus: checker

.PHONY: all clean fclean re bonus

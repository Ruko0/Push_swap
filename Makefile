CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = operations.c operations2.c operations3.c parsing.c \
       stack_operations.c stack_utils.c stack_init.c \
       algorithm.c target_node.c target_init.c moves.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) main.c
	$(CC) $(CFLAGS) main.c $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
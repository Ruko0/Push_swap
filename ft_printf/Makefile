NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f


SOURCES =  ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_put_u_nbr_fd.c base_16.c c_hex.c c_int.c c_Uint.c ft_printf.c get_Pguts.c P_print.c
    

OBJECTS = $(SOURCES:.c=.o)

ARCHV = ar rcs


all: $(NAME)

$(NAME): $(OBJECTS)
	$(ARCHV) $(NAME) $(OBJECTS)



%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(OBJECTSBONUS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: clean

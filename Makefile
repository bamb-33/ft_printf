CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PRINTF_FILES = ft_print_hex.c ft_printadd.c ft_printf.c ft_u_putnbr.c \
						ft_strncmp.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_strlen.c
O_LIBFT_PRINTF_FILES = $(LIBFT_PRINTF_FILES:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(O_LIBFT_PRINTF_FILES)
	ar -rcs $(NAME) $(O_LIBFT_PRINTF_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(O_LIBFT_PRINTF_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
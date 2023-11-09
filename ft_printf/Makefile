NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c \
	  ft_printchar.c \
      ft_printstring.c \
	  ft_printpointer.c \
	  ft_printdecimal.c \
	  ft_print_positive_num.c \
	  ft_printunsigned.c \
	  ft_print_lower_hex.c \
	  ft_print_upper_hex.c

# srcファイルへのパスを含む
OBJS = $(addprefix src/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

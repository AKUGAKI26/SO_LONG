NAME = so_long

SRC = main.c parsing1.c parsing2.c get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# Assuming you have a libft directory with its own Makefile
LIBFT_DIR = libft

all: $(NAME)

$(NAME): $(OBJ) 
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
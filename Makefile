NAME = push_swap
# cc main.c tester.c operations.c sor*.c utils/* libft/libft.a

DIR_LIBFT = libft/
LIBFT = $(DIR_LIBFT)libft.a
DIR_UTILS = utils/

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft

SRC = main.c operations.c
UTILS = arr_append.c arr_issorted.c arr_prepend.c arr_remove.c \
arr_create.c arr_populate.c arr_print.c arr_shuffle.c swap_int.c
OBJ = $(SRC:.c=.o)

# Commands --------------------------------------------------------------------

all: $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(DIR_LIBFT)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(DIR_LIBFT)

re: fclean all

.PHONY: all clean fclean re

# Files -----------------------------------------------------------------------

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)
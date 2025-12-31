NAME = push_swap
# cc main.c operations.c sor*.c utils/* libft/libft.a

DIR_LIBFT = libft/
LIBFT = $(DIR_LIBFT)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft

SRC = arr_append.c arr_create.c arr_free.c arr_issorted.c arr_populate.c \
arr_prepend.c arr_print.c arr_remove.c arr_shuffle.c main.c operations.c \
sort.c sort3.c sort5.c sort_radix.c swap_int.c swap_ptr.c to_ranks.c
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

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)
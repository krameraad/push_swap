NAME = push_swap

DIR_LIBFT = libft/
LIBFT = $(DIR_LIBFT)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft

SRC = arr_append.c arr_create.c arr_free.c arr_issorted.c \
arr_populate.c arr_prepend.c arr_remove.c main.c operations.c \
sort.c sort3.c sort5.c sort_radix.c swap_int.c swap_ptr.c to_ranks.c
OBJ = $(SRC:.c=.o)

# Commands --------------------------------------------------------------------

all: $(DIR_OBJ) $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(DIR_LIBFT)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(DIR_LIBFT)

re: fclean all

test: all
	sh test0.sh
	sh test3.sh
	sh test5.sh
	sh test100.sh
	sh test500.sh

.PHONY: all clean fclean re test

# Files -----------------------------------------------------------------------

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)
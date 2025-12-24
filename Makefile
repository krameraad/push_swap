NAME = push_swap

DIR_LIBFT = libft/
LIBFT = $(DIR_LIBFT)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft

SRC = main.c operations.c
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
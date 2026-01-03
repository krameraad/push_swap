NAME = push_swap

DIR_LIBFT = libft/
LIBFT = $(DIR_LIBFT)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft

SRC = main.c operations.c check_badchar.c check_dupes.c \
arr_append.c arr_create.c arr_free.c arr_issorted.c \
arr_populate.c arr_prepend.c arr_remove.c \
sort.c sort3.c sort5.c sort_radix.c swap_int.c swap_ptr.c to_ranks.c
OBJ = $(SRC:.c=.o)

# Tests -----------------------------------------------------------------------

CHECKER = checker_linux
TEST_3 = "2 1 0"
TEST_5 = "1 5 2 4 3"
ARGGEN = arg_gen
NUM_TESTS = 5
SEED = $(shell date +%s)

# Commands --------------------------------------------------------------------

all: $(OBJ) $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(DIR_LIBFT)

fclean: clean
	rm -f $(NAME) $(ARGGEN)
	$(MAKE) fclean -C $(DIR_LIBFT)

re: fclean all

test: test_error test_identity test_3 test_5 test_100 test_500

test_error: all $(ARGGEN)
	@echo "\033[1;4;44m\n\tTest: non-numeric arguments\033[0m"
	./$(NAME) "0 1 a"
	./$(NAME) "0 a 2"
	./$(NAME) "a 1 2"
	@echo "\033[1;4;44m\n\tTest: duplicates\033[0m"
	./$(NAME) "0 1 1"
	./$(NAME) "0 0 2 3 4"
	./$(NAME) "0 1 2 3 2"
	@echo "\033[1;4;44m\n\tTest: argument too big\033[0m"
	./$(NAME) "0 1 2 3000000000 4"
	@echo "\033[1;4;44m\n\tTest: no arguments\033[0m"
	./$(NAME)

test_identity: all $(ARGGEN)
	@echo "\033[1;4;44m\n\tTest: identity\033[0m"
	./$(NAME) "42"
	./$(NAME) "2 3"
	./$(NAME) "0 1 2 3"
	./$(NAME) "0 1 2 3 4 5 6 7 8 9"
	./$(NAME) "$(shell ./arg_gen -s 10 -p 1 -d 50)"
	./$(NAME) "$(shell ./arg_gen -s 10 -p 2 -d 150)"
	./$(NAME) "$(shell ./arg_gen -s 10 -p 3 -d 250)"

test_3: all $(ARGGEN)
	@echo "\033[1;4;44m\n\tTest: 3\033[0m"
	./$(NAME) $(TEST_3) | ./$(CHECKER) $(TEST_3)
	./$(NAME) $(TEST_3) | wc -l
	./$(NAME) "$(shell ./arg_gen -s 3 -p 4 -d 10 -r)" | ./$(CHECKER) "$(shell ./arg_gen -s 3 -p 4 -d 10 -r)"
	./$(NAME) "$(shell ./arg_gen -s 3 -p 4 -d 10 -r)" | wc -l
	./$(NAME) "$(shell ./arg_gen -s 3 -p 5 -d 10 -r)" | ./$(CHECKER) "$(shell ./arg_gen -s 3 -p 5 -d 10 -r)"
	./$(NAME) "$(shell ./arg_gen -s 3 -p 5 -d 10 -r)" | wc -l
	./$(NAME) "$(shell ./arg_gen -s 3 -p 6 -d 10 -r)" | ./$(CHECKER) "$(shell ./arg_gen -s 3 -p 6 -d 10 -r)"
	./$(NAME) "$(shell ./arg_gen -s 3 -p 6 -d 10 -r)" | wc -l

test_5: all $(ARGGEN)
	@echo "\033[1;4;44m\n\tTest: 5\033[0m"
	./$(NAME) $(TEST_5) | ./$(CHECKER) $(TEST_5)
	./$(NAME) $(TEST_5) | wc -l
	./$(NAME) "$(shell ./arg_gen -s 5 -p 7 -d 50 -r)" | ./$(CHECKER) "$(shell ./arg_gen -s 5 -p 7 -d 50 -r)"
	./$(NAME) "$(shell ./arg_gen -s 5 -p 7 -d 50 -r)" | wc -l
	./$(NAME) "$(shell ./arg_gen -s 5 -p 8 -d 50 -r)" | ./$(CHECKER) "$(shell ./arg_gen -s 5 -p 8 -d 50 -r)"
	./$(NAME) "$(shell ./arg_gen -s 5 -p 8 -d 50 -r)" | wc -l
	./$(NAME) "$(shell ./arg_gen -s 5 -p 9 -d 50 -r)" | ./$(CHECKER) "$(shell ./arg_gen -s 5 -p 9 -d 50 -r)"
	./$(NAME) "$(shell ./arg_gen -s 5 -p 9 -d 50 -r)" | wc -l

test_100: all $(ARGGEN)
	@echo "\033[1;4;44m\n\tTest: 100\033[0m"
	@echo "Commands omitted for visual clarity"
	@./$(NAME) "$(shell ./arg_gen -s 100 -p 10 -d 10 -r)" | ./$(CHECKER) "$(shell ./arg_gen -s 100 -p 10 -d 10 -r)"
	@./$(NAME) "$(shell ./arg_gen -s 100 -p 10 -d 10 -r)" | wc -l
	@./$(NAME) "$(shell ./arg_gen -s 100 -p 11 -d 10 -r)" | ./$(CHECKER) "$(shell ./arg_gen -s 100 -p 11 -d 10 -r)"
	@./$(NAME) "$(shell ./arg_gen -s 100 -p 11 -d 10 -r)" | wc -l
	@./$(NAME) "$(shell ./arg_gen -s 100 -p 12 -d 10 -r)" | ./$(CHECKER) "$(shell ./arg_gen -s 100 -p 12 -d 10 -r)"
	@./$(NAME) "$(shell ./arg_gen -s 100 -p 12 -d 10 -r)" | wc -l
	
test_500: all $(ARGGEN)
	@echo "\033[1;4;44m\n\tTest: 500\033[0m"
	@echo "Commands omitted for visual clarity"
	@./$(NAME) "$(shell ./arg_gen -s 500 -p 13 -d 5 -r)" | ./$(CHECKER) "$(shell ./arg_gen -s 500 -p 13 -d 5 -r)"
	@./$(NAME) "$(shell ./arg_gen -s 500 -p 13 -d 5 -r)" | wc -l
	@./$(NAME) "$(shell ./arg_gen -s 500 -p 14 -d 5 -r)" | ./$(CHECKER) "$(shell ./arg_gen -s 500 -p 14 -d 5 -r)"
	@./$(NAME) "$(shell ./arg_gen -s 500 -p 14 -d 5 -r)" | wc -l
	@./$(NAME) "$(shell ./arg_gen -s 500 -p 15 -d 5 -r)" | ./$(CHECKER) "$(shell ./arg_gen -s 500 -p 15 -d 5 -r)"
	@./$(NAME) "$(shell ./arg_gen -s 500 -p 15 -d 5 -r)" | wc -l

.PHONY: all clean fclean re test test_error test_identity test_3 test_5 test_100 test_500

# Files -----------------------------------------------------------------------

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

$(ARGGEN): $(ARGGEN).c
	$(CC) $(ARGGEN).c -o $@
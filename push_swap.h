/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 00:13:54 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/03 16:42:25 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

// 3 integers: maximum moves allowed.
# define OPS_MAX_3 3

// 5 integers: maximum moves allowed.
# define OPS_MAX_5 12

// 100 integers: maximum moves for highest score.
# define OPS_MAX1_100 700
// 100 integers: maximum moves allowed.
# define OPS_MAX2_100 1500

// 500 integers: maximum moves for highest score.
# define OPS_MAX1_500 5500
// 500 integers: maximum moves allowed.
# define OPS_MAX2_500 11500

typedef struct s_array
{
	int				*dat; // Array of elements.
	unsigned int	max; // Maximum amount of elements in the array.
	unsigned int	len; // Current amount of elements in the array.
}	t_array;

/*
	SORTING
*/

/* Sort a pair of `t_array` stacks.
@param stacks Pair of stacks to sort.
@return Amount of operations performed.
`-1` if `malloc()` failed.*/
int		sort(t_array **stacks);

/* Sort a stack of size 3 using hardcoded solutions.
@param a Stack to sort.
@return Amount of operations performed. */
int		sort3(t_array *a);

/* Sort a stack of size 5 `sort3()` and then some simple operations.
@param a Stack to sort.
@param b Buffer stack.
@return Amount of operations performed. */
int		sort5(t_array *a, t_array *b);

/* Sort a stack of any size using radix sort.
Inefficient for small stacks, making other sorts useful.
@param a Stack to sort.
@param b Buffer stack.
@param shift How many bits to check from the start of each integer.
Incremented after each recursive loop until it reaches `maxshift`.
Should be `0` if called from outside `sort_radix()`.
@param maxshift Maximum amount of loops to perform
(to cover the amount of bits in the largest possible number).
Should be `-1` if called from outside `sort_radix()`.
@return Amount of operations performed. */
int		sort_radix(t_array *a, t_array *b, char shift, char maxshift);

/*
	ARRAY UTILS
*/

/* Create a new `t_array` using `malloc()`.
@param size Size of the `t_array`.
@param data Array to assign to the `t_array`'s `dat`.
It's optional: if `data` is `NULL`,
a new array is made and assigned to `dat`.
@return Resulting `t_array`. `NULL` if `malloc()` failed.*/
t_array	*arr_create(unsigned int size, int *data);

/* Free a `t_array` and its contents.
@param arr Array to free.*/
void	arr_free(t_array *arr);

/* Add an integer to the end of a `t_array`.
@param arr Array to append to.
@param n Integer to append.
@return `0` if an integer was successfully appended.
`-1` if there was no room.*/
int		arr_append(t_array *arr, int n);

/* Add an integer to the start of a `t_array`.
@param arr Array to prepend to.
@param n Integer to prepend.
@return `0` if an integer was successfully prepended.
`-1` if there was no room.*/
int		arr_prepend(t_array *arr, int n);

/* Remove the first integer of a `t_array`.
@param arr Array to remove from.
@return `0` if an integer was removed.
`-1` if the array contained no integers.*/
int		arr_remove(t_array *arr);

/* Print the elements of a `t_array` to `stdout`.
@param arr Array to print.*/
void	arr_print(t_array *arr);

/* Check if a `t_array` is sorted.
@param arr Array to check.
@return `true` if sorted, otherwise `false`.*/
int		arr_issorted(t_array *arr);

/* Swap the values of two integers using pointers.
@param a First integer.
@param b Second integer.*/
void	swap_int(int *a, int *b);

/*
	OPERATIONS
*/

/* Equivalent of `sa`, `sb` and `ss`.

Swap the first 2 elements at the top of a stack.
Do nothing if there is only one element or none.
@param s1 Stack to swap on.
@param s2 Other stack to swap on. Can be `NULL`.
@param out What the output of the operation should be.
The output should include the `\\n`.*/
void	swap(t_array *s1, t_array *s2, char *out);

/* Equivalent of `pa` and `pb`.

Take the first element at the top of a stack
and put it on top of the other stack.
Do nothing if the stack is empty.
@param s1 Stack to push from.
@param s2 Stack to push to.
@param out What the output of the operation should be.
The output should include the `\\n`.*/
void	push(t_array *s1, t_array *s2, char *out);

/* Equivalent of `ra`, `rb` and `rr`.

Shift up all elements of a stack by 1.
The first element becomes the last one.
@param s1 Pointer to stack to rotate.
@param s2 Pointer to other stack to rotate. Can be `NULL`.
@param out What the output of the operation should be.
The output should include the `\\n`.*/
void	rotate(t_array *s1, t_array *s2, char *out);

/* Equivalent of `rra`, `rrb` and `rrr`.

Shift down all elements of a stack by 1.
The last element becomes the first one.
@param s1 Pointer to stack to rotate.
@param s2 Pointer to other stack to rotate. Can be `NULL`.
@param out What the output of the operation should be.
The output should include the `\\n`.*/
void	rotrev(t_array *s1, t_array *s2, char *out);

/*
	VALIDATION
*/

/* Check if an integer array contains duplicates.
@param arr Array to check.
@param size Size of the array.
@return `true` if the array contains duplicates, otherwise `false`.*/
int		check_dupes(int const *arr, size_t size);

/* Check if an array of strings contains anything other than
a numeric or whitespace character.
@param strs Array of strings to search.
@return `true` if a bad character was found, otherwise `false`.*/
int		check_badchar(char const **strs);

#endif
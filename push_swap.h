/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 00:13:54 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/31 21:41:08 by ekramer       ########   odam.nl         */
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

int		sort(t_array **stacks);
int		sort3(t_array *a);
int		sort5(t_array *a, t_array *b);
int		sort_radix(t_array *a, t_array *b, unsigned char shift);

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

/* Shuffle a `t_array` using `rand()`.
@param arr Array to shuffle.*/
void	arr_shuffle(t_array *arr);

/* Fill a `t_array` with successive integers in ascending order.
@param arr Array to populate.*/
void	arr_populate(t_array *arr);

/* Swap the values of two integers using pointers.
@param a First integer.
@param b Second integer.*/
void	swap_int(int *a, int *b);

/* Swap the values of two pointers using pointers.
@param a First pointer.
@param b Second pointer.*/
void	swap_ptr(void **a, void **b);

/* Convert the values of a `t_array` to normalized ranks
(eg. `-12, 50, 2899` -> `0, 1, 2`).
@param arr Array to convert.
@return `0` if the operation was successful.
`-1` if `malloc()` failed.*/
int	to_ranks(t_array *arr);

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

#endif
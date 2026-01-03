/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 22:56:18 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/03 19:14:21 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the values of two pointers using pointers.
@param a First pointer.
@param b Second pointer.*/
static void	swap_ptr(void **a, void **b)
{
	void	*c;

	c = *a;
	*a = *b;
	*b = c;
}

/* Bubble sort iterator. */
static size_t	iter_bubble(int **array, size_t size)
{
	size_t	i;
	size_t	lastswap;

	i = 0;
	while (i < size - 1)
	{
		if (*array[i] > *array[i + 1])
		{
			swap_ptr((void **)&array[i], (void **)&array[i + 1]);
			lastswap = i;
		}
		++i;
	}
	return (lastswap);
}

/* Bubble sort. */
static void	sort_bubble(int **array, size_t size)
{
	size_t	lastswap;

	lastswap = iter_bubble(array, size);
	--size;
	while (lastswap != 0 && size > 1)
	{
		lastswap = iter_bubble(array, size);
		--size;
	}
}

/* Convert the values of a `t_array` to normalized ranks
(eg. `-12, 50, 2899` -> `0, 1, 2`).
@param arr Array to convert.
@return `0` if the operation was successful.
`-1` if `malloc()` failed.*/
static int	to_ranks(t_array *arr)
{
	int				**ptrs;
	unsigned int	i;

	ptrs = malloc(arr->max * sizeof(int *));
	if (ptrs == NULL)
		return (-1);
	i = 0;
	while (i < arr->max)
	{
		ptrs[i] = &(arr->dat[i]);
		++i;
	}
	sort_bubble(ptrs, arr->max);
	i = 0;
	while (i < arr->max)
	{
		*ptrs[i] = i;
		++i;
	}
	free(ptrs);
	return (0);
}

int	sort(t_array **stacks)
{
	if (to_ranks(stacks[0]) == -1)
		return (ft_printf("Out of memory\n"), -1);
	if (arr_issorted(stacks[0]))
		return (0);
	if (stacks[0]->max == 2)
		if (stacks[0]->dat[0] == 1)
			return (swap(stacks[0], NULL, "sa\n"), 1);
	if (stacks[0]->max == 3)
		return (sort3(stacks[0]));
	if (stacks[0]->max == 4)
		return (sort4(stacks[0], stacks[1]));
	if (stacks[0]->max == 5)
		return (sort5(stacks[0], stacks[1]));
	return (sort_radix(stacks[0], stacks[1], 0, -1));
}

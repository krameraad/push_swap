/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   to_ranks.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 23:22:37 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/30 02:56:07 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_ptr(void **a, void **b)
{
	void	*c;
    
    c = *a;
    *a = *b;
    *b = c;
}

static size_t	iter_bubble(int **array, size_t size)
{
	size_t	i;
	size_t	lastswap;

	i = 0;
	while (i < size - 1)
	{
		if (*array[i] > *array[i + 1])
		{
			swap_ptr(&array[i], &array[i + 1]);
			lastswap = i;
		}
		++i;
	}
	return (lastswap);
}

static void sort_bubble(int **array, size_t size)
{
	size_t	i;
	size_t	lastswap;

	i = 0;
	lastswap = iter_bubble(array, size);
	--size;
	while (lastswap != 0)
	{
		lastswap = iter_bubble(array, size);
		--size;
	}
}

int	to_ranks(t_array *arr)
{
	int				**ptrs;
	unsigned int	i;

	ptrs = malloc(arr->max * sizeof(int*));
	if (ptrs == NULL)
		return (-1); // We should do something with this return
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   to_ranks.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 23:22:37 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/30 00:22:33 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*intset(int *arr, unsigned int size, int n)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = n;
		++i;
	}
	return (arr);
}

static int	find_lowest_index(int *old, int *new, unsigned int size)
{
	unsigned int	lowest;
	unsigned int	i;
	unsigned int	j;

	lowest = INT_MAX;
	i = 0;
	j = 0;
	while (i < size)
	{
		if (old[i] < lowest && new[i] == -1)
		{
			lowest = old[i];
			j = i;
		}
		++i;
	}
	return (j);
}

int	*to_ranks(t_array *arr)
{
	int				*new;
	int				rank;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	new = malloc(arr->max * sizeof(int));
	if (new == NULL)
		return (NULL);
	intset(arr->dat, arr->max, -1);
	rank = 0;
	i = 0;
	k = 0;
	while (k < arr->max)
	{
		j = find_lowest_index(arr->dat, new, arr->max);
		new[j] = rank;
		++rank;
		++k;
	}
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   to_ranks.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 23:22:37 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/29 23:55:27 by ekramer       ########   odam.nl         */
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

static int	find_lowest(int *a, unsigned int size, int min)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (a[i] > min)
			min = a[i];
		++i;
	}
	return (min);
}

void	to_ranks(t_array *a)
{
	int				*new;
	unsigned int	lowest;
	unsigned int	newlow;
	unsigned int	i;

	new = malloc(a->max * sizeof(int));
	if (new == NULL)
		return ;
	i = 0;
	intset(a->dat, a->max, -1);
	lowest = INT_MIN;
	newlow = find_lowest(a->dat, a->len, lowest);
	while (lowest != newlow)
	{
		
		++i;
	}
	free(a->dat);
	a->dat = new;
}

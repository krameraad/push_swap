/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_radix.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 16:37:37 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/03 16:18:20 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	find_maxshift(unsigned int size)
{
	char			maxshift;
	unsigned int	i;

	i = 0;
	while (i < 32)
	{
		if ((size >> i) & 0b1)
			maxshift = i;
		++i;
	}
	return (maxshift);
}

int	sort_radix(t_array *a, t_array *b, char shift, char maxshift)
{
	unsigned int	i;
	unsigned int	ops;

	if (maxshift == -1)
		maxshift = find_maxshift(a->max);
	if (shift > maxshift)
		return (0);
	i = 0;
	while (i < a->max)
	{
		if ((a->dat[0] >> shift) & 0b1)
			rotate(a, NULL, "ra\n");
		else
			push(a, b, "pb\n");
		++i;
	}
	i = b->len;
	ops = i + a->max;
	while (i > 0)
	{
		push(b, a, "pa\n");
		--i;
	}
	return (ops + sort_radix(a, b, shift + 1, maxshift));
}

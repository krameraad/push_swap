/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_radix.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 16:37:37 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/02 17:54:28 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_radix(t_array *a, t_array *b, unsigned char shift)
{
	unsigned int	i;
	unsigned int	ops;

	if (shift > 8)
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
	return (ops + sort_radix(a, b, shift + 1));
}

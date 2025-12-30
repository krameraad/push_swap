/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 16:37:37 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/30 00:51:24 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_radix(t_array *a, t_array *b, unsigned char shift)
{
	unsigned int	i;
	
	if (shift > 31)
		return (0);
	i = 0;
	while (i < a->max)
	{
		if ((a->dat[0] >> shift) & 0b1)
			rotate(a, NULL);
		else
			push(a, b);
		++i;
	}
	i = b->len;
	while (i > 0)
	{
		push(b, a);
		--i;
	}
	return (sort_radix(a, b, shift + 1));
}

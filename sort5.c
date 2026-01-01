/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort5.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/30 17:03:05 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/31 20:49:43 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort5(t_array *a, t_array *b)
{
	unsigned int	i;

	i = 0;
	while (i < a->len)
	{
		if (a->dat[0] == 3 || a->dat[0] == 4)
			push(a, b, "pb\n");
		else
		{
			rotate(a, NULL, "ra\n");
			++i;
		}
	}
	i = sort3(a);
	if (b->dat[0] == 3)
	{
		swap(b, NULL, "sb\n");
		++i;
	}
	push(b, a, "pa\n");
	push(b, a, "pa\n");
	rotate(a, NULL, "ra\n");
	rotate(a, NULL, "ra\n");
	return (9 + i);
}

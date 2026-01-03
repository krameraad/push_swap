/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort4.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/03 19:00:29 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/03 19:12:30 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort4(t_array *a, t_array *b)
{
	unsigned int	i;

	i = 0;
	while (i < a->len)
	{
		if (a->dat[0] == 3)
			push(a, b, "pb\n");
		else
		{
			rotate(a, NULL, "ra\n");
			++i;
		}
	}
	i = sort3(a);
	push(b, a, "pa\n");
	rotate(a, NULL, "ra\n");
	return (6 + i);
}

/*
	1 2 4 3
to_ranks()
	0 1 3 2
ra
	1 3 2 0
ra
	3 2 0 1
pb
	2 0 1	| 3
ra
	0 1 2	| 3

*/
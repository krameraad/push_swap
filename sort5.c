/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort5.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/30 17:03:05 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/30 18:39:31 by ekramer       ########   odam.nl         */
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
			push(a, b);
		else
		{
			rotate(a, NULL);
			++i;
		}
	}
	i = sort3(a);
	if (b->dat[0] == 3)
	{
		swap(b, NULL);
		++i;
	}
	push(b, a);
	push(b, a);
	rotate(a, NULL);
	rotate(a, NULL);
	return (9 + i);
}

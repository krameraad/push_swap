/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 16:41:21 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/29 20:29:27 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_array *s1, t_array *s2)
{
	if (s1->len > 1)
		swap_int(&(s1->dat[0]), &(s1->dat[1]));
	if (s2 != NULL && s2->len > 1)
		swap_int(&(s2->dat[0]), &(s2->dat[1]));
}

void	push(t_array *s1, t_array *s2)
{
	arr_prepend(s2, s1->dat[0]);
	arr_remove(s1);
}

void	rotate(t_array *s1, t_array *s2)
{
	int	n;
	
	if (s1->len > 1)
	{
		n = s1->dat[0];
		arr_remove(s1);
		arr_append(s1, n);
	}
	if (s2 != NULL)
		rotate(s2, NULL);
}

void	rotrev(t_array *s1, t_array *s2)
{
	int	n;
	
	if (s1->len > 1)
	{
		n = s1->dat[s1->len - 1];
		s1->len -= 1;
		arr_prepend(s1, n);
	}
	if (s2 != NULL)
		rotrev(s2, NULL);
}

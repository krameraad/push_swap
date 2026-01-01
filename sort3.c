/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort3.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/30 15:56:21 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/31 20:49:01 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort3(t_array *a)
{
	int	*arr;

	arr = a->dat;
	if (arr[0] == 0 && arr[1] == 1)
		return (0);
	if (arr[0] == 0 && arr[1] == 2)
		return (swap(a, NULL, "sa\n"), rotate(a, NULL, "ra\n"), 2);
	if (arr[0] == 1 && arr[1] == 0)
		return (swap(a, NULL, "sa\n"), 1);
	if (arr[0] == 1 && arr[1] == 2)
		return (rotrev(a, NULL, "rra\n"), 1);
	if (arr[0] == 2 && arr[1] == 0)
		return (rotate(a, NULL, "ra\n"), 1);
	return (swap(a, NULL, "sa\n"), rotrev(a, NULL, "rra\n"), 2);
}

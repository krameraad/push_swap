/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arr_prepend.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 19:49:04 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/29 19:57:19 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	arr_prepend(t_array *arr, int n)
{
	unsigned int	i;
	
	if (arr->len >= arr->max)
		return (-1);
	i = arr->len;
	while (i > 0)
	{
		arr->dat[i] = arr->dat[i - 1];
		--i;
	}
	arr->dat[0] = n;
	arr->len += 1;
	return (0);
}

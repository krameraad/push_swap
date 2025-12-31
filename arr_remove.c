/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arr_remove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 19:48:21 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/31 19:44:25 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_remove(t_array *arr)
{
	unsigned int	i;

	if (arr->len <= 0)
		return (-1);
	i = 0;
	while (i < arr->len - 1)
	{
		arr->dat[i] = arr->dat[i + 1];
		++i;
	}
	arr->len -= 1;
	return (0);
}

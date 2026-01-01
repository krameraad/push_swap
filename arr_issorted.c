/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arr_issorted.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 20:47:47 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/31 21:35:47 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int arr_issorted(t_array *arr)
{
	unsigned int	i;

	if (arr->len < 2)
		return (true);
	i = 0;
	while (i < arr->len - 1)
	{
		if (arr->dat[i] > arr->dat[i + 1])
			return (false);
		++i;
	}
	return (true);
}

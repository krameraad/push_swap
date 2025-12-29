/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arr_shuffle.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 20:52:16 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/29 20:56:24 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	arr_shuffle(t_array *arr)
{
	unsigned int	i;

	i = arr->len;
	while (i > 1)
	{
		swap_int(&(arr->dat[rand() % i]), &(arr->dat[i - 1]));
		--i;
	}
}

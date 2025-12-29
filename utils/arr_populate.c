/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arr_populate.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 21:01:10 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/29 21:02:46 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	arr_populate(t_array *arr)
{
	unsigned int	i;

	i = 0;
	while (i < arr->max)
	{
		arr->dat[i] = i;
		++i;
	}
	arr->len = arr->max;
}

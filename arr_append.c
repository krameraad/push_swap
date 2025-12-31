/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arr_append.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 19:49:32 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/31 19:44:42 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_append(t_array *arr, int n)
{
	if (arr->len >= arr->max)
		return (-1);
	arr->dat[arr->len] = n;
	arr->len += 1;
	return (0);
}

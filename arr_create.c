/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arr_create.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 17:38:38 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/02 17:54:40 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_array	*arr_create(unsigned int size, int *data)
{
	t_array	*arr;

	arr = malloc(sizeof(t_array));
	if (arr == NULL)
		return (NULL);
	if (data == NULL)
	{
		arr->dat = malloc(size * sizeof(int));
		if (arr->dat == NULL)
			return (free(arr), NULL);
		arr->len = 0;
	}
	else
	{
		arr->dat = data;
		arr->len = size;
	}
	arr->max = size;
	return (arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arr_free.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/30 15:32:50 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/30 15:33:22 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	arr_free(t_array *arr)
{
	free(arr->dat);
	free(arr);
}

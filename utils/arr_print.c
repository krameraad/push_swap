/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arr_print.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 20:24:39 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/29 20:31:53 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void arr_print(t_array *arr)
{
	unsigned int	i;

	if (arr->len <= 0)
	{
		ft_printf("Empty\n");
		return ;
	}
	i = 0;
	while (i < arr->len - 1)
	{
        ft_printf("%d, ", arr->dat[i]);
		++i;
	}
    ft_printf("%d\n", arr->dat[i]);
}

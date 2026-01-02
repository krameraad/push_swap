/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 22:56:18 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/02 17:58:58 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_array **stacks)
{
	if (to_ranks(stacks[0]) == -1)
		return (ft_printf("Out of memory"), -1);
	if (arr_issorted(stacks[0]))
		return (0);
	if (stacks[0]->max == 3)
		return (sort3(stacks[0]));
	if (stacks[0]->max == 5)
		return (sort5(stacks[0], stacks[1]));
	return (sort_radix(stacks[0], stacks[1], 0));
}

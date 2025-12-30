/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sortswitch.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 22:56:18 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/30 18:41:37 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_array **stacks)
{
	if (stacks[0]->max == 3)
		return(sort3(stacks[0]));
	if (stacks[0]->max == 5)
		return(sort5(stacks[0], stacks[1]));
	return (sort_radix(stacks[0], stacks[1], 0));
}

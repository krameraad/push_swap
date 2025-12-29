/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sortswitch.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 22:56:18 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/29 23:22:43 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	lookup(int *arr)
{
	
}

static int	sort3(t_array *a, t_array *b)
{
	
	return (0);
}

static int	sort5(t_array *a, t_array *b)
{
	return (0);
}

int	sortswitch(t_array **stacks)
{
	if (stacks[0]->max == 3)
		return(sort3(stacks[0], stacks[1]));
	if (stacks[0]->max == 5)
		return(sort5(stacks[0], stacks[1]));
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_dupes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/03 00:16:42 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/03 00:17:17 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dupes(int const *arr, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				return (true);
			++j;
		}
		++i;
	}
	return (false);
}

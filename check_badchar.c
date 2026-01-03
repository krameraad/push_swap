/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_badchar.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/03 00:16:42 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/03 00:17:49 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_badchar(char const **strs)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (strs[i] != NULL)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			if (ft_strchr(" \t\n\v\f\r0123456789-+", strs[i][j]) == NULL)
				return (true);
			++j;
		}
		++i;
	}
	return (false);
}

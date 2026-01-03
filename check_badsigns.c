/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_badsigns.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/03 20:20:15 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/03 20:39:31 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_badsigns(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i + 1] == '\0' || !ft_strchr("0123456789", str[i + 1]))
				return (true);
			if (i > 0 && !ft_strchr(" \t\n\v\f\r", str[i - 1]))
				return (true);
		}
		++i;
	}
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/17 13:12:54 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/23 23:56:43 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Checks if a character is whitespace.

Whitespace characters: `'\t'`, `'\\n'`, `'\v'`,
`'\f'`, `'\r'` (9 through 13) and `' '` (space / 32)
@param c Character to test.
@return `1` if whitespace, otherwise `0`. */
static int	whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	total;
	int	i;

	sign = 1;
	total = 0;
	i = 0;
	while (whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = (total * 10) + str[i] - '0';
		i++;
	}
	return (total * sign);
}

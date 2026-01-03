/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoll.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/03 19:34:37 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/03 20:56:49 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	long long	total;
	char		sign;
	size_t		i;

	sign = 1;
	total = 0;
	i = 0;
	while (ft_strchr(" \t\n\v\f\r", str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = (total * 10) + str[i] - '0';
		++i;
	}
	return (total * sign);
}

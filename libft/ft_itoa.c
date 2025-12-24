/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 01:01:00 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/10 01:01:00 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	intlen(int i)
{
	unsigned char	count;

	if (i == 0)
		return (1);
	count = 0;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	while (i)
	{
		i /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned char	size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = intlen(n);
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (size && str[size - 1] != '-')
	{
		size--;
		str[size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

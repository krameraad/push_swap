/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/26 16:35:36 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/23 23:40:34 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(unsigned long long n, char uppercase, int fd)
{
	int		count;

	count = 0;
	if (n < 16)
	{
		if (n < 10)
			return (ft_putchar_fd(n + '0', fd));
		if (uppercase)
			return (ft_putchar_fd(n - 10 + 'A', fd));
		return (ft_putchar_fd(n - 10 + 'a', fd));
	}
	count += ft_puthex_fd(n / 16, uppercase, fd);
	count += ft_puthex_fd(n % 16, uppercase, fd);
	return (count);
}

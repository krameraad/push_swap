/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekramer <ekramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:22:33 by ekramer           #+#    #+#             */
/*   Updated: 2025/11/24 22:19:19 by ekramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n < 10)
		return (count + ft_putchar_fd(n + '0', fd));
	count += ft_putnbr_fd(n / 10, fd);
	count += ft_putnbr_fd(n % 10, fd);
	return (count);
}

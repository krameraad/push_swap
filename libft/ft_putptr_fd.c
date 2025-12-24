/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/24 22:20:25 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/02 17:20:39 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_fd(unsigned long long n, int fd)
{
	if (n == 0)
		return (ft_putstr_fd("(nil)", fd));
	return (ft_putstr_fd("0x", fd) + ft_puthex_fd(n, false, fd));
}

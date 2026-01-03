/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/03 18:38:20 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/03 18:41:43 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	convert(int fd, char const c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), fd));
	if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	if (c == 'p')
		return (ft_putptr_fd(va_arg(args, unsigned long long), fd));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), fd));
	if (c == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), fd));
	if (c == 'x')
		return (ft_puthex_fd(va_arg(args, unsigned int), false, fd));
	if (c == 'X')
		return (ft_puthex_fd(va_arg(args, unsigned int), true, fd));
	if (c == '%')
		return (ft_putchar_fd('%', fd));
	return (ft_putchar_fd('%', fd) + ft_putchar_fd(c, fd));
}

int	ft_printf_fd(int fd, char const *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (s == NULL)
		return (-1);
	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
				return (-1);
			count += convert(fd, s[i + 1], args);
			i += 2;
		}
		else
		{
			count += write(fd, &s[i], 1);
			i++;
		}
	}
	return (va_end(args), count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/26 16:36:22 by ekramer       #+#    #+#                 */
/*   Updated: 2025/11/26 16:36:22 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (c == 'p')
		return (ft_putptr_fd(va_arg(args, unsigned long long), 1));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (c == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), 1));
	if (c == 'x')
		return (ft_puthex_fd(va_arg(args, unsigned int), false, 1));
	if (c == 'X')
		return (ft_puthex_fd(va_arg(args, unsigned int), true, 1));
	if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (ft_putchar_fd('%', 1) + ft_putchar_fd(c, 1));
}

int	ft_printf(const char *s, ...)
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
			count += convert(s[i + 1], args);
			i += 2;
		}
		else
		{
			count += write(1, &s[i], 1);
			i++;
		}
	}
	return (va_end(args), count);
}

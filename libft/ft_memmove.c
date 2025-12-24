/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekramer <ekramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:52:49 by ekramer           #+#    #+#             */
/*   Updated: 2025/10/28 19:57:19 by ekramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;

	if (dest <= src)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	p_dest = dest;
	p_src = src;
	while (n > 0)
	{
		p_dest[n - 1] = p_src[n - 1];
		n--;
	}
	return (dest);
}

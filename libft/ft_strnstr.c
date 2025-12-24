/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekramer <ekramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:31:53 by ekramer           #+#    #+#             */
/*   Updated: 2025/10/28 17:05:26 by ekramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_size;
	size_t	i;

	if (little[0] == 0)
		return ((char *)big);
	little_size = ft_strlen(little);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			if (little_size + i > len)
				return (NULL);
			if (ft_strncmp(big + i, little, little_size) == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}

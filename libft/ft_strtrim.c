/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekramer <ekramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:35:49 by ekramer           #+#    #+#             */
/*   Updated: 2025/11/24 21:41:06 by ekramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	char	*str;
	size_t	size;

	while (*s && ft_strchr(set, *s))
		s++;
	size = ft_strlen(s);
	while (size > 0 && ft_strrchr(set, s[size - 1]))
		size--;
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, size + 1);
	return (str);
}

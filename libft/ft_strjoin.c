/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 01:01:24 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/10 01:01:24 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		s1_len;

	s1_len = ft_strlen(s1);
	str = malloc(s1_len + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, __SIZE_MAX__);
	ft_strlcpy(str + s1_len, s2, __SIZE_MAX__);
	return (str);
}

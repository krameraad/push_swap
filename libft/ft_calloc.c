/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 00:48:47 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/10 00:48:47 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	totalsize;

	totalsize = nmemb * size;
	if (totalsize == 0)
		return (malloc(0));
	if (totalsize / size != nmemb)
		return (NULL);
	s = malloc(totalsize);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, totalsize);
	return (s);
}

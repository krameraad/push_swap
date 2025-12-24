/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 01:37:14 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/23 23:58:04 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// @return Index of the first character in `s` which is the same as `c`.
static size_t	find_next(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

// @return Number of words in `s`, using `c` as a delimiter.
static size_t	wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0' && *s == c)
		s++;
	while (*s != '\0')
	{
		count++;
		s += find_next(s, c);
		while (*s != '\0' && *s == c)
			s++;
	}
	return (count);
}

/* Free all strings in array `strs`.
Assumes the array ends with a `NULL` pointer. */
static void	freeall(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	len;
	size_t	i;

	strs = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	while (*s != '\0' && *s == c)
		s++;
	len = find_next(s, c);
	i = 0;
	while (len != 0)
	{
		strs[i] = ft_substr(s, 0, len);
		if (strs[i] == NULL)
			return (freeall(strs), NULL);
		s += len;
		while (*s != '\0' && *s == c)
			s++;
		len = find_next(s, c);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}

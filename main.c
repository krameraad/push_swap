/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 00:23:00 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/30 21:36:56 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if an integer array contains duplicates.
@param arr Array to check.
@param size Size of the array.
@return `true` if the array contains duplicates, otherwise `false`.*/
static int	check_dupes(int const *arr, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				return (true);
			++j;
		}
		++i;
	}
	return (false);
}

/* Check if an array of strings contains anything other than
a numeric or whitespace character.
@param strs Array of strings to search.
@return `true` if a bad character was found, otherwise `false`.*/
static int	check_badchar(char const **strs)
{
	size_t	i;

	while (*strs != NULL)
	{
		i = 0;
		while (*strs[i] != '\0')
		{
			if (ft_strchr(" \t\n\v\f\r0123456789-", *strs[i]) == NULL)
				return (true);
			++i;
		}
		++strs;
	}
	return (false);
}

int	main(int argc, char const *argv[])
{
	t_array	*stacks[2];
	int		*array;
	char	***strs;
	size_t	i;

	if (argc == 1)
		return (0);
	if (check_badchar(argv + 1))
		
	strs = malloc((argc - 1) * sizeof(char**));
	if (strs == NULL)
		return (-1);
	i = 0;
	while (*argv != NULL)
	{
		strs[i] = ft_split(argv[i], ' ');
		++argv;
	}
	return (0);
}

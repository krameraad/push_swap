/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 00:23:00 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/31 01:15:03 by ekramer       ########   odam.nl         */
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
			if (ft_strchr(" \t\n\v\f\r0123456789-+", *strs[i]) == NULL)
				return (true);
			++i;
		}
		++strs;
	}
	return (false);
}

static int	setup_stacks(t_array **stacks, char **strs)
{
	int		*array;
	size_t	i;
	
	i = 0;
	while (strs[i] != NULL)
		++i;
	array = malloc(i * sizeof(int));
	if (array == NULL)
		return (-1);
	i = 0;
	while (strs[i] != NULL)
	{
		array[i] = ft_atoi(strs[i]);
		++i;
	}
	if (check_dupes(array, i))
		return (ft_printf("Error"), free(array), -1);
	stacks[0] = arr_create(i, array);
	if (stacks[0] == NULL)
		return (free(array), -1);
	stacks[1] = arr_create(i, NULL);
	if (stacks[1] == NULL)
		return (arr_free(stacks[0]), -1);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_array	*stacks[2];
	char	**strs;

	if (argc == 1)
		return (0);
	if (check_badchar(argv + 1))
		return (ft_printf("Error"), -1);
	if (argc == 2)
		strs = ft_split(argv[1], ' ');
	else
		strs = argv;
	if (strs == NULL)
		return (-1);
	if (setup_stacks(stacks, strs) == -1)
		return (free(strs), -1);
	free(strs);
	sort(stacks);
	arr_free(stacks[0]);
	arr_free(stacks[1]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 00:23:00 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/02 17:58:32 by ekramer       ########   odam.nl         */
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
	size_t	j;

	i = 1;
	while (strs[i] != NULL)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			if (ft_strchr(" \t\n\v\f\r0123456789-+", strs[i][j]) == NULL)
				return (true);
			++j;
		}
		++i;
	}
	return (false);
}

static char	**setup_strings(int argc, char const **argv)
{
	char	**strs;
	size_t	i;

	if (argc == 2)
		return (ft_split(argv[1], ' '));
	strs = malloc(argc * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (argv[i + 1] != NULL)
	{
		strs[i] = ft_strdup(argv[i + 1]);
		if (strs[i] == NULL)
		{
			i = 0;
			while (strs[i] != NULL)
				free(strs[i++]);
			return (free(strs), NULL);
		}
		++i;
	}
	strs[i] = NULL;
	return (strs);
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
		return (ft_printf("Out of memory"), free(array), -1);
	stacks[1] = arr_create(i, NULL);
	if (stacks[1] == NULL)
		return (ft_printf("Out of memory"), arr_free(stacks[0]), -1);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_array	**stacks;
	char	**strs;
	int		i;

	if (argc == 1)
		return (0);
	if (check_badchar(argv))
		return (ft_printf("Error"), -1);
	strs = setup_strings(argc, argv);
	if (strs == NULL)
		return (-1);
	stacks = malloc(2 * sizeof(t_array));
	if (stacks == NULL)
		return (free(strs), -1);
	if (setup_stacks(stacks, strs) == -1)
		return (free(strs), free(stacks), -1);
	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
	if (sort(stacks) == -1)
		return (arr_free(stacks[0]), arr_free(stacks[1]), free(stacks), -1);
	return (arr_free(stacks[0]), arr_free(stacks[1]), free(stacks), 0);
}

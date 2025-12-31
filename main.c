/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 00:23:00 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/31 19:39:45 by ekramer       ########   odam.nl         */
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

static char	**setup_strings(int argc, char const **args)
{
	char	**strs;
	size_t	i;
	
	if (argc == 2)
		return (ft_split(args[1], ' '));
	strs = malloc((argc - 1) * sizeof(char*));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (args[i] != NULL)
	{
		strs[i] = ft_strdup(args[i]);
		if (strs[i] == NULL)
		{
			i = 0;
			while (strs[i] != NULL)
				free(strs[i++]);
			return (free(strs), NULL);
		}
		++i;
	}
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
	strs = setup_strings(argc, argv + 1);
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

/*
push_swap/
↳ libft/
  ↳ Makefile
  ↳ *.c
  ↳ libft.h
↳ utils/
  ↳ *.c
↳ Makefile
↳ main.c
↳ *.c
↳ push_swap.h
*/
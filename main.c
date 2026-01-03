/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 00:23:00 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/03 20:20:01 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	*setup_array(int i, char **strs)
{
	int			*array;
	long long	n;

	array = malloc(i * sizeof(int));
	if (array == NULL)
		return (ft_printf_fd(2, "Out of memory\n"), NULL);
	i = 0;
	while (strs[i] != NULL)
	{
		n = ft_atoll(strs[i]);
		if (n <= INT_MAX && n >= INT_MIN && check_badsigns(strs[i]) == false)
			array[i] = n;
		else
			return (ft_printf_fd(2, "Error\n"), free(array), NULL);
		++i;
	}
	return (array);
}

static int	setup_stacks(t_array **stacks, char **strs)
{
	int			*array;
	size_t		i;

	i = 0;
	while (strs[i] != NULL)
		++i;
	array = setup_array(i, strs);
	if (array == NULL)
		return (-1);
	if (check_dupes(array, i))
		return (ft_printf_fd(2, "Error\n"), free(array), -1);
	stacks[0] = arr_create(i, array);
	if (stacks[0] == NULL)
		return (ft_printf_fd(2, "Out of memory\n"), free(array), -1);
	stacks[1] = arr_create(i, NULL);
	if (stacks[1] == NULL)
		return (ft_printf_fd(2, "Out of memory\n"), arr_free(stacks[0]), -1);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_array	**stacks;
	char	**strs;
	int		i;

	if (argc <= 1)
		return (0);
	if (ft_strlen(argv[1]) == 0)
		return (ft_printf_fd(2, "Error\n"), 1);
	if (check_badchar(argv))
		return (ft_printf_fd(2, "Error\n"), 1);
	strs = setup_strings(argc, argv);
	if (strs == NULL)
		return (ft_printf_fd(2, "Out of memory\n"), 1);
	stacks = malloc(2 * sizeof(t_array));
	if (stacks == NULL)
		return (free(strs), 1);
	if (setup_stacks(stacks, strs) == -1)
		return (free(strs), free(stacks), 1);
	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
	if (sort(stacks) == -1)
		return (arr_free(stacks[0]), arr_free(stacks[1]), free(stacks), 1);
	return (arr_free(stacks[0]), arr_free(stacks[1]), free(stacks), 0);
}

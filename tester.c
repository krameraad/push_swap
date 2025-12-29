/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 20:46:35 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/30 00:51:57 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_array	**setup_test_stacks(unsigned int size)
{
	t_array	**stacks;
	
	stacks = malloc(2 * sizeof(t_array*));
	if (stacks == NULL)
		return (NULL);
	stacks[0] = arr_create(size, NULL);
	if (stacks[0] == NULL)
		return (free(stacks), NULL);
	stacks[1] = arr_create(size, NULL);
	if (stacks[0] == NULL)
		return (free(stacks[0]), free(stacks), NULL);
	arr_populate(stacks[0]);
	arr_shuffle(stacks[0]);
	return (stacks);
}

static int	verify_stacks(t_array **stacks)
{
	bool	verified;

	if (arr_issorted(stacks[0]))
	{
		ft_printf("\e[4;42;97m\n" "Stack A, size %d:\tOK", stacks[0]->max);
		ft_printf("\e[24;49;92m\n");
		arr_print(stacks[0]);
		verified = true;
	}
	else
	{
		ft_printf("\e[4;41;97m\n" "Stack A, size %d:\tKO", stacks[0]->max);
		ft_printf("\e[24;49;91m\n");
		arr_print(stacks[0]);
		verified = false;
	}
	ft_printf("\e[0;4m\n" "Stack B" "\e[24m\n");
	arr_print(stacks[1]);
	ft_printf("\n\e[0m");
	return (verified);
}

int run_tests()
{
	t_array			**stackpairs[4];
	unsigned int	i;
	unsigned int	passes;

	stackpairs[0] = setup_test_stacks(3);
	stackpairs[1] = setup_test_stacks(5);
	stackpairs[2] = setup_test_stacks(100);
	stackpairs[3] = setup_test_stacks(500);

	sort_radix(stackpairs[0][0], stackpairs[0][1], 0);
	sort_radix(stackpairs[1][0], stackpairs[1][1], 0);
	sort_radix(stackpairs[2][0], stackpairs[2][1], 0);
	sort_radix(stackpairs[3][0], stackpairs[3][1], 0);
	
	i = 0;
	while (i <= 3)
	{
		passes += verify_stacks(stackpairs[i]);
		++i;
	}
	if (passes >= 4)
		ft_printf("\e[92m");
	else
		ft_printf("\e[91m");
	ft_printf("%u/4 tests passed\n\n", passes);
	ft_printf("\e[0m");
	return 0;
}

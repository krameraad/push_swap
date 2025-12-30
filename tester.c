/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/29 20:46:35 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/30 20:51:40 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

#define FAIL -1
#define WIN 0
#define EPICWIN 1

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

static int	verify_stacks(t_array *a, t_array *b)
{
	bool	verified;

	if (arr_issorted(a))
	{
		ft_printf("\e[4;42;97m\n" "Stack A, size %d:\tOK", a->max);
		ft_printf("\e[24;49;92m\n");
		arr_print(a);
		verified = true;
	}
	else
	{
		ft_printf("\e[4;41;97m\n" "Stack A, size %d:\tKO", a->max);
		ft_printf("\e[24;49;91m\n");
		arr_print(a);
		verified = false;
	}
	if (b->len != 0)
	{
		ft_printf("\e[0;4m\n" "Stack B" "\e[24m\n");
		arr_print(b);
	}
	ft_printf("\n\e[0m");
	return (verified);
}

// static int	check_ops_max(size_t ops, size_t max1, size_t max2)
// {
// 	if (ops > max1)
// 		return (FAIL);
// 	if (ops > max1 && ops < max2)
// 		return (WIN);
// 	return (EPICWIN);
// }

int	main(int argc, char const *argv[])
{
	srand(time(NULL));
	t_array			**stackpairs[4];
	unsigned int	ops[4];
	unsigned int	i;
	unsigned int	passes;

	stackpairs[0] = setup_test_stacks(3);
	stackpairs[1] = setup_test_stacks(5);
	stackpairs[2] = setup_test_stacks(100);
	stackpairs[3] = setup_test_stacks(500);

	i = 0;
	while (i <= 3)
	{
		ops[i] = sort(stackpairs[i]);
		++i;
	}
	passes = 0;
	i = 0;
	while (i <= 3)
	{
		passes += verify_stacks(stackpairs[i][0], stackpairs[i][1]);
		ft_printf("Operations:\t%d\n", ops[i]);
		++i;
	}
	if (passes >= 4)
		ft_printf("\e[92m");
	else
		ft_printf("\e[91m");
	ft_printf("%u/4 tests passed\n\n", passes);
	ft_printf("\e[0m");
	return (0);
}

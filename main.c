/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 00:23:00 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/29 20:36:11 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define ARRAY_SIZE 10

static void	shuffle_array_int(int *array, size_t size)
{
	for (; size > 1; size--)
		swap_int(&array[rand() % size], &array[size - 1]);
}

static void	arr_populate(t_array *arr)
{
	for (unsigned int i = 0; i < arr->max; i++)
		arr->dat[i] = i;
	arr->len = arr->max;
}

static int check_sorted(int *array, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
			return (false);
	}
	return (true);
}

int	main(int argc, char const *argv[])
{
	t_array	*stack_a;
	t_array	*stack_b;

	stack_a = arr_create(ARRAY_SIZE, NULL);
	stack_b = arr_create(ARRAY_SIZE, NULL);
	
	arr_populate(stack_a);
	push(stack_a, stack_b);
	push(stack_a, stack_b);

	if (check_sorted(stack_a->dat, ARRAY_SIZE))
		ft_printf("\e[92;4m" "Stack A: OK!" "\e[24m\n");
	else
		ft_printf("\e[91;4m" "Stack A: KO!" "\e[24m\n");
	arr_print(stack_a);
	
	ft_printf("\n\e[0;4m" "Stack B" "\e[24m\n");
	arr_print(stack_b);
	
	ft_printf("\e[0m");
	return (0);
}

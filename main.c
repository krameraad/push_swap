/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 00:23:00 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/29 22:44:28 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "time.h"

#define ARRAY_SIZE 100

int	main(int argc, char const *argv[])
{
	t_array	*stack_a;
	t_array	*stack_b;
	
	srand(time(NULL));
	run_tests();
	
	return (0);
}

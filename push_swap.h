/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 00:13:54 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/24 01:42:56 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	t_list			*list;
	unsigned int	size;
	struct s_stack	*other;
} t_stack;

void	swap(t_stack *stack, bool both);
void	push(t_stack *stack);
void	rotate(t_stack *stack, bool both);
void	rotrev(t_stack *stack, bool both);

#endif
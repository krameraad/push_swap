/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_circ.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 16:51:03 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/31 19:44:20 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_lstsize_circ(t_list *lst)
{
	t_list	*start;
	size_t	i;

	if (lst == NULL)
		return (0);
	start = lst;
	lst = lst->next;
	i = 1;
	while (lst != start && lst != NULL)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}

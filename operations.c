/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/24 16:41:21 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/02 17:59:14 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_array *s1, t_array *s2, char *out)
{
	if (s1->len > 1)
		swap_int(&(s1->dat[0]), &(s1->dat[1]));
	if (s2 != NULL && s2->len > 1)
		swap_int(&(s2->dat[0]), &(s2->dat[1]));
	ft_printf("%s", out);
}

void	push(t_array *s1, t_array *s2, char *out)
{
	arr_prepend(s2, s1->dat[0]);
	arr_remove(s1);
	ft_printf("%s", out);
}

void	rotate(t_array *s1, t_array *s2, char *out)
{
	int	n;

	if (s1->len > 1)
	{
		n = s1->dat[0];
		arr_remove(s1);
		arr_append(s1, n);
	}
	if (s2 != NULL)
		rotate(s2, NULL, "");
	ft_printf("%s", out);
}

void	rotrev(t_array *s1, t_array *s2, char *out)
{
	int	n;

	if (s1->len > 1)
	{
		n = s1->dat[s1->len - 1];
		s1->len -= 1;
		arr_prepend(s1, n);
	}
	if (s2 != NULL)
		rotrev(s2, NULL, "");
	ft_printf("%s", out);
}

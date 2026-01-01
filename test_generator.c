/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_generator.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/31 21:49:14 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/31 22:01:09 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC);
	
	for (size_t i = 0; i < 500; ++i)
	{
		char *num = ft_itoa(i);
		write(fd, num, ft_strlen(num));
		write(fd, " ", 1);
		free(num);
	}
	return (close(fd), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/22 17:00:58 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/12/13 17:16:57 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

void ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		(unsigned char)s[n - 1] = '\0';
		n--;
	}
}

char *get_next_line(int fd)
{
	char *text[BUFFER_SIZE + 1];

	if(fd < 0)
		return (NULL);
	ft_bzero(text, BUFFER_SIZE + 1);
	read(fd, text, BUFFER_SIZE);

	return(NULL);
}
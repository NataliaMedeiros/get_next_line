/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:00:58 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/12/08 16:49:47 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	read function:
	size_t read (int fd, void* buf, size_t cnt);
	Parameters
		fd: file descriptor of the file from which data is to be read.
		buf: buffer to read data from
		cnt: length of the buffer
	Return Value
		return Number of bytes read on success
		return 0 on reaching the end of file
		return -1 on error
		return -1 on signal interrupt
*/

#include "get_next_line.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
	{
		dst[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	find_next_line(char *text)
{
	int		i;

	i = 0;
	if (!text)
		return (0);
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	return (i);
}

char *read_file(int fd, char *text)
{
	int		bytes_read;
	char	*new_text;

	bytes_read = 1;
	new_text = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while ((find_next_line(text) == 0) && bytes_read != 0)
	{
		bytes_read = read(fd, new_text, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(text);
			free(new_text);
			return (NULL);
		}
		//printf ("bytes read %d\n", bytes_read);
		new_text[bytes_read] = 0;
		text = ft_strjoin(text, new_text);
	}
	return (text);
}

char	*update_text(char *text, int i)
{
	int	j;

	j = 0;
	while (text[i])
		text[j++] = text[i++];
	while (text[j] != '\0')
		text[j++] = '\0';
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*actual_line;
	int			i;

	i = 0;
	if (text == NULL)
		text = ft_calloc((BUFFER_SIZE + 1),sizeof(char));
	text = read_file(fd, text);
	if (text[0] == '\0')
		return (free(text), NULL);
	i = find_next_line(text) + 1;
	actual_line = malloc(i * sizeof(char));
	ft_strlcpy(actual_line, text, i);
	text = update_text(text, i);
	return (actual_line);
}


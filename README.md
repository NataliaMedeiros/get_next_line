/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:39:08 by natalia           #+#    #+#             */
/*   Updated: 2023/12/08 16:48:27 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		((unsigned char *)s)[n - 1] = '\0';
		n--;
	}
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}



size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	n;
	size_t	len_total;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	n = 0;
	src_len = ft_strlen(src);
	len_total = dst_len + src_len;
	if (size > dst_len + 1)
	{
		while ((src[n] != '\0') && ((dst_len + n + 1) < size))
		{
			dst[dst_len + n] = src[n];
			n++;
		}
	}
	dst[dst_len + n] = '\0';
	if (size < dst_len)
		return (src_len + size);
	return (len_total);
}

char	*ft_join_str(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen (s2) + 1;
	s = (char *)malloc(sizeof(char) * len);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, len);
	ft_strlcat(s, s1, len);
	ft_strlcat(s, s2, len);
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;
	size_t	total;

	total = nmemb * size;
	if (nmemb && (total / nmemb) != size)
	{
		return (NULL);
	}
	if ((long) nmemb < 0 || (long) size < 0)
		return (0);
	new = malloc(nmemb * size);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, nmemb * size);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:00:58 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/12/12 16:44:35 by natalia          ###   ########.fr       */
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
		text = ft_join_str(text, new_text);
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
	actual_line = malloc((i+1) * sizeof(char));
	ft_strlcpy(actual_line, text, (i +1));
	text = update_text(text, i);
	return (actual_line);
}

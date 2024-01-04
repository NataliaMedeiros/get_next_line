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

char *ft_strchr (const char *s, char c)
{
	int i;

	i = 0;
	while(s[i] != '\0' && s[i] != (unsigned char) c)
	{
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

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

char *read_file_and_join(int fd, char *text, char *line)
{
	int buffer_read;
	char	*prev_line;
	//char	*temp_line;

	buffer_read = 1;
	prev_line = line;
	if (ft_strchr(line, '\n') != NULL)
		return(line);
	while(buffer_read != 0 && (ft_strchr(text, '\n') == NULL))
	{
		buffer_read = read(fd, text, BUFFER_SIZE);
		if (buffer_read == -1)
		{
			text[0] = '\0';
			free(prev_line);
			return (NULL);
		}
		text[buffer_read] = '\0';
		line = ft_strjoin(prev_line, text);
		if (line == NULL)
		{
			free(prev_line);
			return (NULL);
		}
		free(prev_line);
		prev_line = line;
	}
	return (line);
}

int	find_next_line(char *text)
{
	int i;

	i = 0;
	while(text[i] != '\n' && text[i] != '\0')
	{
		i++;
	}
	if(text[i] == '\n')
		i++;
	return (i);
}

 char *update_text(char *text, int i)
 {
	int	j;

	j = 0;
	while (text[i])
	{
		text[j++] = text[i++];
	}
	text[j] = '\0';
	return (text);
 }

char *get_next_line(int fd)
{
	static char text[BUFFER_SIZE + 1];
	char *line;
	//int line_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//printf("%d\n", line_size);
	line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, text, (ft_strlen(text)));
	line = read_file_and_join(fd, text, line);
	//line_size = find_next_line(text);
	//printf("%d\n", line_size);
	//line = ft_calloc((line_size + 2), sizeof(char));
	//if (line == NULL)
	//	return (NULL);
	//ft_strlcpy(line, text, (line_size + 1));
	if (line[0] == '\0')
		return (free(line), NULL);
	update_text(text, ft_strlen(line));
	return(line);
}
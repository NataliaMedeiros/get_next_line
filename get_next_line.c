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


char *read_file(int fd, char *text)
{
	int buffer_read;
	char *new_text;
	char	*temp;

	buffer_read = 1;
	new_text = malloc((BUFFER_SIZE + 1) * sizeof(char));
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	ft_bzero(new_text, BUFFER_SIZE + 1);
	ft_bzero(temp, BUFFER_SIZE + 1);
	while(buffer_read != 0 && (ft_strchr(text, '\n') == NULL))
	{
		if (buffer_read == BUFFER_SIZE)
			break;
		//printf("Buffer read: %d, BUFFER_SIZE: %d\n", buffer_read, BUFFER_SIZE);
		buffer_read = read(fd, new_text, BUFFER_SIZE);
		if (buffer_read < 0)
		{
			free(new_text);
			free(temp);
			return (NULL);
		}
		//text = ft_strjoin(text, new_text);
		ft_strlcat(temp, text, ft_strlen(text));
		ft_strlcat(temp, new_text, (ft_strlen(new_text) + 1));
		ft_strlcpy(text, temp, (BUFFER_SIZE + 1));
				//printf("Buffer read: %d, BUFFER_SIZE: %d\n", buffer_read, BUFFER_SIZE);

	}
	free(new_text);
	free(temp);
	return (text);
}

int	find_next_line(char *text)
{
	int i;

	i = 0;
	while(text[i] != '\n' && text[i] != '\0')
	{
		i++;
	}
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
	while (text[j] != '\0')
	{
		text[j++] = '\0';
	}
	return (text);
 }

char *get_next_line(int fd)
{
	static char text[BUFFER_SIZE + 1];
	char *line;
	int line_size;

	if (fd == -1)
	{
		return (NULL);
		printf("passei no if");
	}
	read_file(fd, text);
	line_size = find_next_line(text);
	line = ft_calloc((line_size + 2), sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, text, (line_size + 1));
	update_text(text, line_size);
	return(line);
}
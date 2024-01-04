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

char	*combine_strs(char *p_line, char *buf)
{
	char	*joined;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (p_line == NULL || buf == NULL)
		return (NULL);
	joined = malloc((ft_strlen(p_line) + ft_strlen(buf) + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	while (p_line[i] != '\0')
		joined[j++] = p_line[i++];
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		joined[j++] = buf[i++];
	if (buf[i] == '\n')
		joined[j++] = buf[i];
	joined[j] = '\0';
	return (joined);
}

char *read_file(int fd, char *text)
{
	int buffer_read;
	char *new_text;
	char	*temp;

	buffer_read = -1;
	new_text = malloc((BUFFER_SIZE + 1) * sizeof(char));
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	ft_bzero(new_text, BUFFER_SIZE + 1);
	ft_bzero(temp, BUFFER_SIZE + 1);
	while(buffer_read != 0 && (ft_strchr(text, '\n') == NULL))
	{
		//buffer_read = 0;
		//if (buffer_read == BUFFER_SIZE)
		//	break;
		buffer_read = read(fd, new_text, BUFFER_SIZE);
		if (buffer_read < 0)
		{
			free(new_text);
			free(temp);
			return (NULL);
		}
		//new_text[buffer_read] = '\0';
		//new_text = combine_strs(text, new_text);
		text = ft_strjoin(text, new_text);
		//ft_strlcat(temp, text, (ft_strlen(text) + 1));
		//ft_strlcat(temp, new_text, (ft_strlen(new_text) + 1));
		//ft_strlcpy(text, temp, (BUFFER_SIZE + 1));
		//text[buffer_read] = '\0';
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
	int line_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_file(fd, text);
	line_size = find_next_line(text);
	//printf("%d\n", line_size);
	line = ft_calloc((line_size + 2), sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, text, (line_size + 1));
	if (line[0] == '\0')
		return (free(line), NULL);
	update_text(text, line_size);
	return(line);
}
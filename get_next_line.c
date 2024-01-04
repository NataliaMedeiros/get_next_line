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

	buffer_read = 1;
	prev_line = line;
	if (ft_strchr(line, '\n') != NULL)
		return(line);
//	if(line[0] == '\n')
//	{
//		line[0] = line[1];
//		line[ft_strlen(line) - 1] = '\0';
//		return (line);
//	}
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

void	update_text(char *text)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strchr(text, '\n');
	if (temp == NULL)
		return ;
	temp++;
	while (temp[i] != '\0')
	{
		text[i] = temp[i];
		i++;
	}
	text[i] = '\0';
}

char *create_line(char *text)
{
	char *line;
	int i;
	
	i = 0;
	line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (line == NULL)
		return (NULL);
	while (text[i] != '\0' && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char *get_next_line(int fd)
{
	static char text[BUFFER_SIZE + 1];
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	//line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	//if (line == NULL) //esse eu inclui aqui para checar o sucesso do calloc, mas por enquanto ele nao esta sendo necessario por isso esta comentado
	//	return (NULL);
	line = create_line(text);
	//ft_strlcpy(line, text, (ft_strlen(text) + 1));
	line = read_file_and_join(fd, text, line);
	if (line == NULL)
		return (NULL);
	if (line[0] == '\0')
		return (free(line), NULL);
	update_text(text);
	return(line);
}
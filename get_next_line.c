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
	if (text == NULL)
		return (0);
	while (i < BUFFER_SIZE && text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\n')
		i++;
	return (i);
}

char	*read_file(char	*text, int fd)
{
	char	*new_text;
	int		bytes_read;

	if (!text)
		text = ft_calloc(0,0);
	new_text = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, new_text, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(new_text);
			new_text = NULL;
			return (NULL);
		}
		new_text[bytes_read] = '\0';
		char *temp = text;
		text = ft_strjoin(text, new_text);
		free(temp);
	}
	free(new_text);
	new_text = NULL;
	return (text);
}

char	*update_text(char *text, int i)
{
	int	j = 0;

	while (text[i] != '\0')
	{
		text[j] = text[i];
		i++;
		j++;
	}
	while (text[j] != '\0')
	{
		text[j] = '\0';
		j++;
	}
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;
	int			buffer;

	buffer = 0;
	if (!fd || fd < 0 || BUFFER_SIZE < 0)
	{
		//printf("passei por aqui");
		return (NULL);
	}
	//text = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	text = read_file(text, fd);
	//printf("%s\n", text);
	if (text == NULL)
		return (NULL);
	buffer = find_next_line(text);
	line = ft_calloc((buffer + 2), sizeof(char));
	ft_strlcpy(line, text, (buffer + 2));
	text = update_text(text, (buffer + 1));
	if (buffer == 0)
	{
		free(text);
		text = NULL;
		free(line);
		line = NULL;
		return(NULL);
	}
	return (line);
}

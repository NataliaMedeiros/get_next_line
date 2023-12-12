/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:00:58 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/12/12 22:55:29 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new_variable;

	if (nmemb && ((nmemb * size) / nmemb) != size)
		return (NULL);
	if (nmemb < 0 || size < 0)
		return (0);
	new_variable = malloc(nmemb * size);
	if (new_variable == NULL)
		return (NULL);
	while (nmemb > 0)
		new_variable[--nmemb] = '\0';
	return (new_variable);
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

int	find_next_line(char *text)
{
	int		i;

	i = 0;
	if (!text)
		return (0);
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\n')
		i++;
	return (i);
}

char	*read_file(char	*text, int fd)
{
	char	*new_text;
	int		bytes;

	bytes = 1;
	new_text = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while ((find_next_line(text) == 0) && (bytes = read(fd, new_text, BUFFER_SIZE)) > 0)
	{
		new_text[bytes] = '\0';
		// bytes = read(fd, new_text, BUFFER_SIZE);
		// if (bytes == -1)
		// {
		// 	free(text);
		// 	free(new_text);
		// 	return (NULL);
		// }
		text = ft_strjoin(text, new_text);
	}
	free(new_text);
	if (bytes == -1)
	{
		free(text);
		return (NULL);
	}
	//printf("%s\n", text);
	return (text);
}

char	*update_text(char *text, int i)
{
	int	j = 0;

	while (text[i])
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
	int			i;

	i = 0;
	if (text == NULL)
		text = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	//read(fd, text, BUFFER_SIZE);
	text = read_file(text, fd);
	printf("%s\n", text);
	while (text[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, text, (i + 2));
	text = update_text(text, i + 1);
	return (line);
}

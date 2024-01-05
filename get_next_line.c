/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:00:58 by nmedeiro          #+#    #+#             */
/*   Updated: 2024/01/05 15:48:16 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (unsigned char) c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*read_file_and_join(int fd, char *text, char *line)
{
	int		buffer_read;
	char	*prev_line;

	buffer_read = 1;
	prev_line = line;
	while (buffer_read != 0 && (ft_strchr(text, '\n') == NULL))
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
			return (free(prev_line), NULL);
		free(prev_line);
		prev_line = line;
	}
	return (line);
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

char	*create_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_bzero(line, (BUFFER_SIZE + 1));
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

char	*get_next_line(int fd)
{
	static char	text[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = create_line(text);
	line = read_file_and_join(fd, text, line);
	if (line == NULL)
		return (NULL);
	if (line[0] == '\0')
		return (free(line), NULL);
	update_text(text);
	return (line);
}

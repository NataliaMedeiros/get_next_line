/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:39:08 by natalia       #+#    #+#                 */
/*   Updated: 2024/01/08 17:15:26 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_join_str(char *prev_line, char *text)
{
	char	*line;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(prev_line) + find_next_line(text) + 1;
	line = (char *)malloc(sizeof(char) * len);
	if (line == NULL)
		return (NULL);
	while (len > 0)
	{
		((unsigned char *)line)[len - 1] = '\0';
		len--;
	}
	while (prev_line[i] != '\0')
		line[i++] = prev_line[j++];
	j = 0;
	while (text[j] != '\0' && text[j] != '\n')
		line[i++] = text[j++];
	if (text[j] == '\n')
		line[i++] = text[j];
	line[i] = '\0';
	return (line);
}

char	*ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (unsigned char)c)
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
	if (line == NULL)
		return (NULL);
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
		line = ft_join_str(prev_line, text);
		if (line == NULL)
			return (free(prev_line), NULL);
		free(prev_line);
		prev_line = line;
	}
	return (line);
}

char	*create_line(char *text)
{
	char	*line;
	int		i;
	int		n;

	i = 0;
	n = find_next_line(text) + 1;
	line = (char *)malloc((find_next_line(text) + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (n > 0)
	{
		((unsigned char *)line)[n - 1] = '\0';
		n--;
	}
	while (text[i] != '\0' && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		line[i] = '\n';
	return (line);
}

int	find_next_line(char *text)
{
	int		i;

	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\n')
		i++;
	return (i);
}

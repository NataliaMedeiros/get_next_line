/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:39:08 by natalia       #+#    #+#                 */
/*   Updated: 2024/01/08 18:34:50 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join_str(char *prev_line, char *text)
{
	char	*line;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = find_nl(prev_line) + find_nl(text) + 1;
	line = (char *)malloc(sizeof(char) * len);
	if (line == NULL)
		return (NULL);
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

int	find_nl(char *text)
{
	int		i;

	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\n')
		i++;
	return (i);
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

char	*create_line(char *text)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	len = find_nl(text) + 1;
	line = (char *)malloc(len * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (len > 0)
	{
		((unsigned char *)line)[len - 1] = '\0';
		len--;
	}
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

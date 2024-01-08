/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:39:08 by natalia       #+#    #+#                 */
/*   Updated: 2024/01/08 18:08:13 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_join_str(char *prev_line, char *text)
{
	char	*line;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(prev_line) + find_nl(text) + 1;
	line = (char *)malloc(sizeof(char) * len);
	if (line == NULL)
		return (NULL);
	ft_bzero(line, len);
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

// void remove_node(t_text *head, t_text *to_remove)
// {
// 	t_text *current;
// 	t_text *prev_node;

// 	if (to_remove == head)
// 	{
// 		head = to_remove->next;
// 	}
// 	else
// 	{
// 		current = head;
// 		while (current != NULL)
// 		{
// 			if (current == to_remove)
// 			{
// 				prev_node->next = current->next;
// 				break;
// 			}
// 			prev_node = current;
// 			current = current->next;
// 		}
// 	}
// 	free(to_remove);
// }
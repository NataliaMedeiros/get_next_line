/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:00:58 by nmedeiro          #+#    #+#             */
/*   Updated: 2024/01/05 19:30:39 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *ft_strchr(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

char *read_file_and_join(int fd, char *text, char *line)
{
	int buffer_read;
	char *prev_line;

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

void update_text(char *text)
{
	int i;
	char *temp;

	i = 0;
	temp = ft_strchr(text, '\n');
	if (temp == NULL)
		return;
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

t_text *ft_lstnew(int fd)
{
	t_text *new_element;

	new_element = malloc(sizeof(t_text));
	if (new_element == NULL)
		return (NULL);
	new_element->fd = fd;
	// new_element->text = strdup(content);
	new_element->next = NULL;
	return (new_element);
}

// t_text *remove_node(t_text *head, t_text *current)
// {
// 	t_text *to_remove;
// 	t_text *prev_node;

// 	to_remove = current;
// 	if (current == head)
// 	{
// 		head = current->next;
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
// 	return (head);
// }


t_text	*remove_node(t_text *head, t_text *to_remove)
{
	t_text	*current;
	t_text	*prev_node;

	if (to_remove == head)
	{
		head = to_remove->next;
	}
	else
	{
		current = head;
		while (current != NULL)
		{
			if (current == to_remove)
			{
				prev_node->next = current->next;
				break ;
			}
			prev_node = current;
			current = current->next;
		}
	}
	free(to_remove);
	return (head);
}

char *get_next_line(int fd)
{
	char *line;
	static t_text *head;
	t_text *current;

	current = head;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (current)
	{
		if (current->fd == fd)
			break ;
		current = current->next;
	}
	if (!current)
	{
		current = ft_lstnew(fd);
		current->next = head;
		head = current;
	}
	line = create_line(current->text);
	line = read_file_and_join(fd, current->text, line);
	if (line == NULL)
		return (NULL);
	if (line[0] == '\0')
	{
		head = remove_node(head, current);
		return (free(line), NULL);
	}
	update_text(current->text);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/22 17:00:58 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/01/08 18:17:22 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file_and_join(int fd, char *text, char *line)
{
	int		buffer_read;
	char	*prev_line;

	buffer_read = 1;
	if (line == NULL)
		return (NULL);
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
		line = ft_join_str(prev_line, text);
		if (line == NULL)
			return (free(prev_line), NULL);
		free(prev_line);
		prev_line = line;
	}
	return (line);
}

t_text	*ft_lstnew(int fd)
{
	t_text	*new_element;

	new_element = malloc(sizeof(t_text));
	if (new_element == NULL)
		return (NULL);
	new_element->fd = fd;
	new_element->text[0] = '\0';
	new_element->next = NULL;
	return (new_element);
}

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

t_text	*get_or_add_node(t_text *head, int fd)
{
	t_text	*current;

	current = head;
	if (current->fd == fd)
		return (current);
	while (current && current->next != NULL)
	{
		current = current->next;
		if (current->fd == fd)
			return (current);
	}
	current->next = ft_lstnew(fd);
	return (current->next);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_text	*head;
	t_text			*current;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (head == NULL)
	{
		head = ft_lstnew(fd);
		if(head == NULL)
			return (NULL);
		current = head;
	}
	else
		current = get_or_add_node(head, fd);
	line = create_line(current->text);
	line = read_file_and_join(fd, current->text, line);
	if (line == NULL || line[0] == '\0')
	{
		head = remove_node(head, current);
		if (line != NULL && line[0] == '\0')
			free(line);
		return (NULL);
	}
	update_text(current->text);
	return (line);
}

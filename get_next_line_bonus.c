/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/22 17:00:58 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/01/08 13:39:08 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (!head)
	{
		head = ft_lstnew(fd);
		current = head;
	}
	else
		current = get_or_add_node(head, fd);
	line = create_line(current->text);
	if (line == NULL)
		return (NULL);
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

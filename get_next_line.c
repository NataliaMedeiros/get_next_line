/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/22 17:00:58 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/11/22 19:04:46 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	read function:
	size_t read (int fd, void* buf, size_t cnt);
	Parameters
		fd: file descriptor of the file from which data is to be read.
		buf: buffer to read data from
		cnt: length of the buffer
	Return Value
		return Number of bytes read on success
		return 0 on reaching the end of file
		return -1 on error
		return -1 on signal interrupt
*/

#include "get_next_line.h"

int	count_lines(char *content);
{
	//pensei em usar tipo o split para descobrir uantas linhas tenho, 
	//mas nao acho que eo melhor approach pois o ideal seria fazer cada nova linha
	//ser recebida por um node.
}

int	find_new_line(char *content)
{
	int	i;

	i = 0;
	while (content[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	char	*new_line;
	ssize_t	bytes_read;
	int		i;

	new_line = malloc(BUFFER_SIZE * sizeof(char));
	if (new_line == NULL)
		return (NULL);
	bytes_read = read(fd, new_line, BUFFER_SIZE);
	// printf("%zd\n", bytes_read);
	// //if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, new_line, 0) < 0)
	i = 0;
	// if (read(fd, new_line, 0) < 0)
	// 	printf("I found the end of the file\n");
	//le o tamanho total do arquivo
	// while ((read(fd, new_line, 100)) != 0)
	// {
	// 	i++;
	// }
	// printf("%d\n", i);
	while (new_line[i] != '\n')
	{
		i++;
	}
	printf("%d\n", i);
	// write(1, new_line, i);
	// write(1, "\n", 1);
	return (new_line);
}

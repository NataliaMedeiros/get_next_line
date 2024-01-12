/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:34:17 by natalia           #+#    #+#             */
/*   Updated: 2024/01/12 18:08:13 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#define SET_RED "\x1b[31m"
#define SET_GREEN "\x1b[32m"
#define RESET "\x1b[0m"

void	check(int test_number, char *line, char *expected_return)
{
	if (expected_return == NULL)
	{
		if (line == NULL)
			printf("%s%d: OK %s", SET_GREEN, test_number, RESET);
		else
			printf("%s%d: Error %s", SET_RED, test_number, RESET);
	}
	else
	{
		if (strcmp(line, expected_return) == 0)
			printf("%s%d: OK %s", SET_GREEN, test_number, RESET);
		else
			printf("%s%d: Error %s", SET_RED, test_number, RESET);
	}
}

int	main(void)
{
	int		fd;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;

	fd = open("files/empty.txt", O_RDONLY);
	fd1 = open("files/invalid.txt", O_RDONLY);
	fd2 = open("files/1x_nl.txt", O_RDONLY);
	fd3 = open("files/multiple_lines.txt", O_RDONLY);
	fd4 = open("files/7x_nl.txt", O_RDONLY);
	printf("\nInvalid file: ");
	check(1, get_next_line(fd1), NULL);
	check(2, get_next_line(42), NULL);
	close(fd);
	printf("\nEmpty file: ");
	check(1, get_next_line(fd), NULL);
	close(fd);
	fd = open("files/empty.txt", O_RDONLY);
	fd1 = open("files/invalid.txt", O_RDONLY);
	printf("\nMultiples FD: ");
	check(1, get_next_line(fd2), "\n");
	check(2, get_next_line(fd1), NULL);
	check(3, get_next_line(fd3), "Repeated calls (e.g., using a loop) to your get_next_line() function should let\n");
	check(2, get_next_line(fd), NULL);
	check(2, get_next_line(fd4), "\n");
	check(2, get_next_line(fd2), NULL);
	check(2, get_next_line(fd4), "\n");
	check(2, get_next_line(fd3), "you read the text file pointed to by the file descriptor, one line at a time.\n");
	check(2, get_next_line(fd4), "\n");
	//close(fd);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (close(fd), 0);
}

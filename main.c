/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/22 17:13:15 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/01/08 13:34:21 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	Function OPEN:
	int open (const char* Path, int flags);
	Path: Path to the file which we want to open.
	flags: It is used to specify how you want to open the file.
		O_RDONLY 	Opens the file in read-only mode.
		O_CREAT 	Create a file if it doesn’t exist.
	return -1 on error.

*/
#include "get_next_line_bonus.h"
#include <string.h>

#define SET_RED "\x1b[31m"
#define RESET_RED "\x1b[0m"
#define SET_GREEN "\x1b[32m"
#define RESET_GREEN "\x1b[0m"


int ft_fprintf()
{
	FILE	*file;
	char *file_name;

	file_name =  "test.txt";
	file = fopen(file_name, "w");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}
	fprintf(file, "Hello, world!\n");
	fclose(file);
	return (0);
}

void	ft_test_get_next_line(char *file_name)
{
	int		fd;
	char	*lines;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);

	do
	{
		lines = get_next_line(fd);
		printf("%s", lines);
		i++;
	}while (i < 50 && lines != NULL);
	if (lines == NULL && i == 0)
		printf("%s", lines);
	free (lines);
	close(fd);
}

void	check(int test_number, char *line, char *expected_return)
{
	if (expected_return == NULL)
	{
		if (line == NULL)
			printf("%s%d: OK %s", SET_GREEN, test_number, RESET_GREEN);
		else
			printf("%s%d: Error %s", SET_RED, test_number, RESET_RED);
	}
	else
	{
		if (strcmp(line, expected_return) == 0)
			printf("%s%d: OK %s", SET_GREEN, test_number, RESET_GREEN);
		else
			printf("%s%d: Error %s", SET_RED, test_number, RESET_RED);
	}
}

int	main(void)
{
	int		fd;

/* Invalid file */
	fd = open("invalid_file", O_RDONLY);
	printf("Invalid file:");
	/* 1 */	check(1, get_next_line(fd), NULL);
	/* 2 */	check(2, get_next_line(100), NULL);
	/* 3 */ check(3, get_next_line(-1), NULL);
	close(fd);

/* Empty file */
	fd = open("files/empty.txt", O_RDONLY);
	printf("\nEmpty file: ");
	/* 1 */ check(1, get_next_line(fd), NULL);
	close(fd);

/* 1_line_with_nl */
	fd = open("files/1_line_with_nl.txt", O_RDONLY);
	printf("\n1_line_with_\\n: ");
	check (1, get_next_line(fd), "012345678901234567890\n");
	check (2, get_next_line(fd), NULL);
	check (2, get_next_line(fd), NULL);
	close(fd);

/* 7x nl */
	fd = open("files/7x_nl.txt", O_RDONLY);
	printf("\n7 lines with nl: ");
	check (1, get_next_line(fd), "\n");
	check (2, get_next_line(fd), "\n");
	check (3, get_next_line(fd), "\n");
	check (4, get_next_line(fd), "\n");
	check (5, get_next_line(fd), "\n");
	check (6, get_next_line(fd), "\n");
	check (7, get_next_line(fd), "\n");
	check (8, get_next_line(fd), NULL);
	close(fd);

/* Multiple_lines */
	fd = open("files/multiple_lines.txt", O_RDONLY);
	printf("\nMultiple_lines: ");
	check (1, get_next_line(fd), "Repeated calls (e.g., using a loop) to your get_next_line() function should let\n");
	check (2, get_next_line(fd), "you read the text file pointed to by the file descriptor, one line at a time.\n");
	check (3, get_next_line(fd), "Your function should return the line that was read.\n");
	check (4, get_next_line(fd), "If there is nothing else to read or if an error occurred, it should return NULL.\n");
	check (5, get_next_line(fd), "Make sure that your function works as expected both when reading a file and when\n");
	check (6, get_next_line(fd), "reading from the standard input.\n");
	check (7, get_next_line(fd), "Please note that the returned line should include the terminating \\n character,\n");
	check (8, get_next_line(fd), "except if the end of file was reached and does not end with a \\n character.\n");
	check (9, get_next_line(fd), "Your header file get_next_line.h must at least contain the prototype of the\n");
	check (10, get_next_line(fd), "get_next_line() function.\n");
	check (11, get_next_line(fd), "Add all the helper functions you need in the get_next_line_utils.c file.\n");
	check (12, get_next_line(fd), "Repeated calls (e.g., using a loop) to your get_next_line() function should let\n");
	check (13, get_next_line(fd), "you read the text file pointed to by the file descriptor, one line at a time.\n");
	check (14, get_next_line(fd), "Your function should return the line that was read.\n");
	check (15, get_next_line(fd), "If there is nothing else to read or if an error occurred, it should return NULL.\n");
	check (16, get_next_line(fd), "Make sure that your function works as expected both when reading a file and when\n");
	check (17, get_next_line(fd), "reading from the standard input.\n");
	check (18, get_next_line(fd), "Please note that the returned line should include the terminating \\n character,\n");
	check (19, get_next_line(fd), "except if the end of file was reached and does not end with a \\n character.\n");
	check (20, get_next_line(fd), "Your header file get_next_line.h must at least contain the prototype of the\n");
	check (21, get_next_line(fd), "get_next_line() function.\n");
	check (22, get_next_line(fd), "Add all the helper functions you need in the get_next_line_utils.c file.\n");
	check (23, get_next_line(fd), "You will compile your code as follows (a buffer size of 42 is used as an example):\n");
	check (24, get_next_line(fd), "cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c\n");
	check (25, get_next_line(fd), "We consider that get_next_line() has an undefined behavior if the file pointed to\n");
	check (26, get_next_line(fd), "by the file descriptor changed since the last call whereas read() didn’t reach the\n");
	check (27, get_next_line(fd), "end of file.\n");
	check (28, get_next_line(fd), "We also consider that get_next_line() has an undefined behavior when reading\n");
	check (29, get_next_line(fd), "a binary file. However, you can implement a logical way to handle this behavior if\n");
	check (30, get_next_line(fd), "you want to.\n");
	check (31, get_next_line(fd), NULL);

	fd = open("files/multiple_nl.txt", O_RDONLY);
	printf("\nMultiple_nl_lines: ");
		/* 1 */ check(1, get_next_line(fd), "\n");
		/* 2 */ check(2, get_next_line(fd), "\n");
		/* 3 */ check(3, get_next_line(fd), "\n");
		/* 4 */ check(4, get_next_line(fd), "\n");
		/* 5 */ check(5, get_next_line(fd), "\n");
		/* 6 */ check(6, get_next_line(fd), NULL);
	return (0);
}

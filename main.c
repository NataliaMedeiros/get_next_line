/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/22 17:13:15 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/12/13 17:06:38 by nmedeiro      ########   odam.nl         */
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
#include "get_next_line.h"
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

int ft_test_get_next_line()
{
	int		fd;
	char	*lines;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	// while ((lines = get_next_line(fd)) != NULL)
	// {
		lines = get_next_line(fd);
		printf("%s", lines);
	// 	i++;
	// }
	if (lines == NULL && i == 0)
		printf("%s", lines);
	free (lines);
	close(fd);
	return (0);
}

int	main(void)
{
	//ft_fprintf();
	ft_test_get_next_line();
	return (0);
}

/*
Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
• Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
• Make sure that your function works as expected both when reading a file and when
reading from the standard input.
• Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.
• Your header file get_next_line.h must at least contain the prototype of the
get_next_line() function.
• Add all the helper functions you need in the get_next_line_utils.c file.
Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
• Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
• Make sure that your function works as expected both when reading a file and when
reading from the standard input.
• Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.
• Your header file get_next_line.h must at least contain the prototype of the
get_next_line() function.
• Add all the helper functions you need in the get_next_line_utils.c file.
You will compile your code as follows (a buffer size of 42 is used as an example):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
• We consider that get_next_line() has an undefined behavior if the file pointed to
by the file descriptor changed since the last call whereas read() didn’t reach the
end of file.
• We also consider that get_next_line() has an undefined behavior when reading
a binary file. However, you can implement a logical way to handle this behavior if
you want to.
*/

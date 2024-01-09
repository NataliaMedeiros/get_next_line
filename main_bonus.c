#include "get_next_line_bonus.h"

#define SET_RED "\x1b[31m"
#define RESET_RED "\x1b[0m"
#define SET_GREEN "\x1b[32m"
#define RESET_GREEN "\x1b[0m"

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

int main() {
    //char *line;
    int fd1 = open("files/invalid.txt", O_RDONLY);
    int fd2 = open("files/1_line_with_nl.txt", O_RDONLY);
    int fd3 = open("files/1_line_with_nl.txt", O_RDONLY);

    // Use line as needed

	/* Empty file */
	int fd = open("files/empty.txt", O_RDONLY);
	printf("\nEmpty file: ");
	/* 1 */ check(1, get_next_line(fd), NULL);
	close(fd);

    get_next_line(fd2);
	//printf("%s\n", line);

	get_next_line(fd1);
	//printf("%s\n", line);

	get_next_line(fd3);
	//printf("%s\n", line);
    // Use line as needed

    // Close files and free resources as needed
    close(fd1);
    close(fd2);

    return 0;
}

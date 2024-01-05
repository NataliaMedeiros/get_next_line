#include "get_next_line_bonus.h"

int main() {
    char *line;
    int fd1 = open("files/empty.txt", O_RDONLY);
    int fd2 = open("files/multiple_lines.txt", O_RDONLY);


    // Use line as needed

    line = get_next_line(fd2);
	printf("%s\n", line);

	line = get_next_line(fd1);
	printf("%s\n", line);

	line = get_next_line(fd2);
	printf("%s\n", line);
    // Use line as needed

    // Close files and free resources as needed
    close(fd1);
    close(fd2);

    return 0;
}

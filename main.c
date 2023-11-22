/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/22 17:13:15 by nmedeiro      #+#    #+#                 */
/*   Updated: 2023/11/22 18:10:48 by nmedeiro      ########   odam.nl         */
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

int	main(void)
{
	int			fd;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit (1);
	}
	printf("opened the fd = % d\n", fd);
	get_next_line(fd);
	close(fd);
	if (fd < 0)
	{
		perror("Error");
		exit (1);
	}
	printf("closed the fd.\n");
	return (0);
}

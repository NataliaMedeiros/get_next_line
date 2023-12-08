/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:13:15 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/12/08 16:47:14 by natalia          ###   ########.fr       */
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
	char	*lines;
	int		i;

	i = 1;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit (1);
	}
	while ((lines = get_next_line(fd)) != NULL)
	{
		printf("%s\n", lines);
		free (lines);
	}
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:05:07 by nmedeiro          #+#    #+#             */
/*   Updated: 2024/01/05 18:13:09 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				fd;
	char			text[BUFFER_SIZE + 1];
	struct s_list	*next;
}					t_text;

static t_text *fd_list = NULL;

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, char c);

char	*read_file_and_join(int fd, char *text, char *line);

void	update_text(char *text);

char	*create_line(char *text);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strjoin(char *s1, char *s2);

void	ft_bzero(void *s, size_t n);

size_t	ft_strlen(const char *s);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/22 17:05:07 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/01/08 17:11:00 by nmedeiro      ########   odam.nl         */
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
	char			*text;
	struct s_list	*next;
	struct s_list	*first_node;
}					t_text;

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, char c);

char	*read_file_and_join(int fd, char *text, char *line);

void	update_text(char *text);

char	*create_line(char *text);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_join_str(char *s1, char *s2);

void	ft_bzero(void *s, size_t n);

size_t	ft_strlen(const char *s);

t_text	*ft_lstnew(int fd);

t_text	*remove_node(t_text *head, t_text *to_remove);

t_text	*get_or_add_node(t_text *head, int fd);

int		find_next_line(char *text);

#endif

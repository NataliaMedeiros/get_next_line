/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 16:39:08 by natalia       #+#    #+#                 */
/*   Updated: 2023/12/13 12:25:03 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		((unsigned char *)s)[n - 1] = '\0';
		n--;
	}
}


size_t	ft_strlen(const char *s)
{
	int	len;
	
	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	n;
	size_t	len_total;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	n = 0;
	src_len = ft_strlen(src);
	len_total = dst_len + src_len;
	if (size > dst_len + 1)
	{
		while ((src[n] != '\0') && ((dst_len + n + 1) < size))
		{
			dst[dst_len + n] = src[n];
			n++;
		}
	}
	dst[dst_len + n] = '\0';
	if (size < dst_len)
		return (src_len + size);
	return (len_total);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	len;
	len = ft_strlen(s1) + ft_strlen (s2) + 1;
	s = (char *)ft_calloc(sizeof(char), len);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, len);
	ft_strlcat(s, s1, len);
	ft_strlcat(s, s2, len);
	ft_strlcpy(s1, s, len);
	free(s);
	return (s1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;
	size_t	total;
	
	total = nmemb * size;
	if (nmemb != 0 && (total / nmemb != size))
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	new = malloc(total);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, total);
	return (new);
}


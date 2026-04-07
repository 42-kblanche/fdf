/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:47:47 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/07 17:29:26 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

static size_t	check_for_nl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		++i;
	}
	return (0);
}

static int	concat(char **dest, char *src)
{
	size_t	dest_len;
	size_t	src_len;
	char	*t;

	if (!(*dest) || !src)
		return (0);
	dest_len = ft_strlen(*dest);
	src_len = ft_strlen(src);
	t = ft_calloc(dest_len + src_len + 1, sizeof(char));
	if (!t)
		return (0);
	ft_memcpy(t, (*dest), dest_len);
	ft_memcpy(t + dest_len, src, src_len);
	free((*dest));
	(*dest) = t;
	return (1);
}

static int	read_from_file(int fd, char **leftover)
{
	char	*buf;
	int		bytes_read;

	if (!(*leftover))
	{
		*leftover = ft_calloc(1, sizeof(char));
	}
	buf = ft_calloc(GNL_BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0 && !check_for_nl(*leftover))
	{
		bytes_read = read(fd, buf, GNL_BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buf);
			free(*leftover);
			*leftover = NULL;
			return (bytes_read);
		}
		buf[bytes_read] = '\0';
		concat(leftover, buf);
	}
	free(buf);
	return (bytes_read);
}

static char	*extract_line(char *leftover)
{
	char	*ret;
	size_t	i;
	size_t	leftover_len;

	if (!leftover[0])
		return (NULL);
	i = ft_strlen_c(leftover, '\n');
	if (leftover[i] == '\n')
		++i;
	ret = ft_substr(leftover, 0, i);
	leftover_len = ft_strlen(leftover + i);
	ft_memcpy(leftover, leftover + i, leftover_len);
	leftover[leftover_len] = '\0';
	return (ret);
}

char	*ft_gnl(int fd)
{
	char		*ret;
	static char	*leftover;
	int			bytes_read;

	if (fd < 0 || GNL_BUFFER_SIZE < 1)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	bytes_read = read_from_file(fd, &leftover);
	if (leftover == NULL)
		return (NULL);
	ret = extract_line(leftover);
	if (!ret && !bytes_read)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	return (ret);
}

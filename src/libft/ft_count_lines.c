/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:15:32 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/07 17:42:59 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_count_lines(int fd)
{
	char	*line;
	size_t	ret;

	ret = 0;
	line = ft_gnl(fd);
	while (line)
	{
		++ret;
		free(line);
		line = ft_gnl(fd);
	}
	return (ret);
}

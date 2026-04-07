/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:18:32 by kblanche          #+#    #+#             */
/*   Updated: 2025/11/11 22:00:22 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	rlen;
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen)
	{
		r = ft_calloc(1, 1);
		if (!r)
			return (0);
		return (r);
	}
	slen = ft_strlen(s + start);
	if (len > slen)
		rlen = slen + 1;
	else
		rlen = len + 1;
	r = ft_calloc(rlen, sizeof(char));
	if (!r)
		return (0);
	ft_strlcpy(r, s + start, rlen);
	return (r);
}

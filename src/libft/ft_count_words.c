/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:12:56 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/07 17:31:33 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	r;
	int		bflag;

	i = 0;
	r = 0;
	bflag = 1;
	while (s[i])
	{
		if (bflag && s[i] != c)
		{
			++r;
			bflag = 0;
		}
		else if (s[i] == c)
			bflag = 1;
		++i;
	}
	return (r);
}

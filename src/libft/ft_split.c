/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 22:51:06 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/07 17:32:47 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	word_len(const char *s, char c)
{
	size_t	r;

	r = 0;
	while (s[r] && s[r] != c)
		++r;
	return (r);
}

static void	free_tab(char **t, size_t size)
{
	size_t	i;

	i = 0;
	while (i <= size)
	{
		free(t[i]);
		++i;
	}
	free(t);
}

static int	substr_check(const char *s, char c, char **r, size_t k)
{
	r[k] = ft_substr(s, 0, word_len(s, c));
	if (!r[k])
	{
		free_tab(r, ft_count_words(s, c));
		return (0);
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	k;
	char	**r;
	int		bflag;

	i = 0;
	k = 0;
	r = (char **)ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!r)
		return (0);
	bflag = 1;
	while (s[i])
	{
		if (bflag && s[i] != c)
		{
			bflag = 0;
			if (!substr_check(s + i, c, r, k))
				return (0);
			++k;
		}
		else if (s[i] == c)
			bflag = 1;
		++i;
	}
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 22:22:50 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/31 09:28:30 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mathft.h"

int	ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

float	ft_min_float(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

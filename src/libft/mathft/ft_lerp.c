/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lerp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 22:57:02 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/30 23:13:15 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mathft.h"

int	ft_lerp_int(int a, int b, float t)
{
	return (a + (int)((b - a) * t));
}

float	ft_ilerp_int(int a, int b, int c)
{
	return ((float)(a - c) / (float)(a - b));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:22:26 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/31 09:24:17 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mathft.h"

t_quadi	ft_quadi(t_vec2i a, t_vec2i b, t_vec2i c, t_vec2i d)
{
	t_quadi	ret;

	ret.a = a;
	ret.b = b;
	ret.c = c;
	ret.d = d;
	return (ret);
}

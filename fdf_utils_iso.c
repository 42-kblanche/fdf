/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_iso.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:30:05 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/31 14:35:55 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"

t_vec2i	fdf_iso_proj(t_vec3i vec)
{
	t_vec2i	ret;

	ret.x = (WIN_SIZE_X / 2 + (vec.x - vec.y) * X_RATIO);
	ret.y = (WIN_SIZE_Y / 20 + (vec.x + vec.y) * Y_RATIO);
	ret.y -= Z_RATIO * vec.z;
	return (ret);
}

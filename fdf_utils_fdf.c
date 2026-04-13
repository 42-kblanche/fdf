/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:43:43 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/13 14:44:15 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"
#include "src/libft/libft.h"
#include <stdlib.h>

t_vec3i	fdf_calc_vec3(const t_fdf *fdf, int x, int y)
{
	t_vec3i	ret;

	ret.x = x;
	ret.y = y;
	ret.z = fdf_calc_z(fdf, x, y);
	return (ret);
}

int	fdf_calc_z(const t_fdf *fdf, int x, int y)
{
	return (fdf->data[y * fdf->width + x]);
}

t_vec2i	fdf_iso_proj(t_vec3i vec)
{
	t_vec2i	ret;

	ret.x = (WIN_SIZE_X / 2 + (vec.x - vec.y) * X_RATIO);
	ret.y = (WIN_SIZE_Y / 20 + (vec.x + vec.y) * Y_RATIO);
	ret.y -= Z_RATIO * vec.z;
	return (ret);
}

t_vec2i	*fdf_iso_coord(const t_fdf *fdf)
{
	t_vec2i	*iso_coords;
	size_t	i;
	size_t	j;
	t_vec3i	tmp_3d_point;

	iso_coords = ft_calloc(fdf->height * fdf->width, sizeof(t_vec2i));
	if (!iso_coords)
		return (NULL);
	i = 0;
	while (i < fdf->width)
	{
		j = 0;
		while (j < fdf->height)
		{
			tmp_3d_point = fdf_calc_vec3(fdf, i, j);
			iso_coords[i + j * fdf->width] = fdf_iso_proj(tmp_3d_point);
			++j;
		}
		++i;
	}
	return (iso_coords);
}

int	fdf_draw(t_data *img, const t_fdf *fdf, t_color c)
{
	t_vec2i	*iso_coord;

	iso_coord = fdf_iso_coord(fdf);
	if (!iso_coord)
		return (ERROR_MALLOC_ISO_COORDS);
	fdf_iso_scale(fdf, &iso_coord);
	fdf_iso_translate(fdf, &iso_coord);
	fdf_iso_draw(img, fdf, c, iso_coord);
	free(iso_coord);
	return (0);
}

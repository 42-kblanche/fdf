/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_iso.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:30:05 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/13 14:30:59 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"
#include <math.h>

t_bbi	fdf_iso_bb(const t_fdf *fdf, const t_vec2i *iso_coord)
{
	t_bbi	ret;
	t_vec2i	curr;
	size_t	i;

	ret.max = iso_coord[0];
	ret.min = iso_coord[0];
	i = 1;
	while (i < fdf->height * fdf->width)
	{
		curr = iso_coord[i];
		if (curr.x > ret.max.x)
			ret.max.x = curr.x;
		if (curr.y > ret.max.y)
			ret.max.y = curr.y;
		if (curr.x < ret.min.x)
			ret.min.x = curr.x;
		if (curr.y < ret.min.y)
			ret.min.y = curr.y;
		++i;
	}
	return (ret);
}

void	fdf_iso_scale(const t_fdf *fdf, t_vec2i **iso_coord)
{
	t_bbi	iso_bb;
	size_t	i;
	double	ratio;

	iso_bb = fdf_iso_bb(fdf, *iso_coord);
	ratio = fmax((double)(iso_bb.max.x - iso_bb.min.x) / PADDED_WIN_X,
			(double)(iso_bb.max.y - iso_bb.min.y) / PADDED_WIN_Y);
	i = 0;
	while (i < fdf->height * fdf->width)
	{
		(*iso_coord)[i].x = (int)((double)((*iso_coord)[i].x) / ratio);
		(*iso_coord)[i].y = (int)((double)((*iso_coord)[i].y) / ratio);
		++i;
	}
}

t_vec2i	fdf_calc_translate(const t_fdf *fdf, const t_vec2i *iso_coord)
{
	t_bbi	iso_bb;
	t_vec2i	trans_vector;

	iso_bb = fdf_iso_bb(fdf, iso_coord);
	trans_vector.x = (WIN_SIZE_X - iso_bb.max.x + iso_bb.min.x) / 2
		- iso_bb.min.x;
	trans_vector.y = (WIN_SIZE_Y - iso_bb.max.y + iso_bb.min.y) / 2
		- iso_bb.min.y;
	return (trans_vector);
}

void	fdf_iso_translate(const t_fdf *fdf, t_vec2i **iso_coord)
{
	size_t	i;
	t_vec2i	trans_vector;

	trans_vector = fdf_calc_translate(fdf, *iso_coord);
	i = 0;
	while (i < fdf->height * fdf->width)
	{
		(*iso_coord)[i].x += trans_vector.x;
		(*iso_coord)[i].y += trans_vector.y;
		++i;
	}
}

void	fdf_iso_draw(t_data *img, const t_fdf *fdf,
	t_color c, const t_vec2i *iso_coord)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < fdf->width)
	{
		j = 0;
		while (j < fdf->height)
		{
			if (i < fdf->width - 1)
				fdf_line_put(img, iso_coord[i + fdf->width * j],
					iso_coord[i + 1 + fdf->width * j], c);
			if (j < fdf->height - 1)
				fdf_line_put(img, iso_coord[i + fdf->width * j],
					iso_coord[i + fdf->width * (j + 1)], c);
			++j;
		}
		++i;
	}
}

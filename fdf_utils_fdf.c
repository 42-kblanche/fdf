/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:43:43 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/01 16:30:07 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"
#include "src/libft/printfft.h"

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

void	fdf_print_data(const t_fdf *fdf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < fdf->width)
	{
		j = 0;
		while (j < fdf->height)
		{
			ft_printf("%d ", fdf_calc_z(fdf, i, j));
			++j;
		}
		ft_printf("\n");
		++i;
	}
}

void	fdf_draw(t_data *img, const t_fdf *fdf, t_color c)
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
				fdf_line_put(img, fdf_iso_proj(fdf_calc_vec3(fdf, i, j)), fdf_iso_proj(fdf_calc_vec3(fdf, i + 1, j)), c);
			if (j < fdf->height - 1)
				fdf_line_put(img, fdf_iso_proj(fdf_calc_vec3(fdf, i, j)), fdf_iso_proj(fdf_calc_vec3(fdf, i, j + 1)), c);
			++j;
		}
		++i;
	}
}

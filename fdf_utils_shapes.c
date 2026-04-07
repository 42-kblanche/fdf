/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_shapes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:12:43 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/07 23:13:15 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"
#include "src/libft/mathft.h"

void	fdf_checker(t_data *img)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WIN_SIZE_X)
	{
		j = 0;
		while (j < WIN_SIZE_Y)
		{
			if ((i / 50 - j / 50) % 2)
				fdf_pixel_put(img, i, j, ft_color(
						j * 255 / WIN_SIZE_Y,
						i * 255 / WIN_SIZE_X,
						j * 255 / (WIN_SIZE_Y * 2)
						+ i * 255 / (WIN_SIZE_X * 2),
						0));
			++j;
		}
		++i;
	}
}

static void	line_put_loop_h(t_data *img, t_vec2i a, t_vec2i b, t_color c)
{
	int	i;
	int	j;

	i = ft_min_int(a.x, b.x) - LINE_WIDTH / 2;
	while (i < ft_max_int(a.x, b.x) + LINE_WIDTH / 2)
	{
		j = 0;
		while (j < LINE_WIDTH)
		{
			fdf_pixel_put(img, i, ft_lerp_int(a.y, b.y,
					ft_ilerp_int(a.x, b.x, i)) + (j - LINE_WIDTH / 2), c);
			++j;
		}
		++i;
	}
}

static void	line_put_loop_v(t_data *img, t_vec2i a, t_vec2i b, t_color c)
{
	int	i;
	int	j;

	i = ft_min_int(a.y, b.y) - LINE_WIDTH / 2;
	while (i < ft_max_int(a.y, b.y) + LINE_WIDTH / 2)
	{
		j = 0;
		while (j < LINE_WIDTH)
		{
			fdf_pixel_put(img, ft_lerp_int(a.x, b.x,
					ft_ilerp_int(a.y, b.y, i)) + (j - LINE_WIDTH / 2), i, c);
			++j;
		}
		++i;
	}
}

void	fdf_line_put(t_data *img, t_vec2i a, t_vec2i b, t_color c)
{
	if (ft_max_int(a.y, b.y) - ft_min_int(a.y, b.y)
		> ft_max_int(a.x, b.x) - ft_min_int(a.x, b.x))
		line_put_loop_v(img, a, b, c);
	else
		line_put_loop_h(img, a, b, c);
}

void	fdf_quad_put(t_data *img, t_quadi q, t_color col)
{
	fdf_line_put(img, q.a, q.b, col);
	fdf_line_put(img, q.b, q.c, col);
	fdf_line_put(img, q.c, q.d, col);
	fdf_line_put(img, q.d, q.a, col);
}

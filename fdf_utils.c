/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:12:43 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/07 21:26:00 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"
#include "src/libft/printfft.h"

size_t	fdf_pixel_offset(int x, int y, t_data *data)
{
	return (y * data->line_length + x * (data->bpp / 8));
}

int	fdf_pixel_put(t_data *img, int x, int y, t_color color)
{
	char			*pixel;
	unsigned int	*pixel_color;

	if (x < 0 || x > WIN_SIZE_X || y < 0 || y > WIN_SIZE_Y)
		return (1);
	pixel = img->addr + fdf_pixel_offset(x, y, img);
	pixel_color = (unsigned int *)pixel;
	*pixel_color = (unsigned int)color;
	return (0);
}

void	fdf_err_message(int err_code)
{
	if (err_code == ERROR_MALLOC_FDF_DATA)
		ft_errorf("Error while allocating memory for FDF data.\n");
	if (err_code == ERROR_READ_FROM_FILE)
		ft_errorf("Error while reading from file.\n");
	if (err_code == ERROR_MLX)
		ft_errorf("Error while using the MLX.\n");
	if (err_code == ERROR_MLX_INIT)
		ft_errorf("Error while initializing the MLX instance.\n");
	if (err_code == ERROR_MLX_WIN)
		ft_errorf("Error while initializing the MLX window.\n");
	if (err_code == ERROR_MLX_IMG)
		ft_errorf("Error while initializing an MLX image.\n");
	if (err_code == ERROR_FILE_EMPTY)
		ft_errorf("Error: file empty.\n");
	if (err_code == ERROR_MALFORMED_FDF)
		ft_errorf("Error: fdf data invalid.\n");
	if (err_code == ERROR_MALLOC_EXTRACT_CELLS)
		ft_errorf("Error while creating fdf structure.\n");
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

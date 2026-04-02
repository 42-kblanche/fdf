/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:12:43 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/01 15:57:43 by kblanche         ###   ########.fr       */
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
		ft_errorf("Error while allocating memory for FDF data\n");
	if (err_code == ERROR_MLX)
		ft_errorf("Error while using the MLX\n");
	if (err_code == ERROR_READ_FROM_FILE)
		ft_errorf("Error while reading from file\n");
}

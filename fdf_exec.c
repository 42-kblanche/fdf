/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:49:12 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/07 20:03:37 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"
#include "src/mlx/mlx.h"
#include <stdlib.h>

static int	bind_hooks(t_vars *mlx)
{
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_hook(mlx->win, EVENT_DESTROY, 0, quit_hook, mlx);
	return (0);
}

static void	close_fdf(t_vars *mlx, t_data *img, t_fdf *fdf_data)
{
	free(fdf_data->data);
	fdf_data->data = NULL;
	mlx_destroy_image(mlx->mlx, img->img);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}

static void	fdf_render(t_vars *mlx, t_data *img, t_fdf *fdf_data)
{
	fdf_draw(img, fdf_data, HEX_COLOR_RED);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}

static int	fdf_init(t_vars *mlx, t_data *img)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (ERROR_MLX_INIT);
	mlx->win = mlx_new_window(mlx->mlx, WIN_SIZE_X, WIN_SIZE_Y, "fdf");
	if (!mlx->win)
	{
		close_fdf(mlx, img, NULL);
		return (ERROR_MLX_WIN);
	}
	img->img = mlx_new_image(mlx->mlx, WIN_SIZE_X, WIN_SIZE_Y);
	if (!img->img)
	{
		close_fdf(mlx, img, NULL);
		return (ERROR_MLX_IMG);
	}
	img->addr = mlx_get_data_addr(img->img,
			&img->bpp, &img->line_length, &img->endian);
	return (0);
}

int	fdf_exec(t_fdf *fdf_data)
{
	t_vars	mlx;
	t_data	img;
	int		err_code;

	err_code = fdf_init(&mlx, &img);
	if (err_code)
		return (err_code);
	bind_hooks(&mlx);
	fdf_render(&mlx, &img, fdf_data);
	mlx_loop(mlx.mlx);
	close_fdf(&mlx, &img, fdf_data);
	return (0);
}

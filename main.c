/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:53:15 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/01 16:44:15 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"
#include "src/libft/printfft.h"
#include "src/libft/libft.h"
#include "src/mlx/mlx.h"
#include <stdlib.h>
#include <math.h>

static int	bind_hooks(t_vars *mlx)
{
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_hook(mlx->win, EVENT_DESTROY, 0, quit_hook, mlx);
	return (0);
}

static int	parse_file(char *filename, t_fdf *fdf_data)
{
	size_t	i;
	size_t	size;

	(void)filename;
	i = 0;
	fdf_data->width = 10;
	fdf_data->height = 10;
	size = fdf_data->width * fdf_data->height;
	fdf_data->data = ft_calloc(size, sizeof(int));
	if (!fdf_data->data)
		return (ERROR_MALLOC_FDF_DATA);
	while (i < fdf_data->height * fdf_data->width)
	{
		fdf_data->data[i] = 10.f * sinf((i % fdf_data->height)/ 3.14f) + cosf((i / fdf_data->width)/ 3.14f) * 10.f - 10;
		++i;
	}
	fdf_print_data(fdf_data);
	return (0);
}

static int	fdf(t_fdf *fdf_data)
{
	t_vars	mlx;
	t_data	img;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_SIZE_X, WIN_SIZE_Y, "fdf");
	bind_hooks(&mlx);
	img.img = mlx_new_image(mlx.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	img.addr = mlx_get_data_addr(img.img,
			&img.bpp, &img.line_length, &img.endian);
	fdf_checker(&img);
	fdf_quad_put(&img, ft_quadi(ft_vec2i(1, 1),
			ft_vec2i(WIN_SIZE_X - 150, 75),
			ft_vec2i(WIN_SIZE_X - 75, WIN_SIZE_Y - 75),
			ft_vec2i(75, WIN_SIZE_Y - 75)), HEX_COLOR_PUR);
	fdf_draw(&img, fdf_data, HEX_COLOR_RED);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	free(fdf_data->data);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*filename;
	t_fdf	fdf_data;
	int		err_ret;

	err_ret = 0;
	if (argc < 2)
		ft_errorf("No file given as argument.\n");
	if (argc > 2)
		ft_errorf("Too many arguments.\n");
	if (argc != 2)
		return (1);
	filename = argv[1];
	ft_printf("USING FILE %s\n", filename);
	err_ret = parse_file(filename, &fdf_data);
	if (!err_ret)
		err_ret = fdf(&fdf_data);
	fdf_err_message(err_ret);
	return (err_ret);
}

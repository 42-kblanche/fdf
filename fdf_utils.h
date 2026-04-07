/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:09:58 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/07 23:14:28 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_H
# define FDF_UTILS_H

# define WIN_SIZE_X 640
# define WIN_SIZE_Y 480
# define PAD_SIZE_X 10
# define PAD_SIZE_Y 10
# define PADDED_WIN_X 620
# define PADDED_WIN_Y 460
# define HEX_COLOR_RED 0x00FF0000
# define HEX_COLOR_PUR 0x00876497
# define LINE_WIDTH 1
# define X_RATIO 30
# define Y_RATIO 15
# define Z_RATIO 10
# define EVENT_DESTROY 17
# define ESCAPE_KEY_CODE 65307
# define CLOSE_KEY_CODE 1890534152

# include "src/libft/graphicft.h"
# include "src/libft/mathft.h"
# include <stddef.h>

enum	e_err_codes
{
	ERROR_MALLOC_FDF_DATA = 2,
	ERROR_READ_FROM_FILE,
	ERROR_MLX,
	ERROR_MLX_INIT,
	ERROR_MLX_WIN,
	ERROR_MLX_IMG,
	ERROR_FILE_EMPTY,
	ERROR_MALFORMED_FDF,
	ERROR_MALLOC_EXTRACT_CELLS,
};

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fdf
{
	int		*data;
	size_t	height;
	size_t	width;
}				t_fdf;

size_t	fdf_pixel_offset(int x, int y, t_data *data);
int		fdf_pixel_put(t_data *img, int x, int y, t_color color);
void	fdf_err_message(int err_code);

void	fdf_checker(t_data *img);
void	fdf_line_put(t_data *img, t_vec2i a, t_vec2i b, t_color c);
void	fdf_quad_put(t_data *img, t_quadi q, t_color col);

t_vec2i	fdf_iso_proj(t_vec3i vec);
t_vec2i	*fdf_iso_coord(const t_fdf *fdf);
void	fdf_iso_scale(const t_fdf *fdf, t_vec2i **iso_coord);
void	fdf_iso_translate(const t_fdf *fdf, t_vec2i **iso_coord);
void	fdf_iso_draw(t_data *img, const t_fdf *fdf,
			t_color c, const t_vec2i *iso_coord);
t_vec2i	fdf_calc_translate(const t_fdf *fdf, const t_vec2i *iso_coord);

t_vec3i	fdf_calc_vec3(const t_fdf *fdf, int x, int y);
int		fdf_calc_z(const t_fdf *fdf, int x, int y);
void	fdf_print_data(const t_fdf *fdf);
void	fdf_draw(t_data *img, const t_fdf *fdf, t_color c);

int		key_hook(int keycode, t_vars *mlx);
int		quit_hook(t_vars *mlx);

int		fdf_exec(t_fdf *fdf_data);

#endif

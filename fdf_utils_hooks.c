/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:04:55 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/14 13:41:42 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"
#include "src/mlx/mlx.h"

int	key_hook(int keycode, t_vars *mlx)
{
	if (keycode == ESCAPE_KEY_CODE)
		quit_hook(mlx);
	return (0);
}

int	quit_hook(t_vars *mlx)
{
	mlx_loop_end(mlx->mlx);
	return (0);
}

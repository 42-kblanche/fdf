/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:14:15 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/31 09:27:42 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHFT_H
# define MATHFT_H

typedef struct s_vec2_int
{
	int	x;
	int	y;
}	t_vec2i;

typedef struct s_vec3_int
{
	int	x;
	int	y;
	int	z;
}	t_vec3i;

typedef struct s_vec2_float
{
	float	x;
	float	y;
}	t_vec2f;

typedef struct s_quad_int
{
	t_vec2i	a;
	t_vec2i	b;
	t_vec2i	c;
	t_vec2i	d;
}	t_quadi;

typedef struct s_bounding_box_int
{
	t_vec2i	min;
	t_vec2i	max;
}	t_bbi;

typedef struct s_bounding_box_float
{
	t_vec2f	min;
	t_vec2f	max;
}	t_bbf;

t_vec2i	ft_vec2i(int a, int b);
t_quadi	ft_quadi(t_vec2i a, t_vec2i b, t_vec2i c, t_vec2i d);
int		ft_min_int(int a, int b);
int		ft_max_int(int a, int b);
int		ft_lerp_int(int a, int b, float t);
float	ft_ilerp_int(int a, int b, int c);

#endif

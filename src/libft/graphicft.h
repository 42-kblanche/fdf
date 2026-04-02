/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphicft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:14:15 by kblanche          #+#    #+#             */
/*   Updated: 2026/03/30 22:47:02 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICFT_H
# define GRAPHICFT_H

# define FT_BLUE 255
# define FT_GREEN 65280
# define FT_RED 16711680
# define FT_50P 2130706432
# define FT_0P 4278190080

typedef int	t_color;

t_color	ft_color(int r, int g, int b, int a);

#endif

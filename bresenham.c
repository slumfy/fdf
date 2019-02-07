/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 04:35:14 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/07 23:19:43 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(t_data *data, int x0, int y0, int x1, int y1)
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int	e2;

	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		if ((x0 < LENGTH && x0 > 0) && (y0 < HEIGHT && y0 > 0))
			mlx_pixel_put(data->mlx, data->win, x0, y0, 0xFFFFFF);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

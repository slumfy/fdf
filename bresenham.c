/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 04:35:14 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/07 00:03:45 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_data *data, int x0, int y0, int x1, int y1)
{
	int		deltx;
	int		delty;
	double	deltr;
	double	error;
	int		y;

	deltx = x1 - x0;
	delty = y1 - y0;
	deltr = fabs((double)delty / (double)deltx);
	y = y0;
	error = 0.0;
	while (x0 != x1 || y != y1)
	{

		mlx_pixel_put(data->mlx, data->win, x0, y, 0xFFFFFF);
		error += deltr;
		if (error >= 0.5)
		{
			y = y + (delty >= 0 ? 1 : -1);
			error -= 1.0;
		}
		if (x0 != x1)
			x0 += deltx >= 0 ? 1 : -1;
	}
}

void line(t_data *data, int x0, int y0, int x1, int y1)
{

	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;

	while(1)
	{
		mlx_pixel_put(data->mlx, data->win, x0, y0, 0xFFFFFF);
		if (x0==x1 && y0==y1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void	bresenham_blue(t_data *data, int x0, int y0, int x1, int y1)
{
	int		deltx;
	int		delty;
	double	deltr;
	double	error;
	int		y;

	deltx = x1 - x0;
	delty = y1 - y0;
	deltr = fabs((double)delty / (double)deltx);
	y = y0;
	error = 0.0;
	while (x0 != x1 || y != y1)
	{

		mlx_pixel_put(data->mlx, data->win, x0, y, 0x0000FF);
		error += deltr;
		if (error >= 0.5)
		{
			y = y + (delty >= 0 ? 1 : -1);
			error -= 1.0;
		}
		if (x0 != x1)
			x0 += deltx >= 0 ? 1 : -1;
	}
}

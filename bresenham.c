/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 04:35:14 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/06 04:33:14 by rvalenti         ###   ########.fr       */
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

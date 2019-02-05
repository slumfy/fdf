/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 04:35:14 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/05 05:22:00 by rvalenti         ###   ########.fr       */
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
	deltr = (double)delty / (double)deltx;
	y = y0;
	error = 0.0;
	printf("deltx=%d delty=%d deltr= %lf\n",deltx, delty, deltr);
	while (x0 != x1)
	{
		mlx_pixel_put(data->mlx, data->win, x0, y, 0xFFFFFF);
		error += deltr;
		if (error >= 0.5)
		{
		y = y + (delty >= 0 ? 1 : -1);
		error -= 1.0;
		}
		x0 += deltx >= 0 ? 1 : -1;
	}
}

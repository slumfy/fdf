/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 04:44:08 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/07 23:14:45 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_data *data, int larg, int haut, int trig)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < data->y_max)
	{
		x = 0;
		while (x < data->x_max)
		{
			if (x + 1 < data->x_max)
			{
				if (trig)
					iso(data, x, y, x + 1, y);
				else
					parallel(data, x, y, x + 1, y);
				line(data, data->point.x + larg, data->point.y + haut,
						data->point.x1 + larg, data->point.y1 + haut);
			}
			if (y + 1 < data->y_max)
			{
				if (trig)
					iso(data, x, y, x, y + 1);
				else
					parallel(data, x, y, x, y + 1);
				line(data, data->point.x + larg, data->point.y + haut,
						data->point.x1 + larg, data->point.y1 + haut);
			}
			x++;
		}
		y++;
	}
}

int		iso(t_data *data, int x, int y, int x1, int y1)
{
	int	gap;
	int ox;
	int ox1;
	int oy;
	int oy1;


	ox = x - data->x_max / 2;
	ox1 = x1 - data->x_max / 2;
	oy = y - data->y_max / 2;
	oy1 = y1 - data->y_max / 2;
	gap = data->gap;
	data->point.x = ((ox - oy) * cos(0.523599)) * gap;
	data->point.y = (-data->map[y][x] + (ox + oy) * sin(0.523599)) * gap;
	data->point.x1 = ((ox1 - oy1) * cos(0.523599)) * gap;
	data->point.y1 = (-data->map[y1][x1] + (ox1 + oy1) * sin(0.523599)) * gap;
	return (0);
}

int		parallel(t_data *data, int x, int y, int x1, int y1)
{
	int	gap;
	int ox;
	int ox1;
	int oy;
	int oy1;

	ox = x - data->x_max / 2;
	ox1 = x1 - data->x_max / 2;
	oy = y - data->y_max / 2;
	oy1 = y1 - data->y_max / 2;
	gap = data->gap;
	data->point.x = (ox - data->map[y][x] * cos(0.785398)) * gap;
	data->point.y = (oy - data->map[y][x] * sin(0.785398)) * gap;
	data->point.x1 = (ox1 - data->map[y1][x1] * cos(0.785398)) * gap;
	data->point.y1 = (oy1 - data->map[y1][x1] * sin(0.785398)) * gap;
	return (0);
}

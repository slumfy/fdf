/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 04:44:08 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/08 02:42:14 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_data *data, int larg, int haut)
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
				proj(data, x, y, x + 1, y);
				line(data, larg, haut);
			}
			if (y + 1 < data->y_max)
			{
				proj(data, x, y, x, y + 1);
				line(data, larg, haut);
			}
			x++;
		}
		y++;
	}
}

void	proj(t_data *data, int x, int y, int x1, int y1)
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
	if (data->proj)
	{
		data->p.x = ((ox - oy) * cos(0.523599)) * gap;
		data->p.y = (-data->map[y][x] + (ox + oy) * sin(0.523599)) * gap;
		data->p.x1 = ((ox1 - oy1) * cos(0.523599)) * gap;
		data->p.y1 = (-data->map[y1][x1] + (ox1 + oy1) * sin(0.523599)) * gap;
	}
	else
	{
		data->p.x = (ox - data->map[y][x] * cos(0.785398)) * gap;
		data->p.y = (oy - data->map[y][x] * sin(0.785398)) * gap;
		data->p.x1 = (ox1 - data->map[y1][x1] * cos(0.785398)) * gap;
		data->p.y1 = (oy1 - data->map[y1][x1] * sin(0.785398)) * gap;
	}
}

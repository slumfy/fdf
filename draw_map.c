/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 04:44:08 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/08 07:20:39 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_data *d, int larg, int haut)
{
	t_point	abs;

	abs.y = -1;
	while (++(abs.y) < d->y_max)
	{
		abs.x = 0;
		while (abs.x < d->x_max)
		{
			if (abs.x + 1 < d->x_max)
			{
				abs.x1 = abs.x + 1;
				abs.y1 = abs.y;
				proj(d, abs);
				line(d, larg, haut);
			}
			if (abs.y + 1 < d->y_max)
			{
				abs.x1 = abs.x;
				abs.y1 = abs.y + 1;
				proj(d, abs);
				line(d, larg, haut);
			}
			abs.x++;
		}
	}
}

void	proj(t_data *d, t_point abs)
{
	int	gap;
	int ox;
	int ox1;
	int oy;
	int oy1;

	ox = abs.x - d->x_max / 2;
	ox1 = abs.x1 - d->x_max / 2;
	oy = abs.y - d->y_max / 2;
	oy1 = abs.y1 - d->y_max / 2;
	gap = d->gap;
	if (d->proj)
	{
		d->p.x = ((ox - oy) * cos(0.523599)) * gap;
		d->p.y = (-d->map[abs.y][abs.x] + (ox + oy) * sin(0.523599)) * gap;
		d->p.x1 = ((ox1 - oy1) * cos(0.523599)) * gap;
		d->p.y1 = (-d->map[abs.y1][abs.x1] + (ox1 + oy1) * sin(0.523599)) * gap;
	}
	else
	{
		d->p.x = (ox - d->map[abs.y][abs.x] * cos(0.785398)) * gap;
		d->p.y = (oy - d->map[abs.y][abs.x] * sin(0.785398)) * gap;
		d->p.x1 = (ox1 - d->map[abs.y1][abs.x1] * cos(0.785398)) * gap;
		d->p.y1 = (oy1 - d->map[abs.y1][abs.x1] * sin(0.785398)) * gap;
	}
}

void	line(t_data *d, int l, int h)
{
	t_bre	b;

	b.dx = abs((d->p.x1 + l) - (d->p.x + l));
	b.sx = d->p.x < d->p.x1 ? 1 : -1;
	b.dy = abs((d->p.y1 + h) - (d->p.y + h));
	b.sy = d->p.y < d->p.y1 ? 1 : -1;
	b.err = (b.dx > b.dy ? b.dx : -b.dy) / 2;
	while (1)
	{
		if (is_in_win(d->p, l, h))
			mlx_pixel_put(d->mlx, d->win, d->p.x + l, d->p.y + h, 0xFFFFFF);
		if (d->p.x == d->p.x1 && d->p.y == d->p.y1)
			break ;
		b.e2 = b.err;
		if (b.e2 > -b.dx)
		{
			b.err -= b.dy;
			d->p.x += b.sx;
		}
		if (b.e2 < b.dy)
		{
			b.err += b.dx;
			d->p.y += b.sy;
		}
	}
}

int		is_in_win(t_point p, int l, int h)
{
	if ((p.x + l < LENGTH && p.x + l > 0)
			&& (p.y + h < HEIGHT && p.y + h > 0))
		return (1);
	return (0);
}

int		is_int(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+')
				&& !ft_isdigit(str[i + 1]))
			return (0);
		if (!ft_isdigit(str[i]) && str[i] != ' '
				&& str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

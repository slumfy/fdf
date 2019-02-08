/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 04:44:08 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/08 11:00:51 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_data *d, int l, int h)
{
	t_point	s;

	s.y = -1;
	while (++(s.y) < d->y_max)
	{
		s.x = 0;
		while (s.x < d->x_max)
		{
			if (s.x + 1 < d->x_max)
			{
				s.x1 = s.x + 1;
				s.y1 = s.y;
				proj(d, s);
				line(d, l, h, (d->m[s.y][s.x] || d->m[s.y][s.x + 1] ? 1 : 0));
			}
			if (s.y + 1 < d->y_max)
			{
				s.x1 = s.x;
				s.y1 = s.y + 1;
				proj(d, s);
				line(d, l, h, (d->m[s.y][s.x] || d->m[s.y + 1][s.x] ? 1 : 0));
			}
			s.x++;
		}
	}
}

void	proj(t_data *d, t_point s)
{
	int	gap;
	int ox;
	int y;
	int oy;
	int z;

	ox = s.x - d->x_max / 2;
	y = s.x1 - d->x_max / 2;
	oy = s.y - d->y_max / 2;
	z = s.y1 - d->y_max / 2;
	gap = d->gap;
	if (d->proj)
	{
		d->p.x = ((ox - oy) * cos(0.523599)) * gap;
		d->p.y = (-(d->m[s.y][s.x] * d->n) + (ox + oy) * sin(0.523599)) * gap;
		d->p.x1 = ((y - z) * cos(0.523599)) * gap;
		d->p.y1 = ((-d->m[s.y1][s.x1] * d->n) + (y + z) * sin(0.523599)) * gap;
	}
	else
	{
		d->p.x = ((ox - d->m[s.y][s.x] * d->n) * cos(0.785398)) * gap;
		d->p.y = ((oy - d->m[s.y][s.x] * d->n) * sin(0.785398)) * gap;
		d->p.x1 = ((y - d->m[s.y1][s.x1] * d->n) * cos(0.785398)) * gap;
		d->p.y1 = ((z - d->m[s.y1][s.x1] * d->n) * sin(0.785398)) * gap;
	}
}

void	line(t_data *d, int l, int h, int z)
{
	t_bre	b;

	b.dx = abs((d->p.x1 + l) - (d->p.x + l));
	b.sx = d->p.x < d->p.x1 ? 1 : -1;
	b.dy = abs((d->p.y1 + h) - (d->p.y + h));
	b.sy = d->p.y < d->p.y1 ? 1 : -1;
	b.err = (b.dx > b.dy ? b.dx : -b.dy) / 2;
	while (1)
	{
		mlx_pixel_put(d->mlx, d->win, d->p.x + l, d->p.y + h, (z ? CO : WH));
		if ((d->p.x == d->p.x1 && d->p.y == d->p.y1) || !is_in_win(d->p, l, h))
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
	if ((p.x + l <= LENGTH && p.x + l >= 0)
			&& (p.y + h <= HEIGHT && p.y + h >= 0))
		return (1);
	if ((p.x1 + l <= LENGTH && p.x1 + l >= 0)
			&& (p.y1 + h <= HEIGHT && p.y1 + h >= 0))
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

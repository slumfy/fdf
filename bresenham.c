/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 04:35:14 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/08 01:51:33 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:14:23 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/09 11:02:59 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_data d;

	if (ac < 2)
		return (write(1, "Usage: fdf [map]\n", 17) == 42);
	if (!(parse_map(av[1], &d)))
		return (write(2, "Error\n", 6) == 42);
	if (!(d.mlx = mlx_init())
			|| !(d.win = mlx_new_window(d.mlx, LENGTH, HEIGHT, av[1])))
		return (write(2, "Error\n", 6) == 42);
	d.img.ptr = mlx_new_image(d.mlx, LENGTH, HEIGHT);
	d.img.s = (int*)mlx_get_data_addr(d.img.ptr, &d.img.b, &d.img.l, &d.img.e);
	draw_map(&d, d.l, d.h);
	mlx_put_image_to_window(d.mlx, d.win, d.img.ptr, 0, 0);
	set_hud(&d);
	mlx_hook(d.win, 2, 0, zoom_proj_alt_mov, &d);
	mlx_hook(d.win, 17, 0, close_button, &d);
	mlx_loop(d.mlx);
	return (0);
}

int		zoom_proj_alt_mov(int key, t_data *data)
{
	if (key == 123 || key == 124)
		data->n += (key == 123 ? 0.2 : -0.2);
	else if (key == 126 || key == 125)
		data->gap += (key == 126 ? 1 : -1);
	else if (key == 35)
		data->proj = (data->proj ? 0 : 1);
	else if (key == 34 || key == 40)
		data->h += (key == 40 ? 10 : -10);
	else if (key == 38 || key == 37)
		data->l += (key == 37 ? 10 : -10);
	else if (key == 31)
		data->color = (data->color == RED ? BLUE : data->color << 8);
	else if (key == 32)
		data->hud = (data->hud ? 0 : 1);
	else if (key == 53)
		exit(0);
	ft_memset(data->img.s, 0, data->img.l * HEIGHT);
	draw_map(data, data->l, data->h);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	set_hud(data);
	return (0);
}

int		close_button(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

int		color(int z, t_data *data)
{
	if (z == 1)
	{
		return (data->color);
	}
	return (0xFFFFFF);
}

void	set_hud(t_data *data)
{
	if (data->hud)
	{
		mlx_string_put(data->mlx, data->win, 10, 10, WHITE,
				"change projection: P");
		mlx_string_put(data->mlx, data->win, 10, 30, WHITE,
				"zoom: arrow up,down");
		mlx_string_put(data->mlx, data->win, 10, 50, WHITE,
				"change altitude: arrow left,right");
		mlx_string_put(data->mlx, data->win, 10, 70, WHITE,
				"move map: J,K,L,I");
		mlx_string_put(data->mlx, data->win, 10, 90, WHITE,
				"change color: O");
		mlx_string_put(data->mlx, data->win, 10, 110, WHITE,
				"SHOW HUD: U");
	}
}

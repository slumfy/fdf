/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:14:23 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/09 07:27:05 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_data d;

	if (ac < 2)
		return (0);
	if (!(parse_map(av[1], &d)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!(d.mlx = mlx_init())
			|| !(d.win = mlx_new_window(d.mlx, LENGTH, HEIGHT, av[1])))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	draw_map(&d, d.l, d.h);
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
	mlx_clear_window(data->mlx, data->win);
	draw_map(data, data->l, data->h);
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
	if (!data->hud)
	{
		mlx_string_put(data->mlx, data->win, 0, 0, WHITE,
				"change projection: P");
		mlx_string_put(data->mlx, data->win, 0, 20, WHITE,
				"zoom: arrow up,down");
		mlx_string_put(data->mlx, data->win, 0, 40, WHITE,
				"change altitude: arrow left,right");
		mlx_string_put(data->mlx, data->win, 0, 60, WHITE,
				"move map: J,K,L,I");
		mlx_string_put(data->mlx, data->win, 0, 80, WHITE,
				"change color: O");
		mlx_string_put(data->mlx, data->win, 0, 100, WHITE,
				"SHOW HUD: U");
	}
}

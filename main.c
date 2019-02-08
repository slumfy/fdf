/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:14:23 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/08 04:56:54 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_data d;

	if (ac < 2)
		return (0);
	if (!(parse_map(av[1], &d)))
		return (0);
	d.gap = LENGTH / (d.x_max * 2);
	d.proj = 1;
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, LENGTH, HEIGHT, av[1]);
	draw_map(&d, LENGTH / 2, HEIGHT / 2);
	mlx_hook(d.win, 2, 0, key_press, &d);
	mlx_hook(d.win, 17, 0, close_button, &d);
	mlx_loop(d.mlx);
	return (0);
}

int		key_press(int key, t_data *data)
{
	if (key == 126 || key == 125)
		zoom(key, data);
	else if (key == 35)
		change_proj(data);
	else if (key == 53)
		exit(0);
	return (0);
}

int		zoom(int key, t_data *data)
{
	if (key == 126)
	{
		data->gap++;
		mlx_clear_window(data->mlx, data->win);
		draw_map(data, LENGTH / 2, HEIGHT / 2);
	}
	else if (key == 125)
	{
		data->gap--;
		mlx_clear_window(data->mlx, data->win);
		draw_map(data, LENGTH / 2, HEIGHT / 2);
	}
	return (0);
}

int		change_proj(t_data *data)
{
	if (data->proj)
	{
		data->proj = 0;
		mlx_clear_window(data->mlx, data->win);
		draw_map(data, LENGTH / 2, HEIGHT / 2);
	}
	else
	{
		data->proj = 1;
		mlx_clear_window(data->mlx, data->win);
		draw_map(data, LENGTH / 2, HEIGHT / 2);
	}
	return (0);
}

int		close_button(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

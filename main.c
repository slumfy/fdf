/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:14:23 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/07 04:41:45 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, t_data *data)
{
	static int node;

	if (key == 35)
	{
		if (node)
		{
			node = 0;
			delete_map(data, 800, 300, 0);
			draw_map(data, 800, 300, 1);
		}
		else
		{
			node = 1;
			delete_map(data, 800, 300, 1);
			draw_map(data, 800, 300, 0);
		}
	}
	if (key == 53)
		exit(0);
	ft_putnbr(key);
	return (0);
}

int		close_button(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_data data;

	if (ac < 2)
		return (0);
	if (!(parse_map(av[1], &data)))
		return (0);
	printf_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, LENGTH, HEIGHT, av[1]);
	draw_map(&data, 800, 300, 1);
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_hook(data.win, 17, 0, close_button, &data);
	mlx_loop(data.mlx);
	return (0);
}

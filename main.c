/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:14:23 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/07 23:09:39 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_data data;

	if (ac < 2)
		return (0);
	if (!(parse_map(av[1], &data)))
		return (0);
	data.gap = LENGTH / (data.x_max * 2);
	data.proj = 1;
	printf_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, LENGTH, HEIGHT, av[1]);
	draw_map(&data, LENGTH / 2, HEIGHT / 2, data.proj);
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_hook(data.win, 17, 0, close_button, &data);
	mlx_loop(data.mlx);
	return (0);
}

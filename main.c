/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:14:23 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/08 00:41:11 by rvalenti         ###   ########.fr       */
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
	draw_map(&d, LENGTH / 2, HEIGHT / 2, d.proj);
	mlx_hook(d.win, 2, 0, key_press, &d);
	mlx_hook(d.win, 17, 0, close_button, &d);
	mlx_loop(d.mlx);
	return (0);
}

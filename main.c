/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:14:23 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/05 05:21:56 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit (0);
	ft_putnbr(key);
	return(0);
}

int	close_button(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_data data;

	if (ac < 2)
		return(0);
	if(!(parse_map(av[1], &data)))
		return (0);
	printf_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, LENGTH, HEIGHT, av[1]);
	draw_map(&data, 0, 0, 100);
	mlx_hook(data.win, 2, 0, key_press, (void *)0);
	mlx_hook(data.win, 17, 0, close_button, (void *)0);
	mlx_loop(data.mlx);
	return(0);
}

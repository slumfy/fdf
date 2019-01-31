/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:14:23 by rvalenti          #+#    #+#             */
/*   Updated: 2019/01/29 16:18:16 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keylog(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit (0);
	ft_putnbr(key);
	return(0);
}


int		main(int ac, char **av)
{
	void *win;
	void *mlx;
	int x;
	int y;

	x = 0;
	y = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, LENGTH, HEIGHT, "mlx");
	while (x <= LENGTH && y <= HEIGHT)
	{
	mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
	x++;
	if (x % 3)
		y++;
	}
	mlx_key_hook(win, keylog, (void *)0);
	mlx_loop(mlx);
	(void)ac;
	(void)av;
	return(0);
}

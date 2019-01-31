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
	t_data data;

	if (ac < 2)
		return(0);
	if(!(parse_map(av[1], &data)))
		return (0);
	printf("xmax=%d\tymax=%d", data.x_max, data.y_max);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, LENGTH, HEIGHT, av[1]);
	mlx_key_hook(data.win, keylog, (void *)0);
	mlx_loop(data.mlx);
	return(0);
}

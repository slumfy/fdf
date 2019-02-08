/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:39:35 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/08 02:43:04 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

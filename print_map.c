/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 01:41:57 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/07 04:51:24 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printf_map(t_data *data)
{
	int		x;
	t_lst	*tmp;
	int		y;

	x = 0;
	y = 0;
	tmp = data->list;
	printf("xmax=%d\tymax=%d\n", data->x_max, data->y_max);
	while (tmp)
	{
		printf("%d\tdata= %s\n", x, tmp->data);
		x++;
		tmp = tmp->next;
	}
	x = 0;
	printf("map: x=%d y= %d\n", data->x_max, data->y_max);
	while (y < data->y_max)
	{
		x = 0;
		printf("\t");
		while (x < data->x_max)
		{
			printf("%d ", data->map[y][x]);
			x++;
		}
		y++;
		printf("\n");
	}
}

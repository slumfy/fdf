/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 01:41:57 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/05 02:58:37 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printf_map(t_data *data)
{
	//int n;
	//int y;
	t_lst *tmp;
	int n = 0;

	tmp = data->list;
	//n = 0;
	//	y = 0;
	printf("xmax=%d\tymax=%d\n", data->x_max, data->y_max);
	while(tmp)
	{
		printf("%d\tdata= %s\n",n,tmp->data);
		n++;
		tmp = tmp->next;
	}
	/*while (n < data->y_max)
	  {
	  printf("n=%d\n", n);
	  while (y < data->x_max)
	  {
	  printf("%d ", data->map[n][y]);
	  y++;
	  }
	  printf("\n");
	  n++;
	  }*/
}

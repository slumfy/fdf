/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 01:33:57 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/05 02:39:56 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parse_map(char *s, t_data *data)
{
	char *line;
	int	fd;
	int i;

	i = 0;
	if((fd = open(s, O_RDONLY)) < 0)
		return(0);
	while (get_next_line(fd, &line) == 1)
	{
		ft_list_pushback(&data->list, line);
		printf("line=%s\n", line);
		data->x_max = ft_countword(line, ' ');
		data->y_max++;
	}
	free(line);
	close(fd);
	if(!(data->map = (int **)malloc(sizeof(int *) * data->y_max)))
		return(0);
	while (i <= data->y_max)
	{
		if(!(data->map[i] = (int *)malloc(sizeof(int) * data->x_max)))
			return(0);
		i++;
	}
	return(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 01:33:57 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/07 23:19:41 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		parse_map(char *s, t_data *data)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	if ((fd = open(s, O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		ft_list_pushback(&data->list, line);
		data->x_max = ft_countword(line, ' ');
		data->y_max++;
	}
	data->y_max--;
	close(fd);
	if (!get_map(data))
		return (0);
	return (1);
}

int		get_map(t_data *data)
{
	int		**tab;
	int		i;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * data->y_max)))
		return (0);
	while (i < data->y_max)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * data->x_max)))
			return (0);
		i++;
	}
	data->map = tab;
	if (!fill_map(data))
		return (0);
	return (1);
}

int		fill_map(t_data *data)
{
	t_lst	*tmp;
	int		i;
	int		x;
	char	**split;

	x = 0;
	tmp = data->list;
	while (tmp)
	{
		i = 0;
		if (!(split = ft_strsplit(tmp->data, ' ')))
			return (0);
		while (i < data->x_max)
		{
			data->map[x][i] = ft_atoi(split[i]);
			i++;
		}
		ft_freetab((void ***)&split);
		x++;
		tmp = tmp->next;
	}
	return (1);
}

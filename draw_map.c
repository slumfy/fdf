#include "fdf.h"

void	draw_map(t_data *data, int larg, int haut)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < data->y_max)
	{
		x = 0;

		while (x < data->x_max)
		{
			if (x + 1 < data->x_max)
			{
				if(!test_iso(data, x ,y, x + 1, y, 40))
					bresenham(data, data->point.x + larg , data->point.y + haut,
							data->point.x1 + larg , data->point.y1 + haut);
				else
					bresenham_blue(data, data->point.x + larg , data->point.y + haut,
							data->point.x1 + larg , data->point.y1 + haut);

			}
			if (y + 1 < data->y_max)
			{
				if(!test_iso(data, x ,y, x, y + 1, 40))
					bresenham(data, data->point.x + larg, data->point.y + haut,
							data->point.x1 + larg, data->point.y1 + haut);
				else
					bresenham_blue(data, data->point.x + larg, data->point.y + haut,
							data->point.x1 + larg, data->point.y1 + haut);

			}
			x++;
		}
		y++;
	}
}

int		iso(t_data *data, int x, int y,int x1, int y1, int gap)
{
	data->point.x = ((x - data->map[y][x] - y) * gap / 2);
	data->point.x1 = ((x1 - data->map[y1][x1] - y1) * gap / 2);
	data->point.y = ((x - data->map[y][x] + y) * gap / 2);
	data->point.y1 = ((x1 - data->map[y1][x1] + y1) * gap / 2);
	if ((data->map[y1][x1] || data->map[y][x])
			&& data->map[y1][x1] == data->map[y][x])
		return (1);
	return(0);
}

int		test_iso(t_data *data, int x, int y,int x1, int y1, int gap)
{
	(void)gap;
	data->point.x = ((x - y) * cos(0.523599)) * gap / 2;
	data->point.y = (-data->map[y][x] + (x + y) * sin(0.523599)) * gap / 2;
	data->point.x1 = ((x1 - y1) * cos(0.523599)) * gap / 2;
	data->point.y1 = (-data->map[y1][x1] + (x1 + y1) * sin(0.523599)) * gap / 2;
	if ((data->map[y1][x1] || data->map[y][x])
			&& data->map[y1][x1] == data->map[y][x])
		return (1);
	return(0);
}

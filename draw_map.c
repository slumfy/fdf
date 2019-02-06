#include "fdf.h"

void	draw_map(t_data *data, int gap)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y <= data->y_max)
	{
		x = 0;
		while (x <= data->x_max)
		{
			if (x + 1 <= data->x_max)
			{
				iso(data, x ,y, gap);
				bresenham(data, (data->point.x + 1) * gap , (data->point.y + 1) * gap , (data->point.x + 2) * gap , (data->point.y + 1) * gap);
			}
			if (y + 1 <= data->y_max)
			{
				iso(data, x ,y, gap);
				bresenham(data, (data->point.x + 1) * gap , (data->point.y + 1) * gap , (data->point.x + 1) * gap , (data->point.y + 2) * gap);
			}
			x++;
		}
		y++;
	}
}

void	iso(t_data *data, int x, int y, int gap)
{
	data->point.x = ((x - y) * gap / 2.);
	data->point.y = ((x + y) * gap / 2.);
}

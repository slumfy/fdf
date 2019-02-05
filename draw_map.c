#include "fdf.h"

void	draw_map(t_data *data, int x, int y, int gap)
{
	if(x + 1 <= data->x_max)
	{
		bresenham(data, x * gap , y * gap , (x + 1) * gap , y * gap);
		draw_map(data, x + 1, y, gap);
	}
	if(y + 1 <= data->y_max)
	{
		bresenham(data, x * gap , y * gap , x * gap , (y + 1) * gap);
		draw_map(data, x, y + 1, gap);
	}
}

#include "fdf.h"

void	draw_map(t_data *data, int x, int y, int gap)
{
	if(x + 1 <= data->x_max)
	{
		bresenham(data, (x + 1) * gap , (y + 1) * gap , (x + 2) * gap , (y + 1) * gap);
		draw_map(data, x + 1, y, gap);
	}
	if(y + 1 <= data->y_max)
	{
		bresenham(data, (x + 1) * gap , (y + 1) * gap , (x + 1) * gap , (y + 2) * gap);
		draw_map(data, x, y + 1, gap);
	}
}

void iso(int *x, int *y, t_data *data)
{
    int p_x;
    int p_y;

    p_x = *x;
    p_y = *y;
    *x = (p_x - p_y) * cos(0.523599);
    *y = -data->map[p_x][p_y] + (p_x + p_y) * sin(0.523599);
}

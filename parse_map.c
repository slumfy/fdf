#include "fdf.h"

int	parse_map(char *s, t_data *data)
{
	char *line;
	int	fd;

	if((fd = open(s, O_RDONLY)) < 0)
		return(0);
	while (get_next_line(fd, &line) == 1)
	{
		data->x_max = ft_countword(line, ' ');
		data->y_max++;
	}
	free(line);
	close(fd);
	return(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:15:30 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/05 04:47:50 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define LENGTH 1080
# define HEIGHT 720

# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
#include "../minilibx_macos/mlx.h"

typedef struct	s_lst
{
	void			*data;
	size_t			len;
	struct s_lst	*next;
}				t_lst;

typedef struct s_data
{
	void 	*win;
	void 	*mlx;
	void 	*img;
	int		x;
	int 	y;
	int		x_max;
	int		y_max;
	t_lst	*list;
	int 	**map;
}		t_data;


int		parse_map(char *s, t_data *data);
int		get_map(t_data *data);
int		fill_map(t_data *data);

int		key_press(int key, void *param);
int		close_button(void *param);
void	bresenham(t_data *data, int x0, int y0, int x1, int y1);
void	draw_map(t_data *data, int x, int y, int gap);
void	iso(int *x, int *y, t_data *data);

void	ft_list_pushback(t_lst **begin_list, char *line);
t_lst  *ft_create_elem(char *data, size_t len);

void	printf_map(t_data *data);
#endif

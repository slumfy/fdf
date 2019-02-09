/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:15:30 by rvalenti          #+#    #+#             */
/*   Updated: 2019/02/08 10:56:56 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define LENGTH 1080
# define HEIGHT 720
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF


# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include "./minilibx_macos/mlx.h"

typedef struct	s_bre
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int	e2;
}				t_bre;

typedef struct	s_point
{
	int		x;
	int		x1;
	int		y;
	int		y1;
}				t_point;

typedef struct	s_lst
{
	void			*data;
	size_t			len;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_data
{
	void	*win;
	void	*mlx;
	void	*img;
	int		x_max;
	int		y_max;
	int		l;
	int		h;
	int		gap;
	int		proj;
	int		color;
	int		hud;
	double	n;
	t_lst	*list;
	int		**m;
	t_point	p;
}				t_data;

int				parse_map(char *s, t_data *data);
int				get_map(t_data *data);
int				fill_map(t_data *data);
void				set_hud(t_data *data);
int				zoom_proj_alt_mov(int key, t_data *data);
int				close_button(t_data *data);
int				is_in_win(t_point p, int l, int h);
void			line(t_data *data, int l, int h, int z);
void			draw_map(t_data *d, int larg, int haut);
void			proj(t_data *d, t_point s);
int			color(int z,t_data *data);
int				is_int(char *str);
void			ft_list_pushback(t_lst **begin_list, char *line);
t_lst			*ft_create_elem(char *data, size_t len);
#endif

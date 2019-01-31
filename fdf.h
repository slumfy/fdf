/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:15:30 by rvalenti          #+#    #+#             */
/*   Updated: 2019/01/29 16:17:40 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define LENGTH 1080
# define HEIGHT 720

typedef struct s_data
{
	void *win;
	void *mlx;
	void *img;
	int	x;
	int 	y;
	int	x_max;
	int	y_max;
}		t_data;

# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
#include "../minilibx_macos/mlx.h"

int	parse_map(char *s, t_data *data);
int	keylog(int key, void *param);

#endif

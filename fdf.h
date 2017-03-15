/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:23:03 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/10 14:23:04 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>

typedef struct		s_coord
{
	float			x;
	float			y;
	float			z;
}					t_coord;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	t_coord			**coord;
	int				scale;
	int				len;
	int				center[2];
}					t_win;

char				*read_file(int fd);
void				draw_map(float **map, char *name, int x, int y);
float				**valid_file(char	*file, int *x, int *y);
void				draw_line(t_win win, float c1[], float c2[], int color);
void				x_rotate(t_coord **coor, float angel, int x);
void				y_rotate(t_coord **coor, float angel, int x);
void				z_rotate(t_coord **coor, float angel, int x);
int					key_event(int keycode, void *param);
void				draw_coord(t_win win);
#endif

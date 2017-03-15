/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:03:16 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/11 19:03:17 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap_arr(float **c1, float **c2)
{
	float	*c3;

	c3 = *c2;
	*c2 = *c1;
	*c1 = c3;
}

void	draw_line(t_win win, float c1[], float c2[], int color)
{
	float dx;
	float dy;
	float x;
	float y;

	if (c1[0] > c2[0])
		swap_arr(&c1, &c2);
	dx = c2[0] - c1[0];
	dy = c2[1] - c1[1];
	x = c1[0];
	while (x <= c2[0])
	{
		y = c1[1] + dy * (x - c1[0]) / dx;
		mlx_pixel_put(win.mlx, win.win, (int)x, (int)y, color);
		x += 0.1;
	}
}

void	x_rotate(t_coord **coor, float angel, int x)
{
	int		i;
	int		j;
	float	y;
	float	z;

	i = -1;
	while (coor[++i] && (j = -1))
		while (++j < x)
		{
			y = coor[i][j].y;
			z = coor[i][j].z;
			coor[i][j].y = y * cosf(angel) + z * sinf(angel);
			coor[i][j].z = -y * sinf(angel) + z * cosf(angel);
		}
}

void	y_rotate(t_coord **coor, float angel, int len)
{
	int		i;
	int		j;
	float	x;
	float	z;

	i = -1;
	while (coor[++i] && (j = -1))
		while (++j < len)
		{
			x = coor[i][j].x;
			z = coor[i][j].z;
			coor[i][j].x = x * cosf(angel) + z * sinf(angel);
			coor[i][j].z = -x * sinf(angel) + z * cosf(angel);
		}
}

void	z_rotate(t_coord **coor, float angel, int len)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = -1;
	while (coor[++i] && (j = -1))
		while (++j < len)
		{
			y = coor[i][j].y;
			x = coor[i][j].x;
			coor[i][j].x = x * cosf(angel) + y * sinf(angel);
			coor[i][j].y = -x * sinf(angel) + y * cosf(angel);
		}
}

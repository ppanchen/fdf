/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:37:15 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/11 15:37:16 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	**fill_coord(float **map, int x, int y)
{
	t_coord		**coor;
	float		mx;
	float		my;
	int			i;
	int			j;

	mx = (float)(x + 1) / 2 - 1;
	my = (float)(y + 1) / 2 - 1;
	coor = (t_coord **)malloc(sizeof(t_coord *) * (y + 1));
	coor[y] = 0;
	i = -1;
	while (++i < y)
		coor[i] = (t_coord *)malloc(sizeof(t_coord) * (x + 1));
	i = -1;
	while (++i < y && (j = -1))
	{
		while (++j < x)
		{
			coor[i][j].x = -(j - mx);
			coor[i][j].y = (my - i);
			coor[i][j].z = -map[i][j];
		}
	}
	return (coor);
}

void	draw_coord3(t_win win, int i, int j)
{
	float	c1[2];
	float	c2[2];

	i = -1;
	while (win.coord[++i + 1])
	{
		c1[0] = (win.coord[i][j].x - (float)0.5 *\
		win.coord[i][j].y) * win.scale + win.center[0];
		c1[1] = ((float)0.5 * win.coord[i][j].y -\
		win.coord[i][j].z) * win.scale + win.center[1];
		c2[0] = (win.coord[i + 1][j].x - (float)0.5 *\
		win.coord[i + 1][j].y) * win.scale + win.center[0];
		c2[1] = ((float)0.5 * win.coord[i + 1][j].y -\
		win.coord[i + 1][j].z) * win.scale + win.center[1];
		draw_line(win, c1, c2, 0xFFFAFA);
	}
}

void	draw_coord2(t_win win, int i, int j)
{
	float	c1[2];
	float	c2[2];

	j = -1;
	while (++j < win.len - 1)
	{
		c1[0] = (win.coord[i][j].x - (float)0.5 *\
		win.coord[i][j].y) * win.scale + win.center[0];
		c1[1] = ((float)0.5 * win.coord[i][j].y -\
		win.coord[i][j].z) * win.scale + win.center[1];
		c2[0] = (win.coord[i][j + 1].x - (float)0.5 *\
		win.coord[i][j + 1].y) * win.scale + win.center[0];
		c2[1] = ((float)0.5 * win.coord[i][j + 1].y -\
		win.coord[i][j + 1].z) * win.scale + win.center[1];
		draw_line(win, c1, c2, 0xFFFAFA);
	}
	draw_coord3(win, i, j);
}

void	draw_coord(t_win win)
{
	int		i;
	int		j;
	float	c1[2];
	float	c2[2];

	i = -1;
	while (win.coord[++i + 1] && (j = -1))
		while (++j < win.len - 1)
		{
			c1[0] = (win.coord[i][j].x - (float)0.5 *\
			win.coord[i][j].y) * win.scale + win.center[0];
			c1[1] = ((float)0.5 * win.coord[i][j].y - \
			win.coord[i][j].z) * win.scale + win.center[1];
			c2[0] = (win.coord[i][j + 1].x - (float)0.5 *\
			win.coord[i][j + 1].y) * win.scale + win.center[0];
			c2[1] = ((float)0.5 * win.coord[i][j + 1].y -\
			win.coord[i][j + 1].z) * win.scale + win.center[1];
			draw_line(win, c1, c2, 0xFFFAFA);
			c2[0] = (win.coord[i + 1][j].x - (float)0.5 *\
			win.coord[i + 1][j].y) * win.scale + win.center[0];
			c2[1] = ((float)0.5 * win.coord[i + 1][j].y -\
			win.coord[i + 1][j].z) * win.scale + win.center[1];
			draw_line(win, c1, c2, 0xFFFAFA);
		}
	draw_coord2(win, i, j);
}

void	draw_map(float **map, char *name, int x, int y)
{
	t_win	*win;
	t_coord	**coord;

	win = (t_win *)malloc(sizeof(t_win));
	coord = fill_coord(map, x, y);
	win->coord = coord;
	win->len = x;
	x_rotate(win->coord, 10, x);
	z_rotate(win->coord, 10, x);
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, 2000, 1000, name);
	win->scale = 10;
	win->center[0] = 1000;
	win->center[1] = 500;
	draw_coord(*win);
	mlx_hook(win->win, 2, 5, key_event, win);
	mlx_loop(win->mlx);
}

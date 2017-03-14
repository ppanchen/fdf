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
	float 		mx;
	float 		my;
	int 		i;
	int 		j;

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
			coor[i][j].y = -(my - i);
			coor[i][j].z = -map[i][j];
		}
	}
	return (coor);
}

void	draw_coord(t_win win, t_coord **coord, int len, int scale)
{
	float 	mx;
	float	my;
	float	x;
	float	y;
	int		i;
	int 	j;
	float 	c1[2];
	float 	c2[2];

	i = -1;
	mx = 1000;
	my = 500;
	while (coord[++i + 1] && (j = -1))
	{
		while (++j < len - 1)
		{
			x = (coord[i][j].x - (float)0.5 * coord[i][j].y) * scale + mx;
			y = ((float)0.5 * coord[i][j].y - coord[i][j].z) * scale + my;
			c1[0] = x;
			c1[1] = y;
			x = (coord[i][j + 1].x - (float)0.5 * coord[i][j + 1].y) * scale + mx;
			y = ((float)0.5 * coord[i][j + 1].y - coord[i][j + 1].z) * scale + my;
			c2[0] = x;
			c2[1] = y;
			draw_line(win, c1, c2, 0xFFFAFA);
			x = (coord[i + 1][j].x - (float)0.5 * coord[i + 1][j].y) * scale + mx;
			y = ((float)0.5 * coord[i + 1][j].y - coord[i + 1][j].z) * scale + my;
			c2[0] = x;
			c2[1] = y;
			draw_line(win, c1, c2, 0xFFFAFA);
		}
	}
	j = -1;
	while (++j < len - 1)
	{
		x = (coord[i][j].x - (float)0.5 * coord[i][j].y) * scale + mx;
		y = ((float)0.5 * coord[i][j].y - coord[i][j].z) * scale + my;
		c1[0] = x;
		c1[1] = y;
		x = (coord[i][j + 1].x - (float)0.5 * coord[i][j + 1].y) * scale + mx;
		y = ((float)0.5 * coord[i][j + 1].y - coord[i][j + 1].z) * scale + my;
		c2[0] = x;
		c2[1] = y;
		draw_line(win, c1, c2, 0xFFFAFA);
	}
	i = -1;
	while (coord[++i + 1])
	{
		x = (coord[i][j].x - (float)0.5 * coord[i][j].y) * scale + mx;
		y = ((float)0.5 * coord[i][j].y - coord[i][j].z) * scale + my;
		c1[0] = x;
		c1[1] = y;
		x = (coord[i + 1][j].x - (float)0.5 * coord[i + 1][j].y) * scale + mx;
		y = ((float)0.5 * coord[i + 1][j].y - coord[i + 1][j].z) * scale + my;
		c2[0] = x;
		c2[1] = y;
		draw_line(win, c1, c2, 0xFFFAFA);
	}
}

int 	key_event(int keycode, void *param)
{
	t_win *win = (t_win *)param;
	if (keycode == 53)
		exit (0);
	if (keycode == 89)
	{
		x_rotate(win->coord, 0.1, win->len);
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win, win->coord, win->len, win->scale);
	}
	if (keycode == 86)
	{
		x_rotate(win->coord, -0.1, win->len);
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win, win->coord, win->len, win->scale);
	}
	if (keycode == 91)
	{
		y_rotate(win->coord, 0.1, win->len);
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win, win->coord, win->len, win->scale);
	}
	if (keycode == 87)
	{
		y_rotate(win->coord, -0.1, win->len);
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win, win->coord, win->len, win->scale);
	}
	if (keycode == 92)
	{
		z_rotate(win->coord, 0.1, win->len);
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win, win->coord, win->len, win->scale);
	}
	if (keycode == 88)
	{
		z_rotate(win->coord, -0.1, win->len);
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win, win->coord, win->len, win->scale);
	}
	if (keycode == 24)
	{
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win, win->coord, win->len, win->scale++);
	}
	if (keycode == 27)
	{
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win, win->coord, win->len, win->scale--);
	}
	ft_printf("keycode is: %03d\n", keycode);
	return (keycode);
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
	win->scale = 100;
	draw_coord(*win, coord, x, win->scale);
	mlx_key_hook(win->win, key_event, win);
	mlx_mouse_hook(win->win, key_event, win);
	mlx_loop(win->mlx);
	// TODO drawing;
}

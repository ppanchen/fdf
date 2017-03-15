/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:11:55 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/12 14:11:56 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_event4(int keycode, t_win *win)
{
	if (keycode == 125)
	{
		mlx_clear_window(win->mlx, win->win);
		win->center[1] += 10;
		draw_coord(*win);
	}
	if (keycode == 126)
	{
		mlx_clear_window(win->mlx, win->win);
		win->center[1] -= 10;
		draw_coord(*win);
	}
	if (keycode == 15)
	{
		mlx_clear_window(win->mlx, win->win);
		win->color = 0xFF0000;
		draw_coord(*win);
	}
	if (keycode == 5)
	{
		mlx_clear_window(win->mlx, win->win);
		win->color = 0x00FF00;
		draw_coord(*win);
	}
}

void	key_event3(int keycode, t_win *win)
{
	if (keycode == 27)
	{
		mlx_clear_window(win->mlx, win->win);
		win->scale -= 2;
		draw_coord(*win);
	}
	if (keycode == 124)
	{
		mlx_clear_window(win->mlx, win->win);
		win->center[0] += 10;
		draw_coord(*win);
	}
	if (keycode == 123)
	{
		mlx_clear_window(win->mlx, win->win);
		win->center[0] -= 10;
		draw_coord(*win);
	}
	if (keycode == 11)
	{
		mlx_clear_window(win->mlx, win->win);
		win->color = 0x00FFFF;
		draw_coord(*win);
	}
	key_event4(keycode, win);
}

void	key_event2(int keycode, t_win *win)
{
	if (keycode == 87)
	{
		y_rotate(win->coord, -0.1, win->len);
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win);
	}
	if (keycode == 92)
	{
		z_rotate(win->coord, 0.1, win->len);
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win);
	}
	if (keycode == 88)
	{
		z_rotate(win->coord, -0.1, win->len);
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win);
	}
	if (keycode == 24)
	{
		mlx_clear_window(win->mlx, win->win);
		win->scale += 2;
		draw_coord(*win);
	}
	key_event3(keycode, win);
}

int		key_event(int keycode, void *param)
{
	t_win *win;

	win = (t_win *)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 89)
	{
		x_rotate(win->coord, 0.1, win->len);
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win);
	}
	if (keycode == 86)
	{
		x_rotate(win->coord, -0.1, win->len);
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win);
	}
	if (keycode == 91)
	{
		y_rotate(win->coord, 0.1, win->len);
		mlx_clear_window(win->mlx, win->win);
		draw_coord(*win);
	}
	key_event2(keycode, win);
	return (0);
}

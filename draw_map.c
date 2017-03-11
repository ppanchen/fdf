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

int 	key_event(int keycode, void *param)
{
	if (keycode == 53)
		exit (0);
	ft_printf("keycode is: %03d\n", keycode);
	return (keycode);
}

void	draw_map(int **map, char *name)
{
	t_win	win;
	int 	coord1[2];
	int 	coord2[2];


	coord1[0] = 10;
	coord1[1] = 10;

	coord2[0] = 1000;
	coord2[1] = 1200;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 2000, 1000, name);
	draw_line(win, coord1, coord2, 100);
	draw_line(win, coord1, coord2, 100);

	mlx_key_hook(win.win, key_event, 0);
	mlx_mouse_hook(win.win, key_event, 0);
	mlx_loop(win.mlx);
	// TODO drawing;
}

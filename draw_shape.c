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

void	draw_line(t_win win, int c1[], int c2[], int color)
{
	int x1;
	int y1;
	int x2;
	int y2;

	x1 = c1[0];
	y1 = c1[1];
	x2 = c2[0];
	y2 = c2[1];

	while (x1 <= x2 && y1 <= y2)
	{
		mlx_pixel_put(win.mlx, win.win, x1, y1, color);
		x1++;
		y1++;
	}
}

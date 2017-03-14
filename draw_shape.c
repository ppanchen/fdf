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
	float  *c3;
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

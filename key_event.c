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

void	x_rotate(t_coord **coor, float angel, int x)
{
	int i;
	int j;
	float y;
	float z;

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
	int i;
	int j;
	float x;
	float z;

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
	int i;
	int j;
	float x;
	float y;

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
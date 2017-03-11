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

typedef struct	s_win
{
	void		*mlx;
	void		*win;
}				t_win;

char	*read_file(int fd);
void	draw_map(int **map, char *name);
int 	**valid_file(char	*file);
void	draw_line(t_win win, int c1[], int c2[], int color);

#endif
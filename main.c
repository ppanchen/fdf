/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:18:55 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/10 14:18:56 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		valid_file_name(char *filename)
{
	int		i;
	char	**part;
	int		r;

	part = ft_strsplit(filename, '.');
	i = 0;
	while (part[i])
		i++;
	i--;
	if (ft_strcmp(part[i], "fdf") == 0)
		r = 1;
	else
		r = 0;
	ft_arrdel(&part);
	return (r);
}

int		main(int ac, char *av[])
{
	char	*file;
	float	**map;
	int		x;
	int		y;

	if (ac != 2)
		return (0);
	if (!valid_file_name(av[1]))
	{
		printf("File name have to match next pattern: *.fdf\n");
		return (0);
	}
	file = read_file(open(av[1], O_RDONLY));
	ft_printf("%s", file);
	if ((map = valid_file(file, &x, &y)) != 0)
		draw_map(map, av[1], x, y);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:16:08 by ppanchen          #+#    #+#             */
/*   Updated: 2017/03/11 15:16:09 by ppanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_file(int fd)
{
	char	*file;
	char	*tmp;
	char	*n;

	if (fd == -1)
	{
		perror("");
		exit(0);
	}
	file = ft_strdup("");
	while (get_next_line(fd, &tmp))
	{
		n = ft_strdup("\n");
		file = ft_strjoin_free_multy(3, &file, &tmp, &n);
	}
	if (!file || !*file)
	{
		ft_printf("Empty file\n");
		ft_strdel(&file);
		exit(0);
	}
	return (file);
}

float	**mem_map(int x, int y)
{
	float	**map;
	int		i;

	map = (float **)malloc(sizeof(float *) * (y + 1));
	map[y] = 0;
	i = -1;
	while (++i < y)
		map[i] = (float *)malloc(sizeof(float) * x);
	return (map);
}

float	**creat_map(char **chmap, int y, int x)
{
	float	**map;
	char	**str;
	int		i;
	int		j;
	int		r;

	map = mem_map(x, y);
	i = -1;
	r = 1;
	while (chmap[++i] && (j = -1))
	{
		str = ft_strsplit(chmap[i], ' ');
		while (str[++j])
		{
			if ((int)ft_strlen(str[j]) != (str[j][0] == '+' ||
												str[j][0] == '-' ?
				ft_numlen(ft_atoi(str[j])) + 1 : ft_numlen(ft_atoi(str[j]))))
				r = 0;
			map[i][j] = ft_atoi(str[j]);
		}
		ft_arrdel(&str);
	}
	if (r == 0)
		ft_arrmemdel((void ***)&map);
	return (map);
}

int		valid_rect(char **chmap)
{
	int		r;
	int		i;
	char	**onestr;
	int		size;

	i = 0;
	r = 1;
	onestr = ft_strsplit(chmap[0], ' ');
	size = ft_count_items((void **)onestr);
	ft_arrdel(&onestr);
	while (chmap[++i])
	{
		onestr = ft_strsplit(chmap[i], ' ');
		if (ft_count_items((void **)onestr) != size)
			r = 0;
		ft_arrdel(&onestr);
	}
	return (r == 0 ? r : size);
}

float	**valid_file(char *file, int *x, int *y)
{
	char	**chmap;
	float	**map;
	int		size;

	size = -1;
	while (file[++size])
		if (ft_isdigit(file[size]) == 0 && file[size] != '-'
			&& file[size] != '+' && file[size] != ' ' && file[size] != '\n')
			return (0);
	chmap = ft_strsplit(file, '\n');
	*y = ft_count_items((void *)chmap);
	if ((*x = valid_rect(chmap)) != 0)
		map = creat_map(chmap, *y, *x);
	else
		map = 0;
	ft_arrdel(&chmap);
	return (map);
}

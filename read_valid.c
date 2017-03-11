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
	char 	*tmp;
	char 	*n;

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

int 	**creat_map(char **chmap, int y, int x)
{
	int		**map;
	char 	**str;
	int 	i;
	int 	j;
	int 	r;

	map = (int **)malloc(sizeof(int *) * (y + 1));
	map[y] = 0;
	i = -1;
	while (++i < y)
		map[i] = (int *)malloc(sizeof(int) * x);
	i = -1;
	r = 1;
	while (chmap[++i] && (j = -1))
	{
		str = ft_strsplit(chmap[i], ' ');
		while (str[++j])
		{
			if (ft_strlen(str[j]) != (str[j][0] == '+' || str[j][0] == '-'?
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

int 	valid_rect(char **chmap)
{
	int		r;
	int 	i;
	char	**onestr;
	int 	size;

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

int 	**valid_file(char	*file)
{
	char 	**chmap;
	int 	**map;
	int		size;

	size = -1;
	while (file[++size])
		if (ft_isdigit(file[size]) == 0 && file[size] != '-'
			&& file[size] != '+' && file[size] != ' ' && file[size] != '\n')
			return (0);
	chmap = ft_strsplit(file, '\n');
	if ((size = valid_rect(chmap)) != 0)
		map = creat_map(chmap, ft_count_items((void *)chmap), size);
	else
		map = 0;
	ft_arrdel(&chmap);
	int i = -1;
	while (map[++i])
	{
		int j = -1;
		while (++j < size)
			ft_printf("%3d ", map[i][j]);
		ft_printf("\n");
	}
	return (map);
}
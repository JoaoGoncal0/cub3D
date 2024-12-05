/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomendes <jomendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:05:50 by jomendes          #+#    #+#             */
/*   Updated: 2024/12/05 16:30:11 by jomendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_width(t_map *map)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = 0;
	j = 0;
	while (map->matrix[i])
	{
		j = 0;
		while (map->matrix[i][j] != '\0')
			j++;
		if (width < j)
			width = j;
		i++;
	}
	map->x = width - 1;
}

char	*create_top_bottom(t_map *map)
{
	int		i;
	char	*str;
	
	i = 0;
	str = malloc(map->x + 2);
	if (!str)
		return (NULL);
	while (i <= map->x)
	{
		str[i] = 'w';
		i++;
	}
	str[i] = 'w';
	str[i + 1] = '\n';
	str[i + 2] = '\0';
	return (str);
}

void	second_map(t_map *map)
{
	int	y;
	int x;
	
	y = 0;
	map->matrix_ff = malloc((map->y + 3) * sizeof(char *));
	if (!map->matrix_ff)
		return ;
	map->matrix_ff[y++] = create_top_bottom(map);
	while (y <= map->y)
	{
		map->matrix_ff[y] = malloc(map->x + 2);
		if (!map->matrix_ff[y])
			return ;
		x = 0;
		map->matrix_ff[y][x] = 'w';
		while (x <= map->x)
		{
			while (map->matrix[y - 1][x] == ' ')
			{
				map->matrix_ff[y][x + 1] = 'w';
				x++;
			}
			map->matrix_ff[y][x + 1] = map->matrix[y - 1][x];
			x++;
		}
		x = ft_strlen(map->matrix_ff[y]) - 1;
		if (y == map->y)
			x++;
		while(x <= map->x + 1)
		{
			map->matrix_ff[y][x] = 'w';
			x++;
		}
		map->matrix_ff[y][x] = '\n';
		map->matrix_ff[y][x + 1] = '\0';
		y++;
	}
	map->matrix_ff[map->y + 1] = create_top_bottom(map);
	map->matrix_ff[map->y + 2] = NULL;
}

int	check_map_x(t_map *map, int y)
{
	int	x;

	x = 0;
	while (map->matrix_ff[y][x])
	{
		if (!(map->matrix_ff[y][x] == 'w' || map->matrix_ff[y][x] == '1'
		|| (map->matrix_ff[y][x] == '\n')))
			return (1);	
		x++;
	}
	return (0);
}

int	check_map_y(t_map *map)
{
	int	y;
	int	x;
	
	y = 2;
	x = 0;
	while (map->matrix_ff[y][x] && y < map->y)
	{
		x = 0;
		while (map->matrix_ff[y][x] == 'w')
			x++;
		if (map->matrix_ff[y][x] != '1')
			return (1);
		while (map->matrix_ff[y][x] != 'w')
			x++;
		if (map->matrix_ff[y][x - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	check_0(t_map *map)
{
	int	x;
	int	y;

	y = 2;
	while (map->matrix_ff[y] && y < map->y)
	{
		x = 0;
		while (map->matrix_ff[y][x])
		{
			if (map->matrix_ff[y][x] == '0')
			{
				if (map->matrix_ff[y + 1][x] == 'w'
				|| map->matrix_ff[y - 1][x] == 'w')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map(t_map *map)
{
	if (!map->matrix_ff)
		return (1);
	if (check_map_x(map, 1) == 0 && check_map_x(map, map->y) == 0
	&& check_map_y(map) == 0 && check_0(map) == 0)
		return (0);
	return (1);
}
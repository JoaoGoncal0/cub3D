/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:49:23 by jomendes          #+#    #+#             */
/*   Updated: 2024/12/03 02:32:28 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_color(char c)
{
	if (c == '0')
		return (0x00FF00);
	if (c == '1')
		return (0xFFFFFF);
	if (c == 'P')
		return (0xFFFF00);
	return (0x00FF00);
}

void 
	draw_rectangle(t_vc *vc, int h, int w, int color)
{
	int		i;
	int		j;

	h = h * 6;
	w = w * 6;
	while (i < w)
	{
		j = h / 6;
		while (j < h)
		{
			mlx_pixel_put(vc->mlx.mlx, vc->mlx.window, i, j, color);
			j++;
		}
		i++;
	}
}

void	get_pos(t_vc *vc, int x, int y)
{
	vc->map.x = x;
	vc->map.y = y;
}

void	drawminimap(t_vc *vc)
{
	int	i;
	int	j;
	int	color;

	color = 0;
	i = 0;
	while (vc->map.matrix[i])
	{
		j = 0;
		while (vc->map.matrix[i][j])
		{
			color = get_color(vc->map.matrix[i][j]);
			get_pos(vc, i, j);
			draw_rectangle(vc, vc->map.x, vc->map.y, color);
			j++;
		}
		i++;
	}
}

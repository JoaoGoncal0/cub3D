/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:49:19 by jomendes          #+#    #+#             */
/*   Updated: 2024/12/02 17:12:11 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	closegame(t_vc *vc)
{
	free(vc);
	exit(0);
}

void	init()
{
	t_vc		vc;
	t_mlx		mlx;
	t_play		play;

	mlx.mlx = NULL;
	mlx.window = NULL;
	mlx.x = 3840;
	mlx.y = 1990;
	play.x = 0;
	play.y = 0;
	vc.mlx = mlx;
	vc.play = play;
	vc.mlx.mlx = mlx_init();
	vc.mlx.window = mlx_new_window(vc.mlx.mlx, vc.mlx.x, vc.mlx.y, "cub3D");
	mlx_hook(vc.mlx.window, 17, 1L << 17, closegame, &vc);
	drawminimap(&vc);
	mlx_loop(vc.mlx.mlx);
}

int main(int ac, char **av)
{
	if (ac == 2)
		init();
	return (0);
}

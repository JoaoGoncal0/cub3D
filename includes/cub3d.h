/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:43:22 by dinda-si          #+#    #+#             */
/*   Updated: 2024/12/02 16:09:10 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include "../minilibx-linux/mlx.h"

typedef struct	s_mlx
{
	void			*window;
	int				x;
	int				y;
	void			*mlx;
}	t_mlx;

typedef struct s_player
{
	int				x;
	int				y;
}	t_play;


typedef struct s_voidcollector
{
	t_mlx			mlx;
	t_play			play;
}	t_vc;


#endif
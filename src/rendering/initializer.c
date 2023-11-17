/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 05:29:24 by ylarhris          #+#    #+#             */
/*   Updated: 2023/11/17 03:58:15 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_mlx    *mlx_initializer(void)
{
    t_mlx *mlx;
	size_t j;
	
	mlx = (t_mlx *) malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
    return (mlx);
}

void    initplayer(t_data *data)
{
    data->player.x *= TILE_SIZE ;
    data->player.y *= TILE_SIZE ;
    data->player.turndirection = 0;
    data->player.walkdirection = 0;
	data->player.straff_direction = 0;
    data->player.movespeed = 2.5;
    data->player.rotationspeed = 1.5 * (PI / 180);
    data->player.to_do = 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 05:29:24 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/22 12:24:35 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_mlx    *mlx_initializer(void)
{
    t_mlx *mlx;
	
	mlx = (t_mlx *) malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_HEIGHT, WIN_WIDTH, WIN_NAME);
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIN_HEIGHT, WIN_WIDTH);
	mlx_loop(mlx->mlx_ptr);
    return (mlx);
}
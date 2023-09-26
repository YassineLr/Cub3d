/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 05:29:24 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/23 22:55:10 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_mlx    *mlx_initializer(void)
{
    t_mlx *mlx;
	size_t j;
	
	mlx = (t_mlx *) malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_HEIGHT, WIN_WIDTH, WIN_NAME);
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIN_HEIGHT, WIN_WIDTH);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	// for (size_t i = 0; i < WIN_HEIGHT; i++)
	// {
	// 	for (j = 0; j < WIN_WIDTH / 2; j++)
	// 	{
	// 		mlx_pixel_put(mlx->mlx_ptr, mlx->win,i, j, 0x0000FFFF/(j+1));
	// 		mlx_pixel_put(mlx->mlx_ptr, mlx->win,i, j, 0x00ABCFFF/(j+1));
	// 		// mlx_pixel_put(mlx->mlx_ptr, mlx->win,i, (WIN_WIDTH / 2) - j, 0x0000FFFF/j);
	// 	}
	// }
	// for (size_t i = 0; i < WIN_HEIGHT; i++)
	// {
	// 	for (j = WIN_WIDTH; j > 0; j--)
	// 	{
	// 		mlx_pixel_put(mlx->mlx_ptr, mlx->win,i, j, 0x0000FFFF/(j+1));
	// 		mlx_pixel_put(mlx->mlx_ptr, mlx->win,i, j, 0x00ABCFFF/(j+1));
	// 		// mlx_pixel_put(mlx->mlx_ptr, mlx->win,i, (WIN_WIDTH / 2) - j, 0x0000FFFF/j);
	// 	}
	// }
	
    return (mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 05:29:24 by ylarhris          #+#    #+#             */
/*   Updated: 2023/10/19 00:38:27 by ylarhris         ###   ########.fr       */
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

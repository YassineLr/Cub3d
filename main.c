/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 03:26:36 by yismaail          #+#    #+#             */
/*   Updated: 2023/11/24 22:39:01 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	quit(t_data *data)
{
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	init_game(&data, ac, av);
	initplayer(&data);
	mlx_loop_hook(data.mlx->mlx_ptr, render2dmap, &data);
	mlx_hook(data.mlx->win, 02, (1L << 0), keypressed, &data);
	mlx_hook(data.mlx->win, 03, (1L << 1), keyreleased, &data);
	mlx_hook(data.mlx->win, 17, 0, &quit, &data);
	mlx_loop(data.mlx->mlx_ptr);
}

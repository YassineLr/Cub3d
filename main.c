/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 03:26:36 by yismaail          #+#    #+#             */
/*   Updated: 2023/09/29 04:36:57 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main (int ac, char **av)
{
	t_data	data;
	init_game(&data, ac, av);
	render2dmap(&data);
	// run_game(data);
	
	mlx_key_hook(data.mlx->win, keypressed, &data.mlx);
	mlx_loop(data.mlx->mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2dmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:48:58 by ylarhris          #+#    #+#             */
/*   Updated: 2023/11/20 23:31:00 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	has_wall_at(t_data *data, float x, float y)
{
	int	x_index;
	int	y_index;

	if (x < 0 || x > data->map_w * TILE_SIZE
		|| y < 0 || y > data->map_h * TILE_SIZE)
		return (1);
	x_index = x / TILE_SIZE;
	y_index = y / TILE_SIZE;
	if (data->map[y_index] && data->map[y_index] + x_index)
		if (ft_strncmp(data->map[y_index] + x_index, "1", 1))
			return (0);
	return (1);
}

void	playermovement(t_data *data)
{
	float	movestep;
	float	new_x;
	float	new_y;
	float	straff;

	movestep = data->player.walkdirection * data->player.movespeed;
	data->player.ang += data->player.turndirection * data->player.rotationspeed;
	data->player.ang = angles_normalizer(data->player.ang);
	straff = data->player.straff_direction * data->player.movespeed;
	new_x = data->player.x + cos (data->player.ang) * movestep;
	new_y = data->player.y + sin (data->player.ang) * movestep;
	new_x += cos(data->player.ang + M_PI_2) * straff;
	new_y += sin(data->player.ang + M_PI_2) * straff;
	if (!has_wall_at(data, new_x, new_y)
		&& !has_wall_at(data, new_x +2, new_y +2)
		&& !has_wall_at(data, new_x -2, new_y -2)
		&& !has_wall_at(data, new_x -2, new_y +2)
		&& !has_wall_at(data, new_x +2, new_y -2))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	draw_wall(t_data *data, int i, int j)
{
	int	color;
	int	distance_from_top;
	int	choice;

	distance_from_top = j + (data->player.rays[i].wall_strip_height / 2) \
	- (WIN_HEIGHT / 2);
	data->player.rays[i].offset_y = distance_from_top * \
	((double)data->textures.height / data->player.rays[i].wall_strip_height);
	choice = choose_texture(&data->player.rays[i], \
	data->player.rays[i].ray_angle);
	color = get_texture_pixel_color(data->player.rays[i].offset_x \
	, data->player.rays[i].offset_y, data, choice);
	my_mlx_pixel_put(data->mlx, i, j, color);
}

void	rendring(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT)
		{
			if (j >= data->player.rays[i].wall_cordinate.top && j <= \
			data->player.rays[i].wall_cordinate.bottom)
				draw_wall(data, i, j);
			else if (j < data->player.rays[i].wall_cordinate.bottom)
				my_mlx_pixel_put(data->mlx, i, j, data->colors.celling);
			else
				my_mlx_pixel_put(data->mlx, i, j, data->colors.floor);
			j++;
		}
		i++;
	}
	free(data->player.rays);
}

int	render2dmap(t_data *data)
{
	data->mlx->img = mlx_new_image(data->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, \
	&data->mlx->bits_per_pixel, &data->mlx->line_length, &data->mlx->endian);
	playermovement(data);
	cast_all_rays(data);
	rays_parameters(data);
	rendring(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, \
	data->mlx->img, 0, 0);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->img);
	return (1);
}

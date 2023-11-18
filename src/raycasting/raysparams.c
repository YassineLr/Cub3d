/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raysparams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:23:44 by ylarhris          #+#    #+#             */
/*   Updated: 2023/11/18 22:35:25 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_wall_coordinate(t_data *data, int i)
{
	double	correct_wall_distance;

	correct_wall_distance = data->player.rays[i].distance * \
	cos(data->player.rays[i].ray_angle - data->player.ang);
	data->player.rays[i].distance = data->player.rays[i].distance * \
	cos(FOV / 2);
	data->player.rays[i].distance_pojection_plane = (WIN_WIDTH / 2) / \
		tan(FOV / 2);
	data->player.rays[i].wall_strip_height = (TILE_SIZE / correct_wall_distance \
	* data->player.rays[i].distance_pojection_plane);
	data->player.rays[i].wall_cordinate.top = (WIN_HEIGHT / 2) - \
	(data->player.rays[i].wall_strip_height / 2);
	if (data->player.rays[i].wall_cordinate.top < 0)
		data->player.rays[i].wall_cordinate.top = 0;
	data->player.rays[i].wall_cordinate.bottom = \
	data->player.rays[i].wall_cordinate.top + \
	data->player.rays[i].wall_strip_height;
	if (data->player.rays[i].wall_cordinate.bottom > WIN_HEIGHT)
		data->player.rays[i].wall_cordinate.bottom = WIN_HEIGHT;
}

void	rays_parameters(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		calculate_wall_coordinate(data, i);
		if (!data->player.rays[i].player_hit_vertical_wall)
			data->player.rays[i].offset_x = \
			(int)data->player.rays[i].wall_hit_y % TILE_SIZE;
		else
			data->player.rays[i].offset_x = \
			(int)data->player.rays[i].wall_hit_x % TILE_SIZE;
		i++;
	}
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void	distance_to_wall(t_ray *ray, t_data *data)
{
	double	horz_distance;
	double	vert_distance;

	horz_distance = distance_between_points(data->player.x, data->player.y, \
	ray->x_intercept_h, ray->y_intercept_h);
	vert_distance = distance_between_points(data->player.x, data->player.y, \
	ray->x_intercept_v, ray->y_intercept_v);
	if (horz_distance > vert_distance)
	{
		ray->player_hit_vertical_wall = 0;
		ray->wall_hit_x = ray->x_intercept_v ;
		ray->wall_hit_y = ray->y_intercept_v;
		ray->distance = vert_distance;
	}
	else
	{
		ray->player_hit_vertical_wall = 1;
		ray->wall_hit_x = ray->x_intercept_h;
		ray->wall_hit_y = ray->y_intercept_h;
		ray->distance = horz_distance;
	}
}

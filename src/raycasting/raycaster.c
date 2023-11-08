/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:11:16 by ylarhris          #+#    #+#             */
/*   Updated: 2023/11/08 01:28:44 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    cast_all_rays(t_data *data)
{
    float   ray_angle;
    int     i;
    
    i = 0;
    data->player.rays = (t_ray *) malloc(NUM_RAYS * sizeof(t_ray));
    ray_angle = angles_normalizer(data->player.ang - (FOV/2));
    while (i < NUM_RAYS)
    {
        data->player.rays[i].ray_angle = angles_normalizer(ray_angle);
        cast_ray(&data->player.rays[i], data);
        ray_angle += FOV / NUM_RAYS;
        i++;
    }
}

void cast_ray(t_ray *ray, t_data *data)
{
    x_intersections(ray, data);
    y_intersections(ray, data);
    distance_to_wall(ray, data);
    // plotLine(data,data->player.x, data->player.y, ray->wall_hit_x, ray->wall_hit_y, 0x00FF00);    
}


void x_intersections(t_ray *ray, t_data *data)
{
    double arc_tan = -1/tan(ray->ray_angle);
    
    if(ray->ray_angle > M_PI)
    {
        ray->y_intercept_h = (int)(data->player.y / TILE_SIZE) * TILE_SIZE  - 0.001; 
        ray->x_intercept_h = (data->player.y - ray->y_intercept_h) * arc_tan + data->player.x;
        ray->y_step_h = -TILE_SIZE;
    }
    else if(ray->ray_angle < M_PI)
    {
        ray->y_intercept_h = (int)(data->player.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE; 
        ray->x_intercept_h = (data->player.y - ray->y_intercept_h) * arc_tan + data->player.x;
        ray->y_step_h = TILE_SIZE;
    }
    else if (ray->ray_angle == 0 || ray->ray_angle == M_PI)
    {
        ray->y_intercept_h = data->player.y;
        ray->x_intercept_h = data->player.x;
    }
    ray->x_step_h = -ray->y_step_h * arc_tan;
    while (ray->x_intercept_h >= 0 &&  ray->x_intercept_h <= WIN_WIDTH * TILE_SIZE && ray->y_intercept_h >= 0 && ray->y_intercept_h <= WIN_HEIGHT * TILE_SIZE)
    {
        if(has_wall_at(data ,ray->x_intercept_h , ray->y_intercept_h))
            break ;
        else
        {
            ray->x_intercept_h += ray->x_step_h;
            ray->y_intercept_h += ray->y_step_h;
        }
    }
    ray->player_hit_horizontal_wall = 0;
}

void    y_intersections(t_ray *ray, t_data *data)
{
    double arc_tan = -tan(ray->ray_angle);
    
    if(ray->ray_angle > M_PI/2 && ray->ray_angle < 3 * M_PI/2)
    {
        ray->x_intercept_v = (int)(data->player.x / TILE_SIZE) * TILE_SIZE - 0.001; 
        ray->y_intercept_v = (data->player.x - ray->x_intercept_v)*arc_tan +data->player.y;
        ray->x_step_v = -TILE_SIZE;
    }
    else if(ray->ray_angle < M_PI/2 || ray->ray_angle > 3 * M_PI/2)
    {
        ray->x_intercept_v = (int)(data->player.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE; 
        ray->y_intercept_v = (data->player.x - ray->x_intercept_v) * arc_tan + data->player.y;
        ray->x_step_v = TILE_SIZE;
    }
    else if (ray->ray_angle == M_PI/2 || ray->ray_angle == 3 * M_PI/2)
    {
        ray->x_intercept_v = data->player.x;
        ray->y_intercept_v = data->player.y;
    }
    ray->y_step_v = -ray->x_step_v * arc_tan;
    while (ray->x_intercept_v >= 0 &&  ray->x_intercept_v <= WIN_WIDTH *TILE_SIZE && ray->y_intercept_v >= 0 && ray->y_intercept_v <= WIN_HEIGHT * TILE_SIZE)
    {
        if(has_wall_at(data ,ray->x_intercept_v, ray->y_intercept_v))
            break ;
        else
        {
            ray->x_intercept_v += ray->x_step_v;
            ray->y_intercept_v += ray->y_step_v;
        }
    }
    ray->player_hit_vertical_wall = 0;
 }

double distance_between_points(double x1, double y1, double x2, double y2)
{
    return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void    distance_to_wall(t_ray *ray, t_data *data)  
{
    double horz_distance;
    double vert_distance;

    horz_distance = distance_between_points(data->player.x, data->player.y, ray->x_intercept_h, ray->y_intercept_h);
    vert_distance = distance_between_points(data->player.x, data->player.y, ray->x_intercept_v, ray->y_intercept_v);
    if (horz_distance > vert_distance)
    {
        ray->player_hit_horizontal_wall = 1;
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

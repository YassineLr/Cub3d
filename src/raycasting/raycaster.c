/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:11:16 by ylarhris          #+#    #+#             */
/*   Updated: 2023/10/19 00:44:23 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    cast_all_rays(t_data *data)
{
    int     rays_counter;
    float   ray_angle;
    int     i;
    
    i = 0;
    data->player.rays = (t_ray *) malloc(NUM_RAYS * sizeof(t_ray));
    rays_counter = 0;
    ray_angle = angles_normalizer(data->player.ang - (FOV/2));
    while (i < NUM_RAYS)
    {
        data->player.rays[i].ray_angle = angles_normalizer(ray_angle);
        cast_ray(&data->player.rays[i], data);
        ray_angle += FOV / NUM_RAYS;
        i++;
    }
}

// void render_rays(t_data *data)
// {
//     int i;

//     i = 0;
//     while (i < NUM_RAYS)
//     {
//         plotLine(data,data->player.x, data->player.y, data->player.rays[i].wall_hit_x, data->player.rays[i].wall_hit_y, 0x00FF00);
//         i++;
//     }
// }

// int     ray_direction(t_ray *ray)
// {
//     ray->is_ray_facing_up = (ray->ray_angle > 0 && ray->ray_angle < PI);
//     ray->is_ray_facing_down = !ray->is_ray_facing_up;
//     ray->is_ray_facing_right = (ray->ray_angle < (PI/2) && ray->ray_angle > 1.5 * PI);
//     ray->is_ray_facing_left = !ray->is_ray_facing_right;
// }

void cast_ray(t_ray *ray, t_data *data)
{
    x_intersections(ray, data);
    y_intersections(ray, data);
    distance_to_wall(ray, data);
    // plotLine(data,data->player.x, data->player.y, ray->wall_hit_x, ray->wall_hit_y, 0x00FF00);    
}

// void    finding_x_intercept(t_ray ray)
// {
    
// }

// void    finding_y_intercept(t_ray ray)
// {
    
// }

void x_intersections(t_ray *ray, t_data *data)
{
    double arc_tan = -1/tan(ray->ray_angle);
    
    if(ray->ray_angle > M_PI)
    {
        ray->y_intercept_h = (int)(data->player.y / TILE_SIZE) * TILE_SIZE - 1.5; 
        ray->x_intercept_h = (data->player.y - ray->y_intercept_h)*arc_tan +data->player.x;
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
    ray->x_step_h = -ray->y_step_h * arc_tan;;
    while (ray->x_intercept_h >= 0 &&  ray->x_intercept_h <= data->map_w * TILE_SIZE && ray->y_intercept_h >= 0 && ray->y_intercept_h <= data->map_h * TILE_SIZE)
    {
        if(has_wall_at(data ,ray->x_intercept_h , ray->y_intercept_h))
            break ;
        else
        {
            ray->x_intercept_h += ray->x_step_h;
            ray->y_intercept_h += ray->y_step_h;
        }
    }
}

void    y_intersections(t_ray *ray, t_data *data)
{
    double arc_tan = -tan(ray->ray_angle);
    
    if(ray->ray_angle > M_PI/2 && ray->ray_angle < 3 * M_PI/2)
    {
        ray->x_intercept_v = (int)(data->player.x / TILE_SIZE) * TILE_SIZE - 1.5; 
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
    while (ray->x_intercept_v >= 0 &&  ray->x_intercept_v <= data->map_w * TILE_SIZE && ray->y_intercept_v >= 0 && ray->y_intercept_v <= data->map_h * TILE_SIZE)
    {
        if(has_wall_at(data ,ray->x_intercept_v, ray->y_intercept_v))
            break ;
        else
        {
            ray->x_intercept_v += ray->x_step_v;
            ray->y_intercept_v += ray->y_step_v;
        }
    }
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
        ray->wall_hit_x = ray->x_intercept_v ;
        ray->wall_hit_y = ray->y_intercept_v;
        ray->distance = vert_distance;
    }
    else
    {
        ray->wall_hit_x = ray->x_intercept_h;
        ray->wall_hit_y = ray->y_intercept_h;
        ray->distance = horz_distance;
    }
}

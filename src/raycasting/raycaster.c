/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:11:16 by ylarhris          #+#    #+#             */
/*   Updated: 2023/10/04 14:41:01 by ylarhris         ###   ########.fr       */
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
    ray_angle = data->player.ang -(FOV/2);
    while (i < NUM_RAYS)
    {
        data->player.rays[i].ray_angle = angles(ray_angle);
        ray_angle +=angles( FOV / NUM_RAYS);
        printf("%f\n", data->player.rays[i].ray_angle);
        i++;
    }
}

void render_rays(t_data *data)
{
    int i;

    i = 0;
    while (i < NUM_RAYS)
    {
        plotLine(data, data->player.x, data->player.y,
        data->player.x + cos(data->player.rays[i].ray_angle)*100 , data->player.y +sin(data->player.rays[i].ray_angle)*100,0x737373);
        i++;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:11:16 by ylarhris          #+#    #+#             */
/*   Updated: 2023/10/04 13:03:27 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    cast_all_rays(t_data *data)
{
    int     rays_counter;
    float   ray_angle;
    int     i;

    i = 0;
    rays_counter = 0;
    ray_angle = data->player.angle -(FOV/2);
    while (i < NUM_RAYS)
    {
         
    }
    
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:26:02 by ylarhris          #+#    #+#             */
/*   Updated: 2023/11/17 01:27:17 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int choose_texture(t_ray *ray, float ra)
{
    if (ray->player_hit_vertical_wall)
    {
        if(ra > 0 && ra < PI)
            return 0;
        else
            return 1;
    }
    else
    {
        if(ra > 0.5 * PI && ra < 1.5 * PI)
            return 2;
        else 
            return 3;
    }
}
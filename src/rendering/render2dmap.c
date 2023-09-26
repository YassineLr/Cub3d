/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2dmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:48:58 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/26 01:29:40 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    drawrectangle(t_mlx *mlx, t_cordinate point, int color)
{
    int i;
    int j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j = 0;
        while (j < TILE_SIZE)
        {
            if (i > TILE_SIZE - 2 || j > TILE_SIZE - 2)
                mlx_pixel_put(mlx->mlx_ptr, mlx->win, i + point.x , j + point.y, 0x899499);
            else
                mlx_pixel_put(mlx->mlx_ptr, mlx->win, i + point.x , j + point.y, color);
            j++;
        }
        i++;
    }
}

void    initplayer(t_data *data)
{
    data->player.ang = 0;
    data->player.x = WIN_HEIGHT/2;
    data->player.y = WIN_WIDTH/2;
    data->player.walkdirection = 0;
    data->player.rotationspeed = 0;
    data->player.movespeed = 2.0;
    data->player.rotationspeed = 2 * (PI / 180);
}

void renderplayer(t_data *data, int radius)
{
    int         i = 0;
    int         j = 0;
    t_cordinate center;

    center.x = TILE_SIZE * data->map_h / 2;
    center.y = TILE_SIZE * data->map_w / 2;
    while (i < TILE_SIZE * data->map_h)
    {
        j = 0;
        while (j < TILE_SIZE * data->map_w)
        {
            if(abs(center.x - i) < radius && abs(center.y - j) < radius)
                mlx_pixel_put(data->mlx->mlx_ptr, data->mlx->win, i, j, 0xE2E5DE);
            j++;
        }
        i++;
    }
}

void    draw2dmap(t_data *data)
{
    int         i;
    int         j;
    int         color;
    t_cordinate point;
    
    i = 0;
    while (i < data->map_h)
    {
        j = 0;
        while (j < data->map_w)
        {
            point.x = i * TILE_SIZE;
            point.y = j * TILE_SIZE;
            if (ft_strncmp(data->map[i] + j, "1",1))
                color = 0x000000;
            else
                color =  0XFFFFFF;
            drawrectangle(data->mlx, point, color);
            j++;
        }
        i++;
    }
    // mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, data->mlx->img, 0, 0);
}

// void    playermovement(t_data *data)
// {
//     data->player.x = WIN_HEIGHT/2;
//     data->player.y = WIN_WIDTH/2;
//     data-
// }

void render2dmap(t_data *data)
{
    initplayer(data);
    draw2dmap(data);
    renderplayer(data, 10);
}
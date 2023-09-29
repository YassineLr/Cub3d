/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2dmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:48:58 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/29 06:46:59 by ylarhris         ###   ########.fr       */
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
    data->player.x = TILE_SIZE * data->map_w/2;
    data->player.y = TILE_SIZE * data->map_h/2;
    // data->player.ang = PI/2;
    data->player.turndirection = 0;
    data->player.walkdirection = 0;
    data->player.movespeed = 2.0;
    data->player.rotationspeed = 2 * (PI / 180);
}

int renderplayer(t_data *data, int radius)
{
    int         i = 0;
    int         j = 0;
    t_cordinate center;

    center.x = data->player.x;
    center.y = data->player.y;
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
    return (0);
}

// void    drawline(t_data *data, t_cordinate start, t_cordinate end)
// {
//     int i;

// }

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
            printf("%c\t", data->map[i][j]);
            point.x = j * TILE_SIZE;
            point.y = i * TILE_SIZE;
            if (ft_strncmp(data->map[i] + j, "1",1))
                color = 0x000000;
            else
                color =  0XFFFFFF;
            drawrectangle(data->mlx, point, color);
            j++;
        }
        printf("\n");
        i++;
    }
    // mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, data->mlx->img, 0, 0);
}

void    playermovement(t_data *data)
{
    float movestep;

    movestep = data->player.walkdirection * data->player.movespeed;
    data->player.x = data->player.dx * movestep;
    data->player.y = data->player.dy * movestep;
}

void render2dmap(t_data *data)
{
    data->mlx->img = mlx_new_image(data->mlx->mlx_ptr, WIN_HEIGHT, WIN_WIDTH);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bits_per_pixel, &data->mlx->line_length, &data->mlx->endian);
    initplayer(data);
    draw2dmap(data);
    renderplayer(data, 10);
    playermovement(data);
    mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->img);
    // mlx_loop_hook(data->mlx, renderplayer, data);
}
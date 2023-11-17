/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2dmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:48:58 by ylarhris          #+#    #+#             */
/*   Updated: 2023/11/17 04:07:51 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

// void    drawrectangle(t_mlx *mlx, t_cordinate point, int color)
// {
//     int i;
//     int j;

//     i = 0;
//     while (i < TILE_SIZE)
//     {
//         j = 0;
//         while (j < TILE_SIZE)
//         {
//             if (i > TILE_SIZE - 2 || j > TILE_SIZE - 2)
//                 my_mlx_pixel_put(mlx, i + point.x , j + point.y, 0x899499);
//             else
//                 my_mlx_pixel_put(mlx, i + point.x , j + point.y, color);
//             j++;
//         }
//         i++;
//     }
// }



// void plotLine(t_data *cub3D, int x0, int y0, int x1, int y1, int color)
// {
//     int dx = abs(x1 - x0);
//     int sx = x0 < x1 ? 1 : -1;
//     int dy = -abs(y1 - y0);
//     int sy = y0 < y1 ? 1 : -1;
//     int error = dx + dy;

//     while (1)
//     {
//         my_mlx_pixel_put(cub3D->mlx, x0, y0, color);

//         if (x0 == x1 && y0 == y1)
//             break;

//         int e2 = 2 *error;
//         if (e2 >= dy)
//         {
//             if (x0 == x1)
//                 break;
//             error += dy;
//             x0 += sx;
//         }
//         if (e2 <= dx)
//         {
//             if (y0 == y1)
//                 break;
//             error += dx;
//             y0 += sy;
//         }
//     }
// }

// void    draw_player_direction(t_data *data)
// {
//     float x_end;
//     float y_end;

//     x_end = data->player.x + cos(data->player.ang) * TILE_SIZE;
//     y_end = data->player.y + sin(data->player.ang) * TILE_SIZE;
//     plotLine(data, data->player.x, data->player.y, x_end, y_end, 0xFF0000);
// }

// int renderplayer(t_data *data, int radius)
// {
//     int         i = 0;
//     int         j = 0;
//     t_cordinate center;

//     center.x = data->player.x;
//     center.y = data->player.y;
//     while (i < TILE_SIZE * data->map_w)
//     {
//         j = 0;
//         while (j < TILE_SIZE * data->map_h)
//         {
//             if(abs(center.x - i) < radius && abs(center.y - j) < radius)
//                 my_mlx_pixel_put(data->mlx , i, j, 0xE2E5DE);
//             j++;
//         }
//         i++;
//     }
//     draw_player_direction(data);
//     return (0);
// }

// void    draw2dmap(t_data *data)
// {
//     int         i;
//     int         j;
//     int         color;
//     t_cordinate point;
    
//     i = 0;
//     while (i < data->map_h)
//     {
//         j = 0;
//         while (j < data->map_w)
//         {
//             point.x = j * TILE_SIZE;
//             point.y = i * TILE_SIZE;
//             if (ft_strncmp(data->map[i] + j, "1",1))
//                 color = 0x000000;
//             else
//                 color =  0XFFFFFF;
//             drawrectangle(data->mlx, point, color);
//             j++;
//         }
//         i++;
//     }
// }


int has_wall_at(t_data *data, float x, float y)
{
    int x_index;
    int y_index;

	if (x < 0 || x > data->map_w * TILE_SIZE
		|| y < 0 || y > data->map_h * TILE_SIZE)
		return (1);
    x_index = x / TILE_SIZE;
    y_index = y / TILE_SIZE;
    if(data->map[y_index] && data->map[y_index] + x_index)
        if(ft_strncmp(data->map[y_index] + x_index, "1", 1))
            return (0);
    return 1;
}

void    playermovement(t_data *data)
{
    float   movestep;
    float   new_x;
    float   new_y;
    float   straff;
    
    movestep = data->player.walkdirection * data->player.movespeed;
    data->player.ang += data->player.turndirection * data->player.rotationspeed;
    data->player.ang = angles_normalizer(data->player.ang);
    straff = data->player.straff_direction * data->player.movespeed;
    new_x = data->player.x + cos (data->player.ang) * movestep;
    new_y = data->player.y + sin (data->player.ang) * movestep;
    new_x += cos(data->player.ang + M_PI_2) * straff;
    new_y += sin(data->player.ang + M_PI_2) * straff;
    if(!has_wall_at(data, new_x , new_y) 
        && !has_wall_at(data, new_x +2, new_y +2) 
        && !has_wall_at(data, new_x -2, new_y -2)
        && !has_wall_at(data, new_x -2, new_y +2)
        && !has_wall_at(data, new_x +2, new_y -2))
    {
        data->player.x = new_x;
        data->player.y = new_y;
    }
}


void    rendring(t_data *data)
{
    int i;
    int color;
    int distance_from_top = 0;
    int choice;
    
    i = 0;
    while (i < WIN_WIDTH) 
    {
        int j = 0;
        while (j < WIN_HEIGHT) 
        {
            if (j >= data->player.rays[i].wall_cordinate.top && j <= data->player.rays[i].wall_cordinate.bottom)
            {
                distance_from_top = j + (data->player.rays[i].wall_strip_height/2) - (WIN_HEIGHT/2);
                data->player.rays[i].offset_y = distance_from_top * ((double)data->textures.height / data->player.rays[i].wall_strip_height);
                choice = choose_texture(&data->player.rays[i] , data->player.rays[i].ray_angle);
                color = get_texture_pixel_color(data->player.rays[i].offset_x ,data->player.rays[i].offset_y , data,choice);
                my_mlx_pixel_put(data->mlx, i, j, color);
            }
            else if (j < data->player.rays[i].wall_cordinate.bottom)
                my_mlx_pixel_put(data->mlx, i, j, data->colors.celling);
            else
                my_mlx_pixel_put(data->mlx, i, j, data->colors.floor);
            j++;
        }
        i++;
    }
}

int render2dmap(t_data *data)
{
    int i;
    
    data->mlx->img = mlx_new_image(data->mlx->mlx_ptr,  WIN_WIDTH, WIN_HEIGHT);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bits_per_pixel, &data->mlx->line_length, &data->mlx->endian);
    playermovement(data);
    cast_all_rays(data);
    rays_parameters(data);
    rendring(data);
    mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, data->mlx->img, 0,0);
    mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->img);
    return (1);
}

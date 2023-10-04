/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2dmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:48:58 by ylarhris          #+#    #+#             */
/*   Updated: 2023/10/04 14:53:12 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

    if(x < 0 || x > WIN_HEIGHT || y < 0 || y > WIN_WIDTH)
        return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
                my_mlx_pixel_put(mlx, i + point.x , j + point.y, 0x899499);
            else
                my_mlx_pixel_put(mlx, i + point.x , j + point.y, color);
            j++;
        }
        i++;
    }
}

void    initplayer(t_data *data)
{
    data->player.x *= TILE_SIZE ;
    data->player.y *= TILE_SIZE ;
    data->player.turndirection = 0;
    data->player.walkdirection = 0;
    data->player.movespeed = 1.5; 
    data->player.rotationspeed = 2 * (PI / 180);
    data->player.to_do = 0;
}


void plotLine(t_data *cub3D, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int error = dx + dy;

    while (1)
    {
        my_mlx_pixel_put(cub3D->mlx, x0, y0, color);

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 *error;
        if (e2 >= dy)
        {
            if (x0 == x1)
                break;
            error += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            if (y0 == y1)
                break;
            error += dx;
            y0 += sy;
        }
    }
}


void    draw_player_direction(t_data *data)
{
    float x_end;
    float y_end;

    x_end = data->player.x + cos(data->player.ang) * TILE_SIZE;
    y_end = data->player.y + sin(data->player.ang) * TILE_SIZE;
    plotLine(data, data->player.x, data->player.y, x_end, y_end, 0xFF0000);
}
int renderplayer(t_data *data, int radius)
{
    int         i = 0;
    int         j = 0;
    t_cordinate center;

    center.x = data->player.x;
    center.y = data->player.y;
    while (i < TILE_SIZE * data->map_w)
    {
        j = 0;
        while (j < TILE_SIZE * data->map_h)
        {
            if(abs(center.x - i) < radius && abs(center.y - j) < radius)
                my_mlx_pixel_put(data->mlx , i, j, 0xE2E5DE);
            j++;
        }
        i++;
    }
    draw_player_direction(data);
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
            point.x = j * TILE_SIZE;
            point.y = i * TILE_SIZE;
            if (ft_strncmp(data->map[i] + j, "1",1))
                color = 0x000000;
            else
                color =  0XFFFFFF;
            drawrectangle(data->mlx, point, color);
            j++;
        }
        i++;
    }
}

float angles(float angle)
{
    if(angle < 0)
        angle += 2* M_PI;
    else if(angle > 2*M_PI)
        angle -= 2 * M_PI;
    return (angle);
}
int has_wall_at(t_data *data, float x, float y)
{
    int x_index;
    int y_index;
    
	if (x < 0 || x > data->map_w * TILE_SIZE
		|| y < 0 || y > data->map_h * TILE_SIZE)
		return (1);
    x_index = x/TILE_SIZE;
    y_index = y/TILE_SIZE;
    if(ft_strncmp(data->map[y_index]+ x_index, "1", 1))
        return (0);
    return 1;
}

void    playermovement(t_data *data)
{
    float   movestep;
    float   new_x;
    float   new_y;
    
    movestep = data->player.walkdirection * data->player.movespeed;
    data->player.ang += data->player.turndirection * data->player.rotationspeed;
    data->player.ang = angles(data->player.ang);
    new_x = data->player.x + cos (data->player.ang) * movestep;
    new_y = data->player.y + sin (data->player.ang) * movestep;
    if(!has_wall_at(data, new_x, new_y))
    {
        data->player.x = new_x;
        data->player.y = new_y;
    }
}


int render2dmap(t_data *data)
{
    // printf("hey from rendering\n");
    data->mlx->img = mlx_new_image(data->mlx->mlx_ptr, WIN_HEIGHT, WIN_WIDTH);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bits_per_pixel, &data->mlx->line_length, &data->mlx->endian);
    // playermovement(data);
    // printf("%f\t %f\n", data->player.x, data->player.y);
    draw2dmap(data);
    playermovement(data);
    renderplayer(data, 5);
    
    cast_all_rays(data);
    render_rays(data);
    // plotLine(data, data->player.x,data->player.y , 200,200, 0xFF0000);
    // printf("%f\n");
    // draw_line(data->mlx, data->player.x, data->player.y, 20,data->player.ang,0x070707);
    mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, data->mlx->img, 0,0);
    mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->img);
    return (1);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventHandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 01:46:28 by ylarhris          #+#    #+#             */
/*   Updated: 2023/10/02 15:12:30 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

int	keypressed(int keycode, t_data *data)
{
    float movestep;

	if(keycode == ESC)
		exit(1);
    else if(keycode == KEYUP)
        data->player.walkdirection = 1;
    else if(keycode == KEYDOWN)
        data->player.walkdirection = -1;
    else if(keycode == RIGHT_ARROW)
        data->player.turndirection = 1;
    else if(keycode == LEFT_ARROW)
        data->player.turndirection = -1;
   
	return (0);
}

int keyreleased(int keycode, t_data *data)
{
    if(keycode == KEYUP)
        data->player.walkdirection = 0;
    else if(keycode == KEYDOWN)
        data->player.walkdirection = 0;
    else if(keycode == RIGHT_ARROW)
        data->player.turndirection = 0;
    else if(keycode == LEFT_ARROW)
        data->player.turndirection = 0;
	return (0);
}

// void    key_up(t_data *data)
// {
//     float   movestep;
    
//     data->player.walkdirection = 1;
//     movestep = data->player.walkdirection * data->player.movespeed;
//     data->player.x += data->player.dx * movestep;
//     data->player.y += data->player.dy * movestep;    
// }

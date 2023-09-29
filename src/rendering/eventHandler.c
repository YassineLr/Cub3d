/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventHandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 01:46:28 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/29 04:40:10 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

int	keypressed(int keycode, t_data *data)
{
    printf("%d\n", keycode);
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
    printf("%d  %d\n",data->player.walkdirection, data->player.turndirection);
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
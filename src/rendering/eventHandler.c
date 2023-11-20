/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventHandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 01:46:28 by ylarhris          #+#    #+#             */
/*   Updated: 2023/11/20 23:03:07 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	keypressed(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(1);
	else if (keycode == W_KEY)
		data->player.walkdirection = 1;
	else if (keycode == S_KEY)
		data->player.walkdirection = -1;
	else if (keycode == D_KEY)
		data->player.straff_direction = 1;
	else if (keycode == A_KEY)
		data->player.straff_direction = -1;
	else if (keycode == RIGHT_ARROW)
		data->player.turndirection = 1;
	else if (keycode == LEFT_ARROW)
		data->player.turndirection = -1;
	return (0);
}

int	keyreleased(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->player.walkdirection = 0;
	else if (keycode == S_KEY)
		data->player.walkdirection = 0;
	else if (keycode == RIGHT_ARROW)
		data->player.turndirection = 0;
	else if (keycode == LEFT_ARROW)
		data->player.turndirection = 0;
	else if (keycode == D_KEY || keycode == A_KEY)
		data->player.straff_direction = 0;
	return (0);
}

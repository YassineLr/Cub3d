/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventHandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 01:46:28 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/26 03:47:05 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

int	eventlistener(int keycode, t_data *data)
{
	if(keycode == ESC)
		exit(1);
    // else if(keycode == KEYUP)
    // {
    //     data->player.
    // }
    
	// printf("Hello from key_hook!\n");
	return (0);
}

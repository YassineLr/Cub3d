/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:20:23 by yismaail          #+#    #+#             */
/*   Updated: 2023/09/18 05:02:59 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_palyer
{
	int i;
	
}			t_player;

typedef struct s_data
{
	char	*path;
	char	**map;
	int		map_h;
	int		map_w;
	
}			t_data;

void init_game(t_data *data, int ac, char **av);
void	ft_exit(t_data *data, const char *str, int code);

#endif
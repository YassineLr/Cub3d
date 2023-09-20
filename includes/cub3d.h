/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:20:23 by yismaail          #+#    #+#             */
/*   Updated: 2023/09/20 00:42:28 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_palyer
{
	int r;
	
}			t_player;

typedef struct s_get_color
{
	size_t	start;
	char	*temp[3];
	size_t	len;
	int		ret;
}			t_get_color;

typedef struct s_color
{
	int	floor;
	int	celling;
}			t_color;

typedef struct s_texture
{
	int		height;
	int		width;
	char	*no_texture;
	char	*so_texture;
	char	*ea_texture;
	char	*we_texture;
}			t_texture;

typedef struct s_data
{
	char	*path;
	char	**map;
	int		map_h;
	int		map_w;
	t_texture	textures;
	t_color		colors;
}			t_data;

void init_game(t_data *data, int ac, char **av);
void	ft_exit(t_data *data, const char *str, int code);
void	free_ptr(char **str);
void	get_data(t_data *data);
void	free_ptr(char **str);
void	close_fds(int min, int max);

#endif
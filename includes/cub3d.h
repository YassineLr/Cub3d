/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:20:23 by yismaail          #+#    #+#             */
/*   Updated: 2023/09/22 08:18:45 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"

# define WIN_NAME "Cub3d"
# define WIN_HEIGHT 600
# define WIN_WIDTH 960
# define PI 3.1415

typedef struct s_palyer
{
	float	x;
	float	y;
	float	col_x;
	float	col_y;
	float	dx;
	float	dy;
	float	ang;
	int		direction;
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
	t_player	player;
}			t_data;

void init_game(t_data *data, int ac, char **av);
void	ft_exit(t_data *data, const char *str, int code);
void	free_ptr(char **str);
void	get_data(t_data *data);
void	free_ptr(char **str);
void	free_mat(char ***mat);
void	close_fds(int min, int max);
int get_map(t_data *data, char *line);
void	get_format(char ***map, size_t height, size_t width);
void	get_player_info(t_data *data);
void	check_map(t_data *data);

#endif
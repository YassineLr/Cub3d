/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:28:08 by yismaail          #+#    #+#             */
/*   Updated: 2023/11/20 22:02:48 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_temp(char ***map, size_t map_height, size_t map_width)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	map[0] = ft_calloc (map_height + 1, sizeof (char *));
	temp = map_height;
	while (temp--)
		map[0][temp] = ft_calloc (map_width + 1, sizeof (char *));
	i = 0;
	while (map_height--)
	{
		j = 0;
		temp = map_width;
		while (temp--)
		{
			map[0][i][j] = ' ';
			j++;
		}
		i++;
	}
}

static void	get_direction(t_data *data, size_t x, size_t y)
{
	data -> player.x = x + 0.5;
	data -> player.y = y + 0.5;
	data -> player.col_x = x * (WIN_WIDTH / data->map_w);
	data -> player.col_y = y * (WIN_HEIGHT / data->map_h);
	data -> player.walkdirection = data -> map[y][x];
	if (data -> map[y][x] == 'N')
		data -> player.ang = PI / 2;
	if (data -> map[y][x] == 'E')
		data -> player.ang = PI;
	if (data -> map[y][x] == 'S')
		data -> player.ang = 3 * PI / 2;
}

void	get_player_info(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (data->map && data->map[y])
	{
		x = 0;
		while (data->map[y] && data->map[y][x])
		{
			if (ft_strchr("NSEW", data->map[y][x]))
				get_direction(data, x, y);
			x++;
		}
		y++;
	}
}

void	get_format(char ***map, size_t height, size_t width)
{
	char	**temp;
	size_t	i;
	size_t	j;

	set_temp(&temp, height, width);
	i = 0;
	while (map[0] && map[0][i])
	{
		j = 0;
		while (map[0][i] && map[0][i][j])
		{
			if (map[0][i][j] == '\n')
				map[0][i][j] = ' ';
			temp[i][j] = map[0][i][j];
			j++;
		}
		i++;
	}
	free_mat (map);
	map[0] = temp;
}

int	get_map(t_data *data, char *line)
{
	char	**temp;
	int		i;

	data->map_h++;
	temp = ft_calloc(data->map_h + 1, sizeof(char *));
	if (!temp)
		ft_exit(data, "Can't allocate memory", 1);
	i = 0;
	while (data->map && data->map[i])
	{
		temp[i] = ft_strdup(data->map[i]);
		i++;
	}
	if (data->map_w < (int)ft_strlen(line))
		data->map_w = (int)ft_strlen(line);
	temp[i] = ft_strdup(line);
	free_mat(&data->map);
	data->map = temp;
	return (1);
}

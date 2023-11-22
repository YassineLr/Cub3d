/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 03:03:45 by yismaail          #+#    #+#             */
/*   Updated: 2023/11/22 02:00:43 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_args(int ac, t_data *data)
{
	if (ac != 2)
		ft_exit(data, "to much args\n", 2);
}

static void	get_file_name(char *name, t_data *data)
{
	char	*ext;

	data->path = name;
	ext = ft_strrchr(data->path, '.');
	if (ft_strncmp(ext, ".cub", ft_strlen(".cub") + 1))
		ft_exit(data, "Not the same '.cub'", 1);
}

static void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	ft_bzero(&data->textures, sizeof(t_texture));
	ft_bzero(&data->colors, sizeof(t_color));
}

// void	init_textures(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < 4)
// 		data->textures.image[i] = init_texture(data, i);
// }

void	init_game(t_data *data, int ac, char **av)
{
	init_data(data);
	check_args(ac, data);
	get_file_name(av[1], data);
	get_data(data);
	// get_format(&data->map, data->map_h, data->map_w);
	// data->map_w--;
	// get_player_info(data);
	// if (!data->map || !(int)data->player.x || !data->player.y)
	// 	ft_exit(data, "invalide information", 1);
	// check_map(data);
	// data->mlx = mlx_initializer();
	// init_textures(data);
}

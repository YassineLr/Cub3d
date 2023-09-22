/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 03:03:45 by yismaail          #+#    #+#             */
/*   Updated: 2023/09/22 10:10:37 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void check_args(int ac, t_data *data)
{
	if (ac != 2)
		ft_exit(data, "to much args\n", 2);
}

static void get_file_name(char *name, t_data *data)
{
	char *ext;

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

// static void affich_map(char **map)
// {
// 	int i = 0;
// 	while (map[i])
// 	{
// 		// int j = 0;
// 		printf("%s", map[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

// static void affich_info(t_data *data)
// {
// 	if (data)
// 	{
// 		if (data->path)
// 			printf("file name : %s\n", data->path);
// 		if (data->map)
// 			affich_map(data->map);
// 		if (data->map_h)
// 			printf("height : %d\n", data->map_h);
// 		if (data->map_w)
// 			printf("width : %d\n", data->map_w);
// 		if (data->colors.celling && data->colors.floor)
// 			printf("f : %d\nc : %d\n", data->colors.floor, data->colors.celling);
// 		if (data->textures.no_texture)
// 			printf("no : %s\n", data->textures.no_texture);
// 		if (data->textures.ea_texture)
// 			printf("ea : %s\n", data->textures.ea_texture);
// 		if (data->textures.so_texture)
// 			printf("so : %s\n", data->textures.so_texture);
// 		if (data->textures.we_texture)
// 			printf("we : %s\n", data->textures.we_texture);
// 	}
// }

void	init_game(t_data *data, int ac, char **av)
{
	init_data(data);
	check_args(ac, data);
	get_file_name(av[1], data);
	get_data(data);
	get_format(&data->map, data->map_h, data->map_w);
	data->map_w--;
	get_player_info(data);
	if (!data->map || !(int)data->player.x || !data->player.y)
		ft_exit(data, "invalide information", 1);
	check_map(data);
	// affich_info(data);
}
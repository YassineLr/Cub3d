/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 03:03:45 by yismaail          #+#    #+#             */
/*   Updated: 2023/11/24 22:39:46 by yismaail         ###   ########.fr       */
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

void	init_textures(t_data *data)
{
	int	i;
	data->textures.width = 64;
	data->textures.height = 64;
	i = -1;
	while (++i < 4)
		data->textures.image[i] = init_texture(data, i);
}

static void print_map(char **map)
{
	int i = 0;
    while (map[i]) {
        printf("%s\n", map[i]);
        i++;
    }
}

static void print_data(t_data *data) {
    printf("Path: %s\n", data->path);
    // Add print statements for the fields in the textures and colors structures
    // For example, if textures has a field called 'image', you could do:
    // printf("Texture image: %s\n", data->textures.image);
    // Do the same for the colors structure
    // Print the map, map height, and map width
	print_map(data->map);
    printf("Map height: %d\n", data->map_h);
    printf("Map width: %d\n", data->map_w);
	
    // Print the player information
    // For example, if player has fields 'x' and 'y', you could do:
    // printf("Player x: %d\n", data->player.x);
    // printf("Player y: %d\n", data->player.y);
    // Print the mlx information
    // This will depend on what type mlx is and what information you want to print
}

static void	init_g()
{
	F_COUNTER = 0;
	C_COUNTER = 0;
	NO_COUNTER = 0;
	WE_COUNTER = 0;
	SO_COUNTER = 0;
	EA_COUNTER = 0;
	MAP_COUNTER = 0;
}

void	init_game(t_data *data, int ac, char **av)
{
	init_g();
	init_data(data);
	check_args(ac, data);
	get_file_name(av[1], data);
	get_data(data);
	get_format(&data->map, data->map_h, data->map_w);
	data->map_w--;
	get_player_info(data);
	printf("NO = %s\n", data->textures.no_texture);
	printf("WE = %s\n", data->textures.we_texture);
	printf("SO = %s\n", data->textures.so_texture);
	printf("EA = %s\n", data->textures.ea_texture);
	printf("F = %d\n", data->colors.floor);
	printf("C = %d\n", data->colors.celling);
	if (!data->map || !(int)data->player.x || !data->player.y
		|| !data->textures.no_texture || !data->textures.so_texture
		|| !data->textures.ea_texture || !data->textures.we_texture)
		ft_exit(data, "invalioode information", 1);
	if (C_COUNTER != 1 || F_COUNTER != 1 || NO_COUNTER != 1 || SO_COUNTER != 1 || WE_COUNTER != 1 || EA_COUNTER != 1)
	{
		// printf("NO = %d\n SO = %d\n WE = %d\n EA = %d\n C = %d\n f = %d\n MAP = %d\n",
		// 			NO_COUNTER, SO_COUNTER, WE_COUNTER, EA_COUNTER, C_COUNTER, F_COUNTER, MAP_COUNTER);
		ft_exit(data, "Something missing", 1);
	}
	print_data(data);
	check_map(data);
	data->mlx = mlx_initializer();
	init_textures(data);
}

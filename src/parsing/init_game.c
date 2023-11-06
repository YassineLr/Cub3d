/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 03:03:45 by yismaail          #+#    #+#             */
/*   Updated: 2023/11/05 23:55:34 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static void init_data(t_data *data)
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

t_image init_texture(t_data *data)
{
	t_image image;
	// image = malloc(sizeof(t_image));
	// printf("%s   %d   %d\n", data->textures.no_texture, data->textures.width, data->textures.height);
	image.img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->textures.no_texture, &data->textures.width, &data->textures.height);
	if (!image.img)
		ft_exit(data, "cannot open this image", 1);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	if (!image.addr)
		ft_exit(data, "cannot get data address from texture", 1);
	return (image);
}
void init_textures(t_data *data)
{
	data->textures.nord_image = init_texture(data);
	data->textures.west_image = init_texture(data);
	data->textures.east_image = init_texture(data);
	data->textures.south_image = init_texture(data);
	
	// data->textures.nord_image = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->textures.no_texture, &data->textures.width, &data->textures.height);
	// data->textures.west_image = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->textures.no_texture, &data->textures.width, &data->textures.height);
	// data->textures.east_image = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->textures.no_texture, &data->textures.width, &data->textures.height);
	// data->textures.south_image = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->textures.no_texture, &data->textures.width, &data->textures.height);
	// if (data->textures.height != data->textures.width)
	// 	ft_exit(data, "can't open this image", 1);
	// data->textures.addr = mlx_get_data_addr()
}

void init_game(t_data *data, int ac, char **av)
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
	data->mlx = mlx_initializer();
	init_textures(data);
	// affich_info(data);
}
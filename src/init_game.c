/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 03:03:45 by yismaail          #+#    #+#             */
/*   Updated: 2023/09/20 06:00:37 by yismaail         ###   ########.fr       */
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
}

static void affich_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		// int j = 0;
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
}

static void affich_info(t_data *data)
{
	if (data)
	{
		if (data->path)
			printf("file name : %s\n", data->path);
		if (data->map)
			affich_map(data->map);
		if (data->map_h)
			printf("height : %d\n", data->map_h);
		if (data->map_w)
			printf("width : %d\n", data->map_w);
		if (data->colors.celling && data->colors.floor)
			printf("f : %d\nc : %d\n", data->colors.floor, data->colors.celling);
	}
}

void init_game(t_data *data, int ac, char **av)
{
	init_data(data);
	check_args(ac, data);
	get_file_name(av[1], data);
	get_data(data);
	affich_info(data);
}
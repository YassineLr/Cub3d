/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 03:03:45 by yismaail          #+#    #+#             */
/*   Updated: 2023/09/19 05:27:22 by yismaail         ###   ########.fr       */
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

// static void	affich_data(t_data *data)
// {
// 	if (data)
// 	{
// 		if (data->path)
// 		{
// 			printf("path")
// 		}
// 	}
// }


void init_game(t_data *data, int ac, char **av)
{
	init_data(data);
	check_args(ac, data);
	get_file_name(av[1], data);
	get_data(data);
	// affich_data(data);
}
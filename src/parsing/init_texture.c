/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:47:11 by yismaail          #+#    #+#             */
/*   Updated: 2023/11/10 21:58:22 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_image(t_data *data, char *path, t_image *image)
{
	image->img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, path, &data->textures.width, &data->textures.height);
	if (!image->img)
		ft_exit(data, "cannot open this image", 1);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
	if (!image->addr)
		ft_exit(data, "cannot get data address from texture", 1);
}

t_image init_texture(t_data *data, int flag)
{
	t_image image;

	if (flag == 0)
	{
		init_image(data, data->textures.no_texture, &image);
		// image.img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->textures.no_texture, &data->textures.width, &data->textures.height);
		// if (!image.img)
		// 	ft_exit(data, "cannot open this image", 1);
		// image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
		// if (!image.addr)
		// 	ft_exit(data, "cannot get data address from texture", 1);
	}
	else if (flag == 1)
	{
		init_image(data, data->textures.so_texture, &image);
		// image.img = ml1x_xpm_file_to_image(data->mlx->mlx_ptr, data->textures.no_texture, &data->textures.width, &data->textures.height);
		// if (!image.img)
		// 	ft_exit(data, "cannot open this image", 1);
		// image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
		// if (!image.addr)
		// 	ft_exit(data, "cannot get data address from texture", 1);
	}
	else if (flag == 3)
	{
		init_image(data, data->textures.we_texture, &image);
		// image.img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->textures.no_texture, &data->textures.width, &data->textures.height);
		// if (!image.img)
		// 	ft_exit(data, "cannot open this image", 1);
		// image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
		// if (!image.addr)
		// 	ft_exit(data, "cannot get data address from texture", 1);
	}
	else if (flag == 4)
	{
		init_image(data, data->textures.ea_texture, &image);
		// image.img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, data->textures.no_texture, &data->textures.width, &data->textures.height);
		// if (!image.img)
		// 	ft_exit(data, "cannot open this image", 1);
		// image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
		// if (!image.addr)
			// ft_exit(data, "cannot get data address from texture", 1);
	}
	return (image);
}

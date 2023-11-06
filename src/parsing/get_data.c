/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 06:56:08 by yismaail          #+#    #+#             */
/*   Updated: 2023/11/04 23:21:54 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_color(int *color, char *line)
{
	t_get_color	c;

	ft_bzero (&c, sizeof (t_get_color));
	c.ret = 1;
	c.start = 2;
	c.len = ft_strchr (line + c.start, ',') - line - c.start;
	c.temp[0] = ft_substr (line, c.start, c.len);
	*color = ft_atoi (c.temp[0]) << 16;
	c.start += c.len + 1;
	c.len = ft_strchr (line + c.start, ',') - line - c.start;
	c.temp[1] = ft_substr (line, c.start, c.len);
	*color |= ((unsigned char) ft_atoi (c.temp[1])) << 8;
	c.start += c.len + 1;
	c.len = ft_strchr (line + c.start, '\0') - line - c.start;
	c.temp[2] = ft_substr (line, c.start, c.len);
	*color |= ((unsigned char) ft_atoi (c.temp[2]));
	if (!(ft_atoi(c.temp[0]) >= 0 && ft_atoi(c.temp[0]) <= 255)
		|| !(ft_atoi(c.temp[1]) >= 0 && ft_atoi(c.temp[1]) <= 255)
		|| !(ft_atoi(c.temp[2]) >= 0 && ft_atoi(c.temp[2]) <= 255))
			c.ret = -1;
	if (!c.temp[0] || !c.temp[1] || !c.temp[2])
		c.ret = -1;
	free_ptr (&c.temp[0]);
	free_ptr (&c.temp[1]);
	free_ptr (&c.temp[2]);
	return (c.ret);
}

static int	set_data(char *line, t_data *data)
{
	static int	s;
	size_t		i;
	int			color;

	i = 0;
	color = 0;
	data->textures.width = 64;
	data->textures.height = 64;
	while (line[i] && line[i] != '\n')
		i++;
	if (!ft_strncmp(line, "NO ", 3) && !s)
		data->textures.no_texture = ft_strtrim(line , "NO \n\r");
	else if (!ft_strncmp(line, "SO ", 3) && !s)
		data->textures.so_texture = ft_strtrim(line , "SO \n\r");
	else if (!ft_strncmp(line, "EA ", 3) && !s)
		data->textures.ea_texture = ft_strtrim(line , "EA \n\r");
	else if (!ft_strncmp(line, "WE ", 3) && !s)
		data->textures.we_texture = ft_strtrim(line , "WE \n\r");
	else if (!ft_strncmp(line, "C ", 2) && !s)
		color = get_color(&data->colors.celling, line);
	else if (!ft_strncmp(line, "F ", 2) && !s)
		color = get_color(&data->colors.floor, line);
	else if (ft_strchr("NWES10", line[0]) || s)
		s = get_map(data, line);
	return (color);
}

void	get_data(t_data *data)
{
	char	*line;
	int		fd;
	int		err;

	fd = open(data->path, O_RDONLY);
	if (fd < 0)
		ft_exit(data, "cannot open this file discriptor", 1);
	line = get_next_line(fd);
	err = 0;
	while (line && err >= 0)
	{
		err += set_data(line, data);
		free_ptr(&line);
		line = get_next_line(fd);
	}
	if (err < 2)
	{
		while (line)
		{
			free_ptr(&line);
			line = get_next_line(fd);
		}
	}
	if (err < 2)
		ft_exit(data, "invalide information", 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:04:12 by yismaail          #+#    #+#             */
/*   Updated: 2023/11/23 10:40:51 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_border(t_data *data, char **map, int y)
{
	int	x;

	x = 0;
	while (x < data->map_w)
	{
		if (map[y][x] != ' ' && map[y][x] != '1')
			ft_exit(data, "Invalid Map1.", 7);
		if (y == 0 && map[y][x] == ' ')
		{
			if (map[1][x] != ' ' && map[1][x] != '1')
				ft_exit(data, "Invalid Map2.", 8);
		}
		else if (y == data->map_h - 1 && map[y][x] == ' ')
		{
			if (map[y - 1][x] != ' ' && map[y - 1][x] != '1')
				ft_exit(data, "Invalid Map3.", 9);
		}
		x++;
	}
}

static void	check_arround_middle(t_data *data, int y, int x, char **map)
{
	if (x == 0 && map[y][x] == ' ')
	{
		if ((map[y][x + 1] != ' ' && map[y][x + 1] != '1') || \
		(map[y - 1][x] != ' ' && map[y - 1][x] != '1') || \
		(map[y + 1][x] != ' ' && map[y + 1][x] != '1'))
			ft_exit(data, "Invalid Map4.", 4);
	}
	else if (x == data->map_w - 1 && map[y][x] == ' ')
	{
		if (((map[y][x - 1] != ' ' && map[y][x - 1] != '1') || \
		(map[y - 1][x] != ' ' && map[y - 1][x] != '1') || \
		(map[y + 1][x] != ' ' && map[y + 1][x] != '1')))
			ft_exit (data, "Invalid Map5.", 5);
	}
	else if (map[y][x] == ' ')
	{
		if (((map[y][x - 1] != ' ' && map[y][x - 1] != '1') || \
		(map[y][x + 1] != ' ' && map[y][x + 1] != '1') || \
		(map[y - 1][x] != ' ' && map[y - 1][x] != '1') || \
		(map[y + 1][x] != ' ' && map[y + 1][x] != '1')))
			ft_exit(data, "Invalid Map6.", 6);
	}
}

static void	check_middle(t_data *data, char **map, int y)
{
	int	x;

	x = 0;
	while (x < data->map_w)
	{
		if (x == 0 || x == data->map_w - 1)
		{
			if (map[y][x] != ' ' && map[y][x] != '1')
				ft_exit(data, "Invalid Map7.", 3);
		}
		check_arround_middle(data, y, x, map);
		x++;
	}
}

static void	check_characters(t_data *data, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (y < data -> map_h)
	{
		x = 0;
		while (x < data -> map_w)
		{
			if (!ft_strchr("NSEW01 ", map[y][x]))
				ft_exit(data, "Invalid Map8.", 1);
			x++;
		}
		y++;
	}
}

static int isMapSplitByNewline(char **map) {
    int i;
	int	count;

	i = 0;
	count = 0;
    while (map[i]) {
		if (ft_isempty(map[i]) == 1)
			count++;
        i++;
    }
	if (count != 0)
		return (1);
    return (0);
}

static int	b_strchr(const char *s, int c)
{
	while (s && *s)
	{
		if (*s == (unsigned char)c)
			return (1);
		s++;
	}
	if (s && *s == (unsigned char)c)
		return (1);
	return (0);
}

static int	isDuplicate(char **map)
{
	int	i;
	int flag;
	int	j;
	
	i = 0;
	flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (b_strchr("NWES", map[i][j]))
				flag++;
			j++;	
		}
		i++;
	}
	if (flag > 1)
		return (1);
	return (0);
}

static void	final_check(t_data *data, char **map)
{
	if (isMapSplitByNewline(map) == 1)
		ft_exit(data, "Invalid Map9.", 1);
	if (isDuplicate(map) == 1)
		ft_exit(data, "Invalide Map10.", 1);
	
}

void	check_map(t_data *data)
{
	int	y;

	y = 0;
	check_characters(data, data->map);
	while (data->map[y])
	{
		if (y == 0 || y == data->map_h - 1)
			check_border(data, data->map, y);
		else
			check_middle(data, data->map, y);
		y++;
	}
	final_check(data, data->map);
}

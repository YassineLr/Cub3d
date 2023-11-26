/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banana.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:21:40 by yismaail          #+#    #+#             */
/*   Updated: 2023/11/26 00:31:32 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_map_split_by_new_line(char **map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
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

static int	is_duplicate(char **map)
{
	int	i;
	int	flag;
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

void	final_check(t_data *data, char **map)
{
	if (is_map_split_by_new_line(map) == 1)
		ft_exit(data, "Invalid Map9.", 1);
	if (is_duplicate(map) == 1)
		ft_exit(data, "Invalide Map10.", 1);
	check_plus(data);
}

// void	init_g(void)
// {
// 	g_f_counter = 0;
// 	g_c_counter = 0;
// 	g_no_counter = 0;
// 	g_we_counter = 0;
// 	g_so_counter = 0;
// 	g_ea_counter = 0;
// 	g_map_counter = 0;
// }

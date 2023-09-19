/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 03:43:32 by yismaail          #+#    #+#             */
/*   Updated: 2023/09/19 03:45:03 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void print_message(const char *str, int code)
{
	if (code)
		ft_putstr_fd("ERROR", 2);
	if (str)
		ft_putendl_fd(str, 2);
	if (!code && !str)
		ft_putendl_fd("thella", 1);
}

void	free_ptr(char **str)
{
	free(*str);
	*str = NULL;
}

void	close_fds(int min, int max)
{
	while (min <= max)
		close(min++);
}

void	ft_exit(t_data *data, const char *str, int code)
{
	print_message(str, code);
	close_fds(0, 1023);
	exit(code);
}
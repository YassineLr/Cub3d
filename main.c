/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 03:26:36 by yismaail          #+#    #+#             */
/*   Updated: 2023/09/19 05:27:53 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/cub3d.h"

int main (int ac, char **av)
{
	t_data	*data;
	 data = NULL;
	init_game(data, ac, av);
	// run_game(data);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:38:33 by yismaail          #+#    #+#             */
/*   Updated: 2023/11/22 07:31:06 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int isSpecialCharacter(char *str)
{
    int i;

	i = 0;
    while (str[i]) {
        if (!ft_isalnum((unsigned char)str[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

static int ft_isstr(char *str)
{
	int	i;

	i =0;
	while (str[i]  && ft_isdigit(str[i]) == 1)
		i++;
	if (!ft_isdigit(str[i]))
		return (1);
	// printf("i ==== %d\n", i);
	return (0);
}

void check_nbr(t_get_color *c, int *i)
{
	printf("R = '%s' ", c->temp[0]);
	printf("G = '%s' ", c->temp[1]);
	printf("B = '%s' \n", c->temp[2]);
	if (!c->temp[0] || !c->temp[1] || !c->temp[2])
		*i = -1;
	if (ft_isempty(c->temp[0]) == 1 || ft_isempty(c->temp[1]) == 1 || ft_isempty(c->temp[2]) == 1)
		*i = -1;		
	if (ft_isstr(c->temp[0]) == 1 || ft_isstr(c->temp[1]) == 1 || ft_isstr(c->temp[2]) == 1)
		*i = -1;
	if (ft_strlen(c->temp[0]) >= 4 || ft_strlen(c->temp[1]) >= 4 || ft_strlen(c->temp[2]) - 1 >= 4)
		*i = -1;
	if (isSpecialCharacter(c->temp[0]) == 1 || isSpecialCharacter(c->temp[1]) == 1 || isSpecialCharacter(c->temp[2]) == 1)
    if (!(ft_atoi(c->temp[0]) >= 0 && ft_atoi(c->temp[0]) <= 255)
		|| !(ft_atoi(c->temp[1]) >= 0 && ft_atoi(c->temp[1]) <= 255)
		|| !(ft_atoi(c->temp[2]) >= 0 && ft_atoi(c->temp[2]) <= 255))
			*i = -1;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:38:33 by yismaail          #+#    #+#             */
/*   Updated: 2023/11/23 04:46:38 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// static int isSpecialCharacter(char *str)
// {
//     int i;

// 	i = 0;
//     while (str[i]) {
//         if (!ft_isalnum((unsigned char)str[i])) {
//             return 1;
//         }
//         i++;
//     }
//     return 0;
// }

int isOnlyDigits(char *str) {
    int i = 0;
    while (str[i]) {
        if (!ft_isdigit((unsigned char)str[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

// static int ft_isstr(char *str)
// {
// 	int	i;
// 	int	len;

// 	i =0;
// 	len = ft_strlen(str);	
// 	while (str[i]  && ft_isdigit(str[i]) == 1)
// 		i++;
// 	printf("i = %d\n", i);
// 	printf("len = %d\n", len);
// 	if (!str[i])
// 		return (0);
// 	if (!ft_isalnum(str[i]))
// 		return (1);
// 	// printf("i ==== %d\n", i);
// 	return (0);
// }

void check_nbr(t_get_color *c, int *i)
{
	printf("R = '%s' ", c->temp[0]);
	printf("G = '%s' ", c->temp[1]);
	printf("B = '%s'\n", c->temp[2]);
	if (!c->temp[0] || !c->temp[1] || !c->temp[2])
		*i = -1;
	if (ft_isempty(c->temp[0]) == 1 || ft_isempty(c->temp[1]) == 1 || ft_isempty(c->temp[2]) == 1)
		*i = -1;		
	if (isOnlyDigits(c->temp[0]) == 1 || isOnlyDigits(c->temp[1]) == 1 || isOnlyDigits(c->temp[2]) == 1)
		*i = -1;
	if (ft_strlen(c->temp[0]) >= 4 || ft_strlen(c->temp[1]) >= 4 || ft_strlen(c->temp[2]) >= 4)
		*i = -1;
    if (!(ft_atoi(c->temp[0]) >= 0 && ft_atoi(c->temp[0]) <= 255)
		|| !(ft_atoi(c->temp[1]) >= 0 && ft_atoi(c->temp[1]) <= 255)
		|| !(ft_atoi(c->temp[2]) >= 0 && ft_atoi(c->temp[2]) <= 255))
			*i = -1;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anglesnormalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:05:48 by ylarhris          #+#    #+#             */
/*   Updated: 2023/11/18 19:45:13 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	angles_normalizer(float angle)
{
	double	result;

	result = fmod((double)angle, 2 * PI);
	if (result < 0)
		result += 2 * PI;
	return ((float)result);
}

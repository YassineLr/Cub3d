/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertangles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:05:48 by ylarhris          #+#    #+#             */
/*   Updated: 2023/10/04 12:59:22 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double  degretorad(double angle)
{
	return (angle * (PI / 180.0));
}

double  radtodegre(double angle)
{
	return (angle * (180.0 / PI));
}

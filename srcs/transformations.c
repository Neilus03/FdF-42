/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trasformations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:30:53 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/26 13:11:14 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599); 
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}
/* 0.523599 is 30 degrees in radians, which makes 3d sense possible*/

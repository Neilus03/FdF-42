/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:39:03 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/27 16:17:53 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	find_height_range(t_vars *vars)
{
	int	i;
	int	j;
	int	current_height;

	i = 0;
	vars->min_height = vars->data[0][0];
	vars->max_height = vars->data[0][0];
	while (i < vars->rows)
	{
		j = 0;
		while (j < vars->cols)
		{
			current_height = vars->data[i][j];
			if (current_height < vars->min_height)
				vars->min_height = current_height;
			if (current_height > vars->max_height)
				vars->max_height = current_height;
			j++;
		}
		i++;
	}
}

int	generate_color(t_vars *vars, int height)
{
	int		red;
	int		green;
	int		blue;
	float	ratio;

	if (vars->max_height == vars->min_height)
		ratio = 1;
	else
		ratio = (float)(height - vars->min_height) \
		/ (vars->max_height - vars->min_height);
	red = ((vars->color_pairs[vars->color_pair_index].max >> 16) & 0xFF) \
		* ratio + ((vars->color_pairs[vars->color_pair_index].min >> 16) \
		& 0xFF) * (1 - ratio);
	green = ((vars->color_pairs[vars->color_pair_index].max >> 8) & 0xFF) \
		* ratio + ((vars->color_pairs[vars->color_pair_index].min >> 8) & \
		0xFF) * (1 - ratio);
	blue = (vars->color_pairs[vars->color_pair_index].max & 0xFF) * ratio + \
		(vars->color_pairs[vars->color_pair_index].min & 0xFF) * (1 - ratio);
	return ((red << 16) | (green << 8) | blue);
}

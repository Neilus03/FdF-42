/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:20:30 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/25 18:32:43 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "includes/fdf.h"

int	mouse_press(int button, int x, int y, t_vars *vars)
{
	if (button == 1) // Left mouse button
	{
		// Start rotation
		vars->rotating = 1;
		vars->last_x = x;
		vars->last_y = y;
	}
	else if (button == 2) // Right mouse button
	{
		// Start moving
		vars->moving = 1;
		vars->last_x = x;
		vars->last_y = y;
	}
	else if (button == 4 && vars->scale < MAX_SCALE) // Scroll up
		vars->scale *= 1.1;
	else if (button == 5 && vars->scale > MIN_SCALE) // Scroll down
		vars->scale /= 1.1;
	mlx_clear_window(vars->mlx, vars->win);
	redraw(vars);
	return (0);
}

int	mouse_release(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == 1) // Left mouse button
	{
		// Stop rotating
		vars->rotating = 0;
	}
	else if (button == 2) // Right mouse button
	{
		// Stop moving
		vars->moving = 0;
	}
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	if (vars->moving)
	{
		// Update offset based on mouse movement
		vars->x_offset += x - vars->last_x;
		vars->y_offset += y - vars->last_y;
		vars->last_x = x;
		vars->last_y = y;
	}
	else if (vars->rotating)
	{
		// Update rotation based on mouse movement
		vars->rotation_x += (y - vars->last_y) * ROTATION_SPEED;
		vars->rotation_y += (x - vars->last_x) * ROTATION_SPEED;
		vars->last_x = x;
		vars->last_y = y;
	}
	if (vars->moving || vars->rotating)
	{
		mlx_clear_window(vars->mlx, vars->win);
		redraw(vars);
	}
	return (0);
}

t_point rotate_point(t_point p, float rotation_x, float rotation_y)
{
    // Rotate around x-axis
    t_point p1;
    p1.x = p.x;
    p1.y = p.y * cos(rotation_x) - p.z * sin(rotation_x);
    p1.z = p.y * sin(rotation_x) + p.z * cos(rotation_x);

    // Rotate around y-axis
    t_point p2;
    p2.x = p1.x * cos(rotation_y) + p1.z * sin(rotation_y);
    p2.y = p1.y;
    p2.z = -p1.x * sin(rotation_y) + p1.z * cos(rotation_y);

    return p2;
}
*/
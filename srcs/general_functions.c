/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:09:52 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/25 19:17:12 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	close_window(void)
{
	exit(0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == MAIN_PAD_ESC)
		close_window();
	else if (keycode == MAIN_PAD_W)
		vars->color_index = (vars->color_index + 1) % \
		(sizeof(vars->colors) / sizeof(int));
	else if (keycode == ARROW_UP)
		vars->y_offset -= 10;
	else if (keycode == ARROW_DOWN)
		vars->y_offset += 10;
	else if (keycode == ARROW_LEFT)
		vars->x_offset -= 10;
	else if (keycode == ARROW_RIGHT)
		vars->x_offset += 10;
	mlx_clear_window(vars->mlx, vars->win);
	redraw(vars);
	return (0);
}

int	mouse_press(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == 4 && vars->scale < MAX_SCALE)
		vars->scale *= 1.1;
	else if (button == 5 && vars->scale > MIN_SCALE)
		vars->scale /= 1.1;
	mlx_clear_window(vars->mlx, vars->win);
	redraw(vars);
	return (0);
}

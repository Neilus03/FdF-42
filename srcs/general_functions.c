/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:09:52 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/27 13:47:48 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	close_window(void)
{
	exit(0);
	return ;
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
	printf("Mouse press function started\n");
	(void)x;
	(void)y;
	if (button == 4 && vars->scale < MAX_SCALE) 
	{
		printf("Zoom in: old scale = %f\n", vars->scale);
		vars->scale *= 1.1;
		printf("Zoom in: new scale = %f\n", vars->scale);
	}
	else if (button == 5 && vars->scale > MIN_SCALE) 
	{
		printf("Zoom out: old scale = %f\n", vars->scale);
		vars->scale /= 1.1;
		printf("Zoom out: new scale = %f\n", vars->scale);
	}
	mlx_clear_window(vars->mlx, vars->win);
	printf("About to redraw\n");
	redraw(vars);
	printf("Redraw completed\n");
	printf("Mouse press function ended\n");
	return (0);
}

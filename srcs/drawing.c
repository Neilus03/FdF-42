/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:03:40 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/27 15:54:23 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/*
//Bresenham's algortithm , it should work with zoom.
*/
void	initialize_line_draw(t_points *points, t_line_vars *line_vars)
{
	line_vars->abs_dx = abs(points->x2 - points->x1);
	line_vars->abs_dy = abs(points->y2 - points->y1);
	if (points->x1 < points->x2)
		line_vars->sx = 1;
	else
		line_vars->sx = -1;
	if (points->y1 < points->y2)
		line_vars->sy = 1;
	else
		line_vars->sy = -1;
	if (line_vars->abs_dx > line_vars->abs_dy)
		line_vars->err = line_vars->abs_dx / 2;
	else
		line_vars->err = -line_vars->abs_dy / 2;
}

void	draw_line(t_vars *vars, t_points *points, int color)
{
	t_line_vars	line_vars;

	initialize_line_draw(points, &line_vars);
	while (1)
	{
		mlx_pixel_put(vars->mlx, vars->win, points->x1, points->y1, color);
		if (points->x1 == points->x2 && points->y1 == points->y2)
			break ;
		if (2 * line_vars.err > -line_vars.abs_dx)
		{
			line_vars.err -= line_vars.abs_dy;
			points->x1 += line_vars.sx;
		}
		if (2 * line_vars.err < line_vars.abs_dy)
		{
			line_vars.err += line_vars.abs_dx;
			points->y1 += line_vars.sy;
		}
	}
}

void	handle_row_draw(t_vars *vars, t_points *points, int row, int col)
{
	float	norm_factor;

	norm_factor = WIN_SIZE / (max(vars->rows, vars->cols) * sqrt(2.0));
	points->x1 = (int)(((col - row) * cos(0.523599) * norm_factor + \
	vars->x_offset) * vars->scale);
	points->y1 = (int)(((-vars->data[row][col] + (row + col) * sin(0.523599)) \
	* norm_factor + vars->y_offset) * vars->scale);
	if (col < vars->cols - 1)
	{
		points->x2 = (int)((((col + 1) - row) * cos(0.523599) * norm_factor \
		+ vars->x_offset) * vars->scale);
		points->y2 = (int)(((-vars->data[row][col + 1] + (row + (col + 1)) \
		* sin(0.523599)) * norm_factor + vars->y_offset) * vars->scale);
		draw_line(vars, points, generate_color(vars, vars->data[row][col]));
	}
}

void	handle_column_draw(t_vars *vars, t_points *points, int row, int col)
{
	float	norm_factor;

	norm_factor = WIN_SIZE / (max(vars->rows, vars->cols) * sqrt(2.0));
	points->x1 = (int)(((col - row) * cos(0.523599) * norm_factor \
	+ vars->x_offset) * vars->scale);
	points->y1 = (int)(((-vars->data[row][col] + (row + col) \
	* sin(0.523599)) * norm_factor + vars->y_offset) * vars->scale);
	if (row < vars->rows - 1)
	{
		points->x2 = (int)(((col - (row + 1)) * cos(0.523599) * norm_factor \
		+ vars->x_offset) * vars->scale);
		points->y2 = (int)(((-vars->data[row + 1][col] + ((row + 1) + col) \
		* sin(0.523599)) * norm_factor + vars->y_offset) * vars->scale);
		draw_line(vars, points, generate_color(vars, vars->data[row][col]));
	}
}

int	redraw(t_vars *vars)
{
	int			row;
	int			col;
	t_points	points;

	row = 0;
	while (row < vars->rows)
	{
		col = 0;
		while (col < vars->cols)
		{
			handle_row_draw(vars, &points, row, col);
			handle_column_draw(vars, &points, row, col);
			col++;
		}
		row++;
	}
	return (0);
}

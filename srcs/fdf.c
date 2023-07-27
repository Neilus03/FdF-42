/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:21:38 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/27 15:15:04 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	initialize_vars(t_vars *vars)
{
	float	norm_factor;

	norm_factor = WIN_SIZE / (max(vars->rows, vars->cols) * sqrt(2.0));
	vars->colors[0] = RED;
	vars->colors[1] = GREEN;
	vars->colors[2] = BLUE;
	vars->colors[3] = YELLOW;
	vars->colors[4] = MAGENTA;
	vars->colors[5] = CYAN;
	vars->colors[6] = WHITE;
	vars->color_index = 0;
	vars->scale = 1;
	vars->x_offset = WIN_SIZE / 2;
	vars->y_offset = WIN_SIZE / 2;
}

void	read_data_and_initialize_vars(char *filename, t_vars *vars, \
										int *rows, int *cols)
{
	if (count_rows_and_cols(filename, rows, cols) == -1)
	{
		ft_printf("Error: Could not open file\n");
		exit(1);
	}
	vars->data = read_fdf_file(filename, *rows, *cols);
	if (vars->data == NULL)
	{
		ft_printf("Error: Could not read data from file\n");
		exit(1);
	}
	vars->rows = *rows;
	vars->cols = *cols;
	initialize_vars(vars);
}

void	initialize_and_run_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 800, 800, "FdF");
	redraw(vars);
	mlx_hook(vars->win, 2, 0, key_press, vars);
	mlx_mouse_hook(vars->win, mouse_press, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char **argv)
{
	char	*filename;
	t_vars	vars;
	int		rows;
	int		cols;

	if (argc != 2)
	{
		ft_printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	filename = argv[1];
	read_data_and_initialize_vars(filename, &vars, &rows, &cols);
	initialize_and_run_mlx(&vars);
	return (0);
}

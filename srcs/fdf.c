/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:21:38 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/27 14:12:50 by nde-la-f         ###   ########.fr       */
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
	vars->x_offset = WIN_SIZE / 2 - (vars->cols / 2.0) * norm_factor;
	vars->y_offset = WIN_SIZE / 2 - (vars->rows / 2.0) * norm_factor;
}

int	main(int argc, char **argv)
{
	char	*filename;
	t_vars	vars;
	int		rows;
	int		cols;
	int		i;
	int		j;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	filename = argv[1];
	if (count_rows_and_cols(filename, &rows, &cols) == -1)
	{
		printf("Error: Could not open file\n");
		return (1);
	}
	vars.data = read_fdf_file(filename, rows, cols);
	if (vars.data == NULL)
	{
		printf("Error: Could not read data from file\n");
		return (1);
	}
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			printf("%d ", vars.data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	vars.rows = rows;
	vars.cols = cols;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "FdF");
	initialize_vars(&vars);
	printf("scale: %f, x_offset: %d, y_offset: %d\n", vars.scale, vars.x_offset, vars.y_offset);
	redraw(&vars);
	mlx_hook(vars.win, 2, 0, key_press, &vars);
	mlx_mouse_hook(vars.win, mouse_press, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

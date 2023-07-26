/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:21:38 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/26 13:14:25 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/*
//REDRAW FOR DRAWING A LINE
int redraw(t_vars *vars)
{
    int x;
    int y;

    x = 0;
	y = 0;
	printf("scale: %f, x_offset: %d, y_offset: %d\n", vars->scale, vars->x_offset, vars->y_offset);

    while (y < 400)
    {
        x = (int)((y * vars->scale) + vars->x_offset);
        printf("x: %d, y: %d\n", x, y);
        mlx_pixel_put(vars->mlx, vars->win, x, (int)((y * vars->scale) + vars->y_offset), vars->colors[vars->color_index]);
        y++;
    }
    return (0);
}
*/
/*
//REDRAW FOR DRAWING A DOUGHNUT
int	redraw(t_vars *vars)
{
	int x, y;
	int r1 = 100; // inner radius
    int r2 = 150; // outer radius
    int cx = 200; // center x
    int cy = 200; // center y
	int plot_y;
	int plot_x;

    for (y = 0; y < 400; y++)
    {
        for (x = 0; x < 400; x++)
        {
            int dx = x - cx;
            int dy = y - cy;
            int dist = dx*dx + dy*dy; // distance squared
            if (dist > r1*r1 && dist < r2*r2)
            {
                plot_x = (int)((x * vars->scale) + vars->x_offset);
				plot_y = (int)((y * vars->scale) + vars->y_offset);
				mlx_pixel_put(vars->mlx, vars->win, plot_x, plot_y, \
				vars->colors[vars->color_index]);
			}
		}
	}
	return (0);
}
*/

/*
REDRAW USING ISOMETRIC TRANSFORMATION FUNCTION:

int	redraw(t_vars *vars)
{
	int	i;
	int	j;
	int	plot_x;
	int	plot_y;

	i = 0;
	while (i < vars->rows)
	{
		j = 0;
		while (j < vars->cols)
		{
			plot_x = j * vars->scale + vars->x_offset;
			plot_y = i * vars->scale + vars->y_offset;
			iso(&plot_x, &plot_y, vars->data[i][j]);
			mlx_pixel_put(vars->mlx, vars->win, plot_x, plot_y, \
			vars->colors[vars->color_index]);
			j++;
		}
		i++;
	}
	return (0);
}
*/

//REDRAW TRYING TO READ THE FDF 
int	redraw(t_vars *vars)
{
	int	i;
	int	j;
	int	plot_x;
	int	plot_y;

	i = 0;
	while (i < vars->rows)
	{
		j = 0;
		while (j < vars->cols)
		{
			plot_x = (int)((j - i) * cos(0.523599) * vars->scale \
			+ vars->x_offset);
			plot_y = (int)((-vars->data[i][j] + (i + j) \
			* sin(0.523599)) * vars->scale + vars->y_offset);
			mlx_pixel_put(vars->mlx, vars->win, plot_x, plot_y, \
			vars->colors[vars->color_index]);
			j++;
		}
		i++;
	}
	return (0);
}

void	initialize_vars(t_vars *vars)
{
	vars->colors[0] = RED;
	vars->colors[1] = GREEN;
	vars->colors[2] = BLUE;
	vars->colors[3] = YELLOW;
	vars->colors[4] = MAGENTA;
	vars->colors[5] = CYAN;
	vars->colors[6] = WHITE;
	vars->color_index = 0;
	vars->scale = 1.0;
	vars->x_offset = 0;
	vars->y_offset = 0;
}
/*
int	main(int argc, char **argv)
{
	char	*filename;
	t_vars	vars;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	filename = argv[1];
	write(1, filename, ft_strlen(filename));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "FdF");
	initialize_vars(&vars);
	redraw(&vars);
	mlx_hook(vars.win, 2, 0, key_press, &vars);
	mlx_mouse_hook(vars.win, mouse_press, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
*/
/*Main that is suposed to be able to read the
fdf file hopefully and luckily PORFAAVOR*/

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
	redraw(&vars);
	mlx_hook(vars.win, 2, 0, key_press, &vars);
	mlx_mouse_hook(vars.win, mouse_press, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

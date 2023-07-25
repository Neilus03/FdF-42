/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:21:38 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/25 15:30:11 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	g_colors[] = {RED, GREEN, BLUE, YELLOW, MAGENTA, CYAN, WHITE};

int	g_color_index = 0;

int	redraw(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < 800)
	{
		x = y;
		mlx_pixel_put(vars->mlx, vars->win, x, y, g_colors[g_color_index]);
		y++;
	}
	return (0);
}

int	close_program(t_vars *vars)
{
	(void)vars;
	exit(0);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == MAIN_PAD_ESC)
	{
		close_program(vars);
	}
	else if (keycode == MAIN_PAD_W)
	{
		g_color_index = (g_color_index + 1) % (sizeof(g_colors) / sizeof(int));
		mlx_clear_window(vars->mlx, vars->win);
		redraw(vars);
	}
	return (0);
}

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
	vars.win = mlx_new_window(vars.mlx, 800, 800, "Hello World");
	redraw(&vars);
	mlx_hook(vars.win, 17, 0, close_program, &vars);
	mlx_hook(vars.win, 2, 0, key_press, &vars);
	mlx_loop(vars.mlx);
}

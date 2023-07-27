/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:25:11 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/27 16:12:36 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "colors.h"
# include "keycodes.h"

# define MAX_SCALE 100.0
# define MIN_SCALE 0.01
# define WIN_SIZE 800

/*---------------------------------------------------#
#              Structure definitions                 #
#---------------------------------------------------*/
/*
This structure contains the minimum and maximum values of the color space
*/
typedef struct s_color_pair {
	int	min;
	int	max;
}	t_color_pair;

/*
This structure contains the main variables about the window, map data
colors, etc. It is passed as a parameter to the functions that need it.
*/
typedef struct s_vars {
	void			*mlx;
	void			*win;
	int				x_offset;
	int				y_offset;
	float			scale;
	int				**data;
	int				rows;
	int				cols;
	int				min_height;
	int				max_height;
	int				color_pair_index;
	t_color_pair	color_pairs[4];
}					t_vars;
/*
This structure contains the coordinates of the two points that 
define a line. Is used in the draw_line function.
*/
typedef struct s_points {
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}		t_points;

/*
This structure contains the variables used in the draw_line function.
I built it because if not, I had to pass to many arguments to the 
initialize_line_draw function which is not allowed by norminette
*/
typedef struct s_line_vars {
	int	sx;
	int	sy;
	int	err;
	int	abs_dx;
	int	abs_dy;
}		t_line_vars;

/*---------------------------------------------------#
#              Function prototypes                   #
#---------------------------------------------------*/

// READING THE FDF FILE:
int		count_rows_and_cols(char *filename, int *row, int *col);
int		**read_fdf_file(char *filename, int row, int col);

// GENERAL FUNCTIONS:
int		close_window(t_vars *vars);
void	initialize_vars(t_vars *vars);
void	initialize_and_run_mlx(t_vars *vars);
void	read_data_and_initialize_vars(char *filename, \
									t_vars *vars, int *rows, int *cols);
// DRAWING FUNCTIONS:
void	handle_column_draw(t_vars *vars, t_points *points, int row, int col);
void	handle_row_draw(t_vars *vars, t_points *points, int row, int col);
void	draw_line(t_vars *vars, t_points *points, int color);
int		redraw(t_vars *vars);

// COLORING FUNCTIONS:
int		generate_color(t_vars *vars, int height);
void	find_height_range(t_vars *vars);

//KEYBOARD OPERATIONS:
int		key_press(int keycode, t_vars *vars);

// MOUSE OPERATIONS:
int		mouse_press(int button, int x, int y, t_vars *vars);

//AUXILIARY FUNCTIONS:
int		abs(int n);
int		max(int a, int b);

#endif
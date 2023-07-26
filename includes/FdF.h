/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:25:11 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/26 11:46:55 by nde-la-f         ###   ########.fr       */
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

# define MAX_SCALE 10.0
# define MIN_SCALE 0.1

/*---------------------------------------------------#
#              Structure definitions                 #
#---------------------------------------------------*/

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		x_offset;
	int		y_offset;
	int		colors[7];
	int		color_index;
	float	scale;
	int		**data;
	int		rows;
	int		cols;
}			t_vars;

/*---------------------------------------------------#
#              Function prototypes                   #
#---------------------------------------------------*/

// READING THE FDF FILE:

int		count_rows_and_cols(char *filename, int *row, int *col);
int		**read_fdf_file(char *filename, int row, int col);
// GENERAL FUNCTIONS:
void	close_window(void);
int		redraw(t_vars *vars);
void	initialize_vars(t_vars *vars);

//KEYBOARD OPERATIONS:
int		key_press(int keycode, t_vars *vars);

// MOUSE OPERATIONS:
int		mouse_press(int button, int x, int y, t_vars *vars);
//int	mouse_release(int button, int x, int y, t_vars *vars);
//int	mouse_move(int x, int y, t_vars *vars);

#endif
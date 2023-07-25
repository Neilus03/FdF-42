/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:25:11 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/25 14:23:50 by nde-la-f         ###   ########.fr       */
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
# include "ft_printf/ft_printf.h"
# include "colors.h"
# include "keycodes.h"

/*---------------------------------------------------#
#              Structure definitions                 #
#---------------------------------------------------*/

typedef struct s_vars 
{
	void	*mlx;
	void	*win;
	int		color;
}			t_vars;

/*---------------------------------------------------#
#              Function prototypes                   #
#---------------------------------------------------*/

// GENERAL FUNCTIONS:
int	close_window(t_vars *vars);

#endif
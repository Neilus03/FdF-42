/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:14:13 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/25 20:13:07 by nde-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	count_rows_and_cols(char *filename, int *row, int *col)
{
	int		fd;
	char	*line;
	char	**split_line;

	*row = 0;
	*col = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*row == 0)
		{
			split_line = ft_split(line, ' ');
			while (split_line[*col])
				(*col)++;
			free(split_line);
		}
		(*row)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static int	**allocate_data_matrix(int row, int col)
{
	int	**data;
	int	i;

	data = (int **)malloc(sizeof(int *) * row);
	if (!data)
		return (NULL);
	i = 0;
	while (i < row)
	{
		data[i] = (int *)malloc(sizeof(int) * col);
		if (!data[i])
		{
			j = 0;
			while (j < i)
			{
				free(data[j]);
				j++;
			}
			free(data);
			return (NULL);
		}
		i++;
	}
	return (data);
}

static void	free_data_matrix(int **data, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(data[i]);
		i++;
	}
	free(data);
}

static int	read_fdf_data(int fd, int **data, int row, int col)
{
	char	*line;
	char	**split_line;
	int		rows_read;
	int		cols_read;

	rows_read = 0;
	while (get_next_line(fd) > 0)
	{
		line = get_next_line(fd);
		split_line = ft_split(line, ' ');
		free(line);
		cols_read = 0;
		while (cols_read < col)
		{
			data[rows_read][cols_read] = ft_atoi(split_line[cols_read]);
			cols_read++;
		}
		free_split(split_line);
		rows_read++;
	}
	return (rows_read);
}

int	**read_fdf_file(char *filename, int row, int col)
{
	int	fd;
	int	**data;
	int	rows_read;

	data = allocate_data_matrix(row, col);
	if (!data)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free_data_matrix(data, row);
		return (NULL);
	}
	rows_read = read_fdf_data(fd, data, row, col);
	if (rows_read < row)
	{
		free_data_matrix(data, row);
		return (NULL);
	}
	close(fd);
	return (data);
}

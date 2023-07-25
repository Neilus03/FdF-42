/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-la-f <nde-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:14:13 by nde-la-f          #+#    #+#             */
/*   Updated: 2023/07/25 19:59:46 by nde-la-f         ###   ########.fr       */
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

static int	**allocate_data_matrix(int row, int col)
{
	int	**data;
	int	i;

	data = (int **)malloc(sizeof(int *) * row);
	if (!data)
		retun NULL;
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

int	**read_fdf_file(char *filename, int row, int col)
{
	int		fd;
	char	*line;
	char	**split_line;
	int		**data;
	int		i;
	int		j;

	data = allocate_data_matrix(row, col);
	if (!data)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free_data_matrix(data, row);
		return (NULL);
	}
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		split_line = ft_split(line, ' ');
		free(line);
		j = 0;
		while (j < col)
		{
			data[i][j] = ft_atoi(split_line[j]);
			j++;
		}
		free_split(split_line);
		i++;
	}
	close(fd);
	return (data);
}

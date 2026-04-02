/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:53:15 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/02 19:25:37 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"
#include "src/libft/printfft.h"
#include "src/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

static size_t	fdf_count_valid_cells(char **cells)
{
	size_t	i;
	size_t	ret;
	char	**tmp;

	i = 0;
	ret = 0;
	while (cells[i])
	{
		if (*(cells[i]))
			++ret;
		++i;
	}
	return (ret);
}

static void	fdf_sanitize_cells(char ***cells)
{
	size_t	i;
	size_t	j;
	char	**tmp;
	char	**cell_data;

	cell_data = *cells;
	i = 0;
	tmp = ft_calloc(fdf_count_valid_cells(cell_data) + 1, sizeof(char *));
	j = 0;
	while (cell_data[i])
	{
		if (*(cell_data[i]))
		{
			tmp[j] = cell_data[i];
			++j;
		}
		++i;
	}
	free (*cells);
	*cells = tmp;
}

static int	fdf_extract_raw(char *filename, t_fdf *fdf_data)
{
	size_t	i;
	size_t	size;
	int		fd;
	char	*line;
	char	**cells;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERROR_READ_FROM_FILE);
	line = ft_gnl(fd);
	while (line)
	{
		++fdf_data->height;
		cells = ft_split(line, ' ');
		if (fdf_data->width)
		fdf_sanitize_cells(&cells);
		while (cells[i])
		{
			if (cells[i])
			{
				++fdf_data
			}
			
		}
		
		free(line);
		line = ft_gnl(fd);
	}
}

static int	fdf_from_file(char *filename, t_fdf *fdf_data)
{
	size_t	i;
	size_t	size;
	int		fd;
	char	*line;
	char	**cells;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERROR_READ_FROM_FILE);
	line = ft_gnl(fd);
	while (line)
	{
		++fdf_data->width;
		cells = ft_split(line, ' ');
		free(line);
		line = ft_gnl(fd);
	}


	i = 0;
	size = fdf_data->width * fdf_data->height;
	fdf_data->data = ft_calloc(size, sizeof(int));
	if (!fdf_data->data)
		return (ERROR_MALLOC_FDF_DATA);
	while (i < fdf_data->height * fdf_data->width)
	{
		fdf_data->data[i] = 10.f * sinf((i % fdf_data->height)/ 3.14f) + cosf((i / fdf_data->width)/ 3.14f) * 10.f - 10;
		++i;
	}
	fdf_print_data(fdf_data);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*filename;
	t_fdf	fdf_data;
	int		err_ret;

	err_ret = 0;
	if (argc < 2)
		ft_errorf("No file given as argument.\n");
	if (argc > 2)
		ft_errorf("Too many arguments.\n");
	if (argc != 2)
		return (1);
	filename = argv[1];
	ft_printf("USING FILE %s\n", filename);
	err_ret = fdf_from_file(filename, &fdf_data);
	if (!err_ret)
		err_ret = fdf_exec(&fdf_data);
	fdf_err_message(err_ret);
	return (err_ret);
}

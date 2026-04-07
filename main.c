/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:53:15 by kblanche          #+#    #+#             */
/*   Updated: 2026/04/07 19:09:10 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_utils.h"
#include "src/libft/printfft.h"
#include "src/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

static int	fdf_count_lines(char *filename, t_fdf *fdf)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERROR_READ_FROM_FILE);
	fdf->height = ft_count_lines(fd);
	if (fdf->height == 0)
		return (ERROR_FILE_EMPTY);
	return (0);
}

static size_t	fdf_count_valid_cells(const char *line)
{
	size_t	i;
	size_t	ret;
	char	**cells;

	i = 0;
	ret = 0;
	cells = ft_split(line, ' ');
	while (cells[i])
	{
		if (*(cells[i]))
			++ret;
		free(cells[i]);
		++i;
	}
	free(cells);
	return (ret);
}

static int	fdf_extract_cells(const char *line, t_fdf *fdf)
{
	int				err_code;
	char			**cells;
	size_t			i;
	static size_t	j = 0;

	i = 0;
	err_code = 0;
	if (fdf->width != fdf_count_valid_cells(line))
		return (ERROR_MALFORMED_FDF);
	cells = ft_split(line, ' ');
	if (!cells)
		return (ERROR_MALLOC_EXTRACT_CELLS);
	while (cells[i])
	{
		if (*(cells[i]))
		{
			if (j < fdf->height * fdf->width)
				fdf->data[j] = ft_atoi(cells[i]);
			++j;
		}
		free(cells[i]);
		++i;
	}
	free(cells);
	return (err_code);
}

static int	fdf_from_file(char *filename, t_fdf *fdf)
{
	int		err_code;
	int		fd;
	char	*line;

	fdf->width = 0;
	err_code = fdf_count_lines(filename, fdf);
	if (err_code)
		return (err_code);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERROR_READ_FROM_FILE);
	line = ft_gnl(fd);
	fdf->width = fdf_count_valid_cells(line);
	fdf->data = ft_calloc(fdf->width * fdf->height, sizeof(int));
	if (!fdf->data)
		err_code = ERROR_MALLOC_FDF_DATA;
	while (!err_code && line)
	{
		err_code = fdf_extract_cells(line, fdf);
		free(line);
		line = ft_gnl(fd);
	}
	free(line);
	close(fd);
	return (err_code);
}

int	main(int argc, char **argv)
{
	char	*filename;
	t_fdf	fdf;
	int		err_ret;

	fdf.data = NULL;
	err_ret = 0;
	if (argc < 2)
		ft_errorf("No file given as argument.\n");
	if (argc > 2)
		ft_errorf("Too many arguments.\n");
	if (argc != 2)
		return (1);
	filename = argv[1];
	err_ret = fdf_from_file(filename, &fdf);
	if (!err_ret)
		err_ret = fdf_exec(&fdf);
	if (fdf.data)
		free(fdf.data);
	fdf_err_message(err_ret);
	return (err_ret);
}

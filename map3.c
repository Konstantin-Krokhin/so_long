/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:40:26 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/10/05 18:02:03 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_maps(t_global **globals)
{
	(*globals)->map = malloc(sizeof(char *) * ((*globals)->map_num_rows + 1));
	if (!((*globals)->map))
		exit(0);
	(*globals)->map_copy = malloc(sizeof(char *) * ((*globals)->map_num_rows + 1));
	if (!((*globals)->map_copy))
		exit(0);
}

void	read_map(t_global **globals, char *map_file)
{
	int		fd;
	int		rows_number;
	char	*line;

	rows_number = 0;
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit (0);
	free (line);
	(*globals)->map_num_cols = ft_strlen(line) - 1;
	while (line != 0)
	{
		line = get_next_line(fd);
		rows_number++;
		free(line);
	}
	(*globals)->map_num_rows = rows_number;
	close(fd);
	malloc_maps(globals);
}

void	map_fill(t_global **globals, char *map_file)
{
	int		fd;
	char	*line;
	int		row_index;
	char	*line2;

	row_index = 1;
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	line2 = ft_strdup(line);
	(*globals)->map[0] = line;
	(*globals)->map_copy[0] = line2;
	while (line != 0)
	{
		line = get_next_line(fd);
		if (line)
		{
			line2 = ft_strdup(line);
			(*globals)->map_copy[row_index] = line2;
		}
		(*globals)->map[row_index] = line;
		row_index++;
	}
	close (fd);
}
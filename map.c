/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:11:50 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/09/23 17:52:14 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errno.h"

void map_check(char	*buffer, int str_len)
{
	// Error check for not wall closed on the map
	if (buffer[0] != '1' || buffer[str_len-2] != '1')
	{
		perror("Invalid map border!");
		exit(0);
	}
	// Check for at least 1 start and 1 exit point and 1 collectible, if more start/exit points -> err_msg & quit
	// Check if there is a valid path in the map!
}

void map_check_top_bottom(char	*buffer, int x)
{
	while (x >= 0)
	{
		if (buffer[x] != '1')
		{
			perror("Invalid map top/bottom!");
			exit(0);
		}
		x--;
	}
}

void draw_map_from_berfile(void	**mlx_ptr, void	**win_ptr, char *argv)
{
	char	*buffer = "";
	char	*tilename = "";
	char	*tiletype = "";
	void	*tile = "";
	int		str_len;
	int		fd, x, y;
	int		img_width;
	int		img_height;

	y = 0;
	fd = open(argv, O_RDONLY);
	while (buffer != NULL)
	{
		x = 0;
		buffer = get_next_line(fd);
		if (!buffer)
			break;
		str_len = ft_strlen(buffer);
		if (y == 0)
			map_check_top_bottom(buffer, str_len - 2);
		else
			map_check(buffer, str_len);
		while (buffer[x] != '\n' && buffer[x] != '\0')
		{
			if (buffer[x] == '1')
				tilename = "Pit-Forest.xpm";
			else if (buffer[x] == '0')
				tilename = "Background.xpm";
			else if (buffer[x] == 'P') // Adding character
				tilename = "char.xpm";
			else if (buffer[x] == 'C')
				tilename = "Collactible.xpm";
			else if (buffer[x] == 'E')
				tilename = "Exit.xpm";
			tiletype = ft_strjoin("./assets/Fantasy/Background/", tilename);
			tile = mlx_xpm_file_to_image(*mlx_ptr, tiletype, &img_width, &img_height);
			mlx_put_image_to_window(*mlx_ptr, *win_ptr, tile, (64 * x), (64 * y));
			free(tiletype);
			free(tile);
			x++;
			if (x >= str_len)
				break;
		}
		y++;
		if (buffer[x] == '\0')
			map_check_top_bottom(buffer, str_len - 1);
		if (buffer)
			free(buffer);
	}
	free(buffer);
}
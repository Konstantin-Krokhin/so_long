/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:11:50 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/10/05 18:22:38 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_check_line(char *buffer, t_global **globals, int str_len)
{
	int i;

	i = -1;
	// Error check for not wall closed on the map
	if (buffer[0] != '1' || buffer[str_len] != '1')
		(*globals)->border_hole = true;
	
	// Check for at least 1 start and 1 exit point and 1 collectible or not allowed characters
	while (++i <= str_len)
	{
		if (buffer[i] == 'P')
		{
			if ((*globals)->start_exists == false)
				(*globals)->start_exists = true;
			else if ((*globals)->start_exists == true)
				(*globals)->more_than_one_player_exists = true;
		}
		else if (buffer[i] == 'E')
		{
			if ((*globals)->exit_exists == false)
				(*globals)->exit_exists = true;
		}
		else if (buffer[i] == 'C')
		{
			if ((*globals)->collectible_exists == false)
				(*globals)->collectible_exists = true;
		}	
		else if (buffer[i] != '1' && buffer[i] != '0' && buffer[i] != '\n' && buffer[i] != '\0')
		{
			ft_printf("Not allowed character!\n");
			exit(0);
		}
	}
	
	// Check if there is a valid path in the map!
}

void check_for_atleast_one_exit_collectible_player(t_global **globals)
{
	int ifMistake;

	ifMistake = 0;
	if ((*globals)->start_exists == false && ++ifMistake)
		ft_printf("One player start position should be!\n");
	if ((*globals)->more_than_one_player_exists == true && ++ifMistake)
		ft_printf("Only one player start position is allowed!\n");
	if ((*globals)->exit_exists == false && ++ifMistake)
		ft_printf("At least one exit should be!\n");
	if ((*globals)->collectible_exists == false && ++ifMistake)
		ft_printf("At least one collectible should be!\n");
	if ((*globals)->border_hole == true && ++ifMistake)
		ft_printf("Invalid map left/right border!\n");
	if ((*globals)->top_bottom_hole == true && ++ifMistake)
		ft_printf("Invalid map top/bottom border!\n");
	if (ifMistake > 0)
		exit(0);
}

void map_check_top_bottom(t_global **globals, char *buffer, int x)
{
	while (x >= 0)
	{
		if (buffer[x] != '1')
			(*globals)->top_bottom_hole = true;
		x--;
	}
}

void draw_map_from_berfile(void	**mlx_ptr, void	**win_ptr, char *argv)
{
	char	*buffer = "";
	char	*tilename = "";
	char	*tiletype = "";
	void	*tile = "";
	int		str_len = 0;
	int		fd, x, y;
	int		img_width;
	int		img_height;
	t_global	*globals;

	globals = ft_calloc(sizeof(t_global), 1);
	y = 0;
	if (valid_extension(argv))
		return ;
	fd = open(argv, O_RDONLY);
	read_map(&globals, argv);
	map_fill(&globals, argv);
	if (is_rectangular(&globals) == 1)
		{
		
		exit(0);}
	while (buffer != NULL)
	{
		if (!check_buf(&x, &buffer, fd, y))
			break;
		str_len = ft_strlen(buffer);
		if (y == 0)
		{
			globals->old_strlen = str_len - 2;
			map_check_top_bottom(&globals, buffer, str_len - 2);
		}
		else
			map_check_line(buffer, &globals, str_len - 2);
		while (buffer[x] != '\n' && buffer[x] != '\0')
		{
			tiletype = ft_strjoin("./assets/Fantasy/Background/", return_tile(buffer, tilename, x));
			tile = mlx_xpm_file_to_image(*mlx_ptr, tiletype, &img_width, &img_height);
			mlx_put_image_to_window(*mlx_ptr, *win_ptr, tile, (64 * x), (64 * y));
			free(tiletype);
			free(tile);
			x++;
			if (x >= str_len)
				break;
		}
		y++;
		if (buffer[x] == '\0' && buffer[x-1] == '\n')
			map_check_top_bottom(&globals, buffer, str_len - 2);
		else if (buffer[x] == '\0' && buffer[x-1] == '1')
			map_check_top_bottom(&globals, buffer, str_len - 1);
		if (buffer)
			free(buffer);
	}
	free(buffer);
	check_for_atleast_one_exit_collectible_player(&globals);
}
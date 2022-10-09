/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:11:45 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/10/09 15:37:09 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int close_window(t_global *game)
{
	mlx_destroy_image(game->mlx, game->image);
	mlx_destroy_window(game->mlx, game->window);
	// if (game->image)
	// 	free(game->image);
	// if (game->window)
	// 	free(game->window);
	// if (game->mlx)
	// 	free(game->mlx);
	// if (game->map)
	// 	free(game->map);
	// if (game->map_copy)
	// 	free(game->map_copy);
	// if (game)
	// 	free(game);
	ft_printf("game exited");
	exit(0);
	return(1);
}

char	*display_tile(t_global *game, int j, int i)
{
	char	*path_tile;

	path_tile = NULL;
	if (game->map[j][i] == '1')
		path_tile = "./assets/Fantasy/Background/Pit-Forest.xpm";
	else if (game->map[j][i] == '0')
		path_tile = "./assets/Fantasy/Background/Background.xpm";
	else if (game->map[j][i] == 'P')
		path_tile = "./assets/Fantasy/Background/char.xpm";
	else if (game->map[j][i] == 'C')
		path_tile = "./assets/Fantasy/Background/Collactible.xpm";
	else if (game->map[j][i] == 'E')
		path_tile = "./assets/Fantasy/Background/Exit.xpm";
	return(path_tile);
}

void	display_map(t_global *game)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	*path_tile;

	j = 0;
	y = 0;
	// mlx_destroy_image(game->mlx, game->image);
	// mlx_clear_window(game->mlx, game->window);
	while (j < game->map_num_rows)
	{
		i = 0;
		x = 0;
		while ((game->map[j][i] != '\n') && (game->map[j][i] != '\0'))
		{
			path_tile = display_tile(game, j, i);
			game->image = mlx_xpm_file_to_image(game->mlx, path_tile, \
			&game->tile_dimension, &game->tile_dimension);
			mlx_put_image_to_window(game->mlx, game->window, game->image, x, y);
			x = x + game->tile_dimension;
			i++;
		}
		j++;
		y = y + game->tile_dimension;
	}
}

int main(int argc, char **argv)
{
	t_global	*game = ft_calloc(sizeof(t_global), 1);

	if (argc != 2)
		return (0);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1700, 1250, "mlx LINK START!");
	game->tile_dimension = 64;
	draw_map_from_berfile(game, argv[1]); //Drawing the maze
	
	// if (game == NULL)
	// 	close_window();
	//game->window = win_ptr;
	//game->mlx = mlx_ptr;
	mlx_hook(game->window, 17, 0, close_window, game);
	//mlx_hook(game->window, 2, 0, close_window, game);
	mlx_key_hook(game->window, key_hooks_handling, game);
	mlx_loop(game->mlx);
}
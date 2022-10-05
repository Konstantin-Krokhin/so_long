/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:11:45 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/10/04 16:32:03 by kokrokhi         ###   ########.fr       */
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

void put_player()
{

}

int close_window()
{
	exit(0); // Might be segfaulting when not freeing using only exit
	return(1);
}

int main(int argc, char **argv)
{
	void		*mlx_ptr = NULL;
	void		*win_ptr = NULL;

	if (argc != 2)
		return (0);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1700, 1250, "mlx LINK START!");
	draw_map_from_berfile(&mlx_ptr, &win_ptr, argv[1]); //Drawing the maze
	mlx_hook(win_ptr, 17, 0, close_window, 0);
	mlx_hook(win_ptr, 2, 0, close_window, 0);
	mlx_loop(mlx_ptr);
}
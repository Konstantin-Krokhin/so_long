/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:11:45 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/09/16 17:23:12 by kokrokhi         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	void	*mlx_ptr = NULL;
	void	*win_ptr = NULL;

	if (argc != 2)
		return (0);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1700, 1250, "mlx LINK START!");
	draw_map_from_berfile(&mlx_ptr, &win_ptr, argv[1]); //Drawing the maze
	mlx_loop(mlx_ptr);
}
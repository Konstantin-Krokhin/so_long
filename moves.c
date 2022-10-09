/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:05:54 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/10/09 13:48:20 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_global *game)
{
	if (game->map[game->player_x + 1][game->player_y] == '1' || \
	(game->map[game->player_x + 1][game->player_y] == 'E' && \
game->collectibles_count != 0))
		return ;
	if (game->map[game->player_x + 1][game->player_y] == 'C')
		game->collectibles_count--;
	if (game->map[game->player_x + 1][game->player_y] == 'E' && \
game->collectibles_count == 0)
	{
		ft_printf("You won! The window will close in a second\n");
		close_window(game);
	}
	game->map[game->player_x][game->player_y] = '0';
	game->map[game->player_x + 1][game->player_y] = 'P';
	game->player_x = game->player_x + 1;
	display_map(game);
	game->moves_count++;
	ft_printf("Number of moves: %d \n", game->moves_count);
}

void	move_up(t_global *game)
{
	if (game->map[game->player_x - 1][game->player_y] == '1' || \
	(game->map[game->player_x - 1][game->player_y] == 'E' && \
game->collectibles_count != 0))
		return ;
	if (game->map[game->player_x - 1][game->player_y] == 'C')
		game->collectibles_count--;
	if (game->map[game->player_x - 1][game->player_y] == 'E' && \
game->collectibles_count == 0)
	{
		ft_printf("You won! The window will close in a second\n");
		close_window(game);
	}
	game->map[game->player_x][game->player_y] = '0';
	game->map[game->player_x - 1][game->player_y] = 'P';
	game->player_x = game->player_x - 1;
	display_map(game);
	game->moves_count++;
	ft_printf("Number of moves: %d \n", game->moves_count);
}

void	move_left(t_global *game)
{
	if (game->map[game->player_x][game->player_y - 1] == '1' || \
	(game->map[game->player_x][game->player_y - 1] == 'E' && \
game->collectibles_count != 0))
		return ;
	if (game->map[game->player_x][game->player_y - 1] == 'C')
		game->collectibles_count--;
	if (game->map[game->player_x][game->player_y - 1] == 'E' && \
game->collectibles_count == 0)
	{
		ft_printf("You won! The window will close in a second\n");
		close_window(game);
	}
	game->map[game->player_x][game->player_y] = '0';
	game->map[game->player_x][game->player_y - 1] = 'P';
	game->player_y = game->player_y - 1;
	display_map(game);
	game->moves_count++;
	ft_printf("Number of moves: %d \n", game->moves_count);
}

void	move_right(t_global *game)
{
	if (game->map[game->player_x][game->player_y + 1] == '1' || \
	(game->map[game->player_x][game->player_y + 1] == 'E' && \
game->collectibles_count != 0))
		return ;
	if (game->map[game->player_x][game->player_y + 1] == 'C')
		game->collectibles_count--;
	if (game->map[game->player_x][game->player_y + 1] == 'E' && \
game->collectibles_count == 0)
	{
		ft_printf("You won! The window will close in a second\n");
		close_window(game);
	}
	game->map[game->player_x][game->player_y] = '0';
	game->map[game->player_x][game->player_y + 1] = 'P';
	game->player_y = game->player_y + 1;
	display_map(game);
	game->moves_count++;
	ft_printf("Number of moves: %d \n", game->moves_count);
}

int	key_hooks_handling(int keycode, t_global *game)
{
	if (keycode == 53)
		close_window(game);
	if (keycode == 13)
		move_up(game);
	if (keycode == 1)
		move_down(game);
	if (keycode == 0)
		move_left(game);
	if (keycode == 2)
		move_right(game);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:11:40 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/10/05 18:22:17 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "unistd.h"
#include "mlx/mlx.h"
#include <fcntl.h>
#include "Libft/get_next_line.h"
#include "Libft/libft.h"
#include "Libft/ft_printf.h"
#include "stdio.h"

typedef struct s_global
{
	bool start_exists;
	bool exit_exists;
	bool collectible_exists;
	bool border_hole;
	bool more_than_one_player_exists;
	bool top_bottom_hole;
	int	old_strlen;
	int		map_num_cols;
	int		map_num_rows;
	char	**map;
	char	**map_copy;
} t_global;

void draw_map_from_berfile(void	**mlx_ptr, void	**win_ptr, char *argv);
void	map_fill(t_global **globals, char *map_file);
void	read_map(t_global **globals, char *map_file);
int	is_rectangular(t_global **game);
int	valid_extension(char *path);
char *return_tile(char *buffer, char *tilename, int x);
bool check_buf(int *x, char **buffer, int fd, int y);
// void check_if_rectangle(char *buffer, t_global **globals, int str_len);

#endif
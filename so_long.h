/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:11:40 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/09/22 19:25:30 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "unistd.h"
#include "mlx/mlx.h"
#include <fcntl.h>
#include "Libft/get_next_line.h"
#include "Libft/libft.h"
#include "stdio.h"

void draw_map_from_berfile(void	**mlx_ptr, void	**win_ptr, char *argv);

#endif
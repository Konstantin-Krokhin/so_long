/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:46:43 by kokrokhi          #+#    #+#             */
/*   Updated: 2022/10/05 18:21:14 by kokrokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_extension(char *path)
{
	int	length;

	length = ft_strlen(path);
	if (ft_strnstr(path + length - 4, ".ber", 4) == 0)
	{
		ft_printf("Wrong file extension (must be .ber) !\n");
		exit (0);
		return (1);
	}
	return (0);
}

char *return_tile(char *buffer, char *tilename, int x)
{
	if (buffer[x] == '1')
		tilename = "Pit-Forest.xpm";
	else if (buffer[x] == '0')
		tilename = "Background.xpm";
	else if (buffer[x] == 'P')
		tilename = "char.xpm";
	else if (buffer[x] == 'C')
		tilename = "Collactible.xpm";
	else if (buffer[x] == 'E')
		tilename = "Exit.xpm";
	return(tilename);
}

bool check_buf(int *x, char **buffer, int fd, int y)
{
	*x = 0;
	*buffer = get_next_line(fd);
	if (!(*buffer))
	{
		if (y == 0)
		{
			ft_printf("No such file!\n");
			exit(0);
		}
		return (false);
	}
	return (true);
}

int	is_rectangular(t_global **game)
{
	int	i;

	i = 1;
	while (i < (*game)->map_num_rows)
	{
		if (ft_strlen((*game)->map[0]) != ft_strlen((*game)->map[i]))
		{
			ft_printf("Map not rectangular \n");
			return (1);
		}
		i++;
	}
	return (0);
}

// void check_if_rectangle(char *buffer, t_global **globals, int str_len)
// {
// 	ft_printf("\n[%c]", buffer[str_len+1]);
// 	if (buffer[str_len+1] == '\0')
// 		(*globals)->old_strlen -= 1;
// 	ft_printf("\noldstrlen---- %d ---", (*globals)->old_strlen);
// 	ft_printf("\nstrlen---- %d ---", str_len);
// 	if (((*globals)->old_strlen) != str_len)
// 		ft_printf("%d %d %s", (*globals)->old_strlen, str_len, "ERRO!\n");
// }

// void is_rectangular(int *old_strlen, int *str_len, char *buffer, int y)
// {
// 	if (y == 0)
// 		*old_strlen = ft_strlen(buffer);
// 	*
// 	if (*old_strlen != *str_len)
// 	{
// 		ft_printf("The map is not rectangular!");
// 		exit(0);
// 	}
// 	*old_strlen = *str_len;
// }
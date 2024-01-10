/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:08:33 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/09 15:12:33 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include "GNL/get_next_line.h"
#include "Libft/libft.h"
#include <stdio.h>

void	put_bg(char **map, t_texture *texture, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					texture->bg, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	put_walls(char **map, t_texture *texture, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					texture->wall, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	put_collectibles(char **map, t_texture *texture, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					texture->collectible, j * 64, i * 64);
				data->collectibles_left++;
			}
			j++;
		}
		i++;
	}
}

void	put_exit(char **map, t_texture *texture, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					texture->exit, j * 64, i * 64);
				data->door_x = j * 64;
				data->door_y = i * 64;
			}
			j++;
		}
		i++;
	}
}

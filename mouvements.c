/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:57:35 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/16 15:38:09 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_data *data)
{
	if (data->map.map[data->player->y / 64 - 1][data->player->x / 64] == '1' ||
	(data->map.map[data->player->y / 64 - 1][data->player->x / 64] == 'E'
	&& data->collectibles_left != 0))
		return (0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture->bg,
		data->player->x, data->player->y);
	data->player->y -= 64;
	data->steps++;
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'C')
	{
		data->collectibles_left--;
		data->map.map[data->player->y / 64][data->player->x / 64] = '0';
	}
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'E')
	{
		if (data->collectibles_left == 0)
			exit_game(data);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->texture->player_up, data->player->x, data->player->y);
	return (0);
}

int	move_down(t_data *data)
{
	if (data->map.map[data->player->y / 64 + 1][data->player->x / 64] == '1' ||
	(data->map.map[data->player->y / 64 + 1][data->player->x / 64] == 'E'
		&& data->collectibles_left != 0))
		return (0);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->texture->bg, data->player->x, data->player->y);
	data->player->y += 64;
	data->steps++;
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'C')
	{
		data->collectibles_left--;
		data->map.map[data->player->y / 64][data->player->x / 64] = '0';
	}
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'E')
	{
		if (data->collectibles_left == 0)
			exit_game(data);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->texture->player_down, data->player->x, data->player->y);
	return (0);
}

int	move_left(t_data *data)
{
	if (data->map.map[data->player->y / 64][data->player->x / 64 - 1] == '1' ||
	(data->map.map[data->player->y / 64][data->player->x / 64 - 1] == 'E'
	&& data->collectibles_left != 0))
		return (0);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->texture->bg, data->player->x, data->player->y);
	data->player->x -= 64;
	data->steps++;
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'C')
	{
		data->collectibles_left--;
		data->map.map[data->player->y / 64][data->player->x / 64] = '0';
	}
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'E')
	{
		if (data->collectibles_left == 0)
			exit_game(data);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->texture->player_left, data->player->x, data->player->y);
	return (0);
}

int	move_right(t_data *data)
{
	if (data->map.map[data->player->y / 64][data->player->x / 64 + 1] == '1' ||
	(data->map.map[data->player->y / 64][data->player->x / 64 + 1] == 'E' &&
	data->collectibles_left != 0))
		return (0);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->texture->bg, data->player->x, data->player->y);
	data->player->x += 64;
	data->steps++;
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'C')
	{
		data->collectibles_left--;
		data->map.map[data->player->y / 64][data->player->x / 64] = '0';
	}
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'E')
	{
		if (data->collectibles_left == 0)
			exit_game(data);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->texture->player_right, data->player->x, data->player->y);
	return (0);
}

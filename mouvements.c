/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:57:35 by tsadouk           #+#    #+#             */
/*   Updated: 2023/12/19 15:54:45 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_data *data)
{
	printf("x = %d, y = %d\n", data->player->x, data->player->y);
	if (data->map.map[data->player->y / 64 - 1][data->player->x / 64] == '1')
		return (0);
	del_square(data->mlx, data->mlx_win, data->player->x, data->player->y);
	data->player->y -= 64;
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'C')
	{
		data->collectibles_left--;
		data->map.map[data->player->y / 64][data->player->x / 64] = '0';
	}
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'E')
	{
		if (data->collectibles_left == 0)
			exit_game(data->mlx, data->mlx_win);
	}
	print_square(data->mlx, data->mlx_win, data->player->x,
		data->player->y, data->color);
	return (0);
}

int	move_down(t_data *data)
{
	if (data->map.map[data->player->y / 64 + 1][data->player->x / 64] == '1')
		return (0);
	del_square(data->mlx, data->mlx_win, data->player->x, data->player->y);
	data->player->y += 64;
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'C')
	{
		data->collectibles_left--;
		data->map.map[data->player->y / 64][data->player->x / 64] = '0';
	}
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'E')
	{
		if (data->collectibles_left == 0)
			exit_game(data->mlx, data->mlx_win);
	}
	print_square(data->mlx, data->mlx_win, data->player->x,
		data->player->y, data->color);
	return (0);
}

int	move_left(t_data *data)
{
	if (data->map.map[data->player->y / 64][data->player->x / 64 - 1] == '1')
		return (0);
	del_square(data->mlx, data->mlx_win, data->player->x, data->player->y);
	data->player->x -= 64;
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'C')
	{
		data->collectibles_left--;
		data->map.map[data->player->y / 64][data->player->x / 64] = '0';
	}
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'E')
	{
		if (data->collectibles_left == 0)
			exit_game(data->mlx, data->mlx_win);
	}
	print_square(data->mlx, data->mlx_win, data->player->x,
		data->player->y, data->color);
	return (0);
}

int	move_right(t_data *data)
{
	if (data->map.map[data->player->y / 64][data->player->x / 64 + 1] == '1')
		return (0);
	del_square(data->mlx, data->mlx_win, data->player->x, data->player->y);
	data->player->x += 64;
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'C')
	{
		data->collectibles_left--;
		data->map.map[data->player->y / 64][data->player->x / 64] = '0';
	}
	if (data->map.map[data->player->y / 64][data->player->x / 64] == 'E')
	{
		if (data->collectibles_left == 0)
			exit_game(data->mlx, data->mlx_win);
	}
	print_square(data->mlx, data->mlx_win, data->player->x,
		data->player->y, data->color);
	return (0);
}

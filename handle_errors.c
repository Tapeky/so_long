/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:51:18 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/16 15:11:22 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_collectibles(char **map)
{
	int	i;
	int	j;
	int	collectibles;

	collectibles = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	if (collectibles == 0)
		return (false);
	return (true);
}

bool	check_exit(char **map)
{
	int	i;
	int	j;
	int	exit;

	exit = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (false);
	return (true);
}

bool	check_walls(char **map, char *path_to_map)
{
	int	i;
	int	j;
	int	height;
	int	width;

	height = get_height(path_to_map);
	width = get_width(path_to_map);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((i == 0 || i == height - 1) && map[i][j] != '1')
				return (false);
			if ((j == 0 || j == width - 1) && map[i][j] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_player(char **map)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (false);
	return (true);
}

bool	handle_errors(char **map, char *path_to_map)
{
	if (!check_collectibles(map))
		return (false);
	if (!check_exit(map))
		return (false);
	if (!check_player(map))
		return (false);
	if (!check_walls(map, path_to_map))
		return (false);
	return (true);
}

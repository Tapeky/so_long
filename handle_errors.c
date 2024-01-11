/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:51:18 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/11 17:36:23 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// Quel sont les erreurs ? si la map n est pas valide, si il n'y a pas de collectibles, si il n'y a pas de sortie

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

bool	check_walls(char **map) // si il n'y a pas de murs
{
	int	i;
	int	j;
	int height;
	int width;

	height = get_height();
	width = get_width();
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
			if (map[i][j] == 'P') // 
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (false);
	return (true);	
}

bool	handle_errors(char **map)
{
	if (!check_collectibles(map)) // si il n'y a pas de collectibles
		return (false);
	if (!check_exit(map)) // si il n'y a pas de sortie
		return (false);
	if (!check_player(map)) // si il n'y a pas de joueur
		return (false);
	if (!check_walls(map)) // si il n'y a pas de murs
		return (false);
	return (true);
}

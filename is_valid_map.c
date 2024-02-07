/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:13:22 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/31 13:26:05 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remap_map(char **map, char *path_to_map)
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
			if (map[i][j] == 'E')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

char	**spread(char **map, int x, int y, char *path_to_map)
{
	map[y][x] = 'T';
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'T' &&
			x + 2 < get_width(path_to_map))
	{
		map[y][x + 1] = 'T';
		spread(map, x + 1, y, path_to_map);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'T' && x - 1 > 0)
	{
		map[y][x - 1] = 'T';
		spread(map, x - 1, y, path_to_map);
	}
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'T' &&
			y + 2 < get_height(path_to_map))
	{
		map[y + 1][x] = 'T';
		spread(map, x, y + 1, path_to_map);
	}
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'T' && y - 1 > 0
	)
	{
		map[y - 1][x] = 'T';
		spread(map, x, y - 1, path_to_map);
	}
	return (map);
}

char    **ft_spread(char **final_map, int x, int y)
{
    final_map[x][y] = 'P';
    if (final_map[x + 1][y] != '1' && final_map[x + 1][y] != 'E')
	{
		final_map[x + 1][y] = 'P';
        ft_spread(final_map, x + 1, y);
	}
    if (final_map[x - 1][y] != '1' && final_map[x + 1][y] != 'E')
        ft_spread(final_map, x - 1, y);
    if (final_map[x][y + 1] != '1' && final_map[x + 1][y] != 'E')
        ft_spread(final_map, x, y + 1);
    if (final_map[x][y - 1] != '1' && final_map[x + 1][y] != 'E')
        ft_spread(final_map, x, y - 1);
    return (final_map);
}

char	**spread2(char **map, int x, int y, char *path_to_map)
{
	remap_map(map, path_to_map);
	map[y][x] = 'T';
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'T' &&
			x + 2 < get_width(path_to_map))
	{
		map[y][x + 1] = 'T';
		spread(map, x + 1, y, path_to_map);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'T' && x - 1 > 0)
	{
		map[y][x - 1] = 'T';
		spread(map, x - 1, y, path_to_map);
	}
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'T' &&
			y + 2 < get_height(path_to_map))
	{
		map[y + 1][x] = 'T';
		spread(map, x, y + 1, path_to_map);
	}
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'T' && y - 1 > 0)
	{
		map[y - 1][x] = 'T';
		spread(map, x, y - 1, path_to_map);
	}
	return (map);
}

bool	is_valid_map(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_valid_map2(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (map[i][j] == 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

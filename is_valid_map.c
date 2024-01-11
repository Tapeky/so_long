/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:13:22 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/11 17:41:59 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	**spread(char **map, int x, int y)
{
	map[y][x] = 'T';
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'T')
	{
		map[y][x + 1] = 'T';
		spread(map, x + 1, y);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'T')
	{
		map[y][x - 1] = 'T';
		spread(map, x - 1, y);
	}
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'T')
	{
		map[y + 1][x] = 'T';
		spread(map, x, y + 1);
	}
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'T')
	{
		map[y - 1][x] = 'T';
		spread(map, x, y - 1);
	}
	return (map);
}

bool	is_valid_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

/*
int	main(void)
{
	char	**map = get_map();
	int		y = player_pos_y(map);
	int		x = player_pos_x(map);

	map = spread(map, x, y);
	int i = 0;
	int j;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	
	return (0);

}
*/
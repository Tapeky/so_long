/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:21:40 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/16 14:52:07 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_error_1(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.height)
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
	free(data->player);
	free(data);
}

void	free_error_2(t_data *data, char **map_cpy)
{
	int	i;

	i = 0;
	while (i < data->map.height)
	{
		free(map_cpy[i]);
		free(data->map.map[i]);
		i++;
	}
	free(map_cpy);
	free(data->map.map);
	free(data->player);
	free(data);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	free(map);
}

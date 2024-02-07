/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:06:12 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/16 15:15:30 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_data(t_data *data, t_player *player, char ***map_cpy,
		char *path_to_map)
{
	int	i;

	i = 0;
	data->map.map = get_map(path_to_map);
	data->map.height = get_height(path_to_map);
	data->map.width = get_width(path_to_map);
	data->collectibles_left = 0;
	data->steps = 0;
	player->x = player_pos_x(data->map.map) * 64;
	player->y = player_pos_y(data->map.map) * 64;
	data->player = player;
	if (player_pos_x(data->map.map) == 0
		|| player_pos_y(data->map.map) == 0)
	{
		free_error_1(data);
		ft_putstr_fd("Error\nInvalid map (No player here)\n", 2);
		exit(0);
	}
	*map_cpy = spread(get_map(path_to_map), player_pos_x(data->map.map),
			player_pos_y(data->map.map), path_to_map);
}

void	initialize_graphics(t_data *data, t_texture *texture)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->map.width * 64,
			data->map.height * 64, "MisthAA!");
	data->texture = texture;
	load_textures(texture, data);
	put_all_textures(data->map.map, texture, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture->player_up,
		data->player->x, data->player->y);
}

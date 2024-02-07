/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:07:40 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/16 15:36:35 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_texture	*texture;
	t_player	*player;
	t_data		*data;
	char		**map_cpy;

	main_error_handler(argc, argv);
	player = malloc(sizeof(t_player));
	data = malloc(sizeof(t_data));
	initialize_data(data, player, &map_cpy, argv[1]);
	handle_map_errors(data->map.map, map_cpy, argv[1], data);
	handle_map_errors2(data->map.map, argv[1], data);
	texture = malloc(sizeof(t_texture));
	initialize_graphics(data, texture);
	run_game_loop(data);
	return (0);
}

void	exit_game(t_data *data)
{
	mlx_destroy_image(data->mlx, data->texture->wall);
	mlx_destroy_image(data->mlx, data->texture->collectible);
	mlx_destroy_image(data->mlx, data->texture->exit);
	mlx_destroy_image(data->mlx, data->texture->player_up);
	mlx_destroy_image(data->mlx, data->texture->player_down);
	mlx_destroy_image(data->mlx, data->texture->player_left);
	mlx_destroy_image(data->mlx, data->texture->player_right);
	mlx_destroy_image(data->mlx, data->texture->bg);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->texture);
	free_error_1(data);
	exit(0);
}

void	load_textures(t_texture *texture, t_data *data)
{
	int	*x;
	int	*y;

	x = malloc(sizeof(int));
	y = malloc(sizeof(int));
	texture->wall = mlx_png_file_to_image(data->mlx,
			"./textures/Wall.png", x, y);
	texture->collectible = mlx_png_file_to_image(data->mlx,
			"./textures/Collec.png", x, y);
	texture->exit = mlx_png_file_to_image(data->mlx,
			"./textures/doors1.png", x, y);
	texture->player_up = mlx_png_file_to_image(data->mlx,
			"./textures/up_sprite.png", x, y);
	texture->player_down = mlx_png_file_to_image(data->mlx,
			"./textures/down_sprite.png", x, y);
	texture->player_left = mlx_png_file_to_image(data->mlx,
			"./textures/left_sprite.png", x, y);
	texture->player_right = mlx_png_file_to_image(data->mlx,
			"./textures/right_sprite.png", x, y);
	texture->bg = mlx_png_file_to_image(data->mlx,
			"./textures/bg.png", x, y);
	free(x);
	free(y);
}

void	put_all_textures(char **map, t_texture *texture, t_data *data)
{
	put_bg(map, texture, data);
	put_walls(map, texture, data);
	put_collectibles(map, texture, data);
	put_exit(map, texture, data);
}

void	run_game_loop(t_data *data)
{
	mlx_on_event(data->mlx, data->mlx_win, 0, handle_key_press, data);
	mlx_on_event(data->mlx, data->mlx_win, 5, handle_cross_click, data);
	mlx_loop(data->mlx);
}

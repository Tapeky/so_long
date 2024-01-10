/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:07:40 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/10 08:50:44 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

void	exit_game(void *mlx, void *mlx_win, void *data_ptr)
{
	t_data	*data = (t_data *)data_ptr;
	mlx_destroy_image(mlx, data->texture->wall);
	mlx_destroy_image(mlx, data->texture->collectible);
	mlx_destroy_image(mlx, data->texture->exit);
	mlx_destroy_image(mlx, data->texture->player_up);
	mlx_destroy_image(mlx, data->texture->player_down);
	mlx_destroy_image(mlx, data->texture->player_left);
	mlx_destroy_image(mlx, data->texture->player_right);
	mlx_destroy_image(mlx, data->texture->bg);
	mlx_destroy_image(mlx, data->texture->exit2);
	mlx_destroy_image(mlx, data->texture->exit3);
	mlx_destroy_image(mlx, data->texture->exit4);
	mlx_destroy_image(mlx, data->texture->exit5);
	mlx_destroy_image(mlx, data->texture->exit6);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	exit(0);
}

int	handle_key_press(int keycode, void *data_ptr)
{
	t_data	*data = (t_data *)data_ptr;
	if (data->collectibles_left == 0)
		open_door(data);
	printf("steps : %d\n", data->steps);
	data->steps++;
	if (keycode == 26)
		move_up(data);
	if (keycode == 22)
		move_down(data);
	if (keycode == 4)
		move_left(data);
	if (keycode == 7)
		move_right(data);
	if (keycode == 41)
		exit_game(data->mlx, data->mlx_win, data);
	printf("collectibles_left: %d\n", ((t_data *)data_ptr)->collectibles_left);
	return (0);
}

void	put_all_textures(char **map, t_texture *texture, t_data *data)
{
	put_bg(map, texture, data);
	put_walls(map, texture, data);
	put_collectibles(map, texture, data);
	put_exit(map, texture, data);
}

int	looooop(void *data_ptr)
{
	t_data *data = (t_data *)data_ptr;
	
	if (data->open_door_anim_state == 6 && data->open_door_anim_state_changed)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->texture->exit, data->door_x, data->door_y);
		data->open_door_anim_state_changed = 0;
	}
	else if (data->open_door_anim_state == 5 && data->open_door_anim_state_changed)
	{
		mlx_destroy_image(data->mlx, data->texture->exit5);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->texture->exit2, data->door_x, data->door_y);
		data->open_door_anim_state_changed = 0;
	}
	else if (data->open_door_anim_state == 4 && data->open_door_anim_state_changed)
	{
		mlx_destroy_image(data->mlx, data->texture->exit5);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->texture->exit3, data->door_x, data->door_y);
		data->open_door_anim_state_changed = 0;
	}
	else if (data->open_door_anim_state == 3 && data->open_door_anim_state_changed)
	{
		mlx_destroy_image(data->mlx, data->texture->exit5);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->texture->exit4, data->door_x, data->door_y);
		data->open_door_anim_state_changed = 0;
	}
	else if (data->open_door_anim_state == 2 && data->open_door_anim_state_changed)
	{
		mlx_destroy_image(data->mlx, data->texture->exit5);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->texture->exit5, data->door_x, data->door_y);
		data->open_door_anim_state_changed = 0;
	}
	else if (data->open_door_anim_state == 1 && data->open_door_anim_state_changed)
	{
		mlx_destroy_image(data->mlx, data->texture->exit5);
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->texture->exit6, data->door_x, data->door_y);
		data->open_door_anim_state_changed = 0;
	}

	if (data->open_door_anim_state > 0)
	{
		printf("open_door_anim_count_down: %d\n", data->open_door_anim_count_down);
		if (data->open_door_anim_count_down == 0)
		{
			data->open_door_anim_state--;
			printf("open_door_anim_state: %d\n", data->open_door_anim_state);
			data->open_door_anim_count_down = 5000;
			data->open_door_anim_state_changed = 1;
		}
		else
			data->open_door_anim_count_down--;
	}

	//printf("frames: %llu\n", data->frames);
	data->frames++;
	return (0);
}

int main(void)
{
	t_texture *texture = malloc(sizeof(t_texture));
    t_player *player = malloc(sizeof(t_player));
    t_data *data = malloc(sizeof(t_data));

	int *x = malloc(sizeof(int *));
	int *y = malloc(sizeof(int *));

	(data->map).map = get_map();
	(data->map).height = get_height();
	(data->map).width = get_width();
	int i = 0;
	int j = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			printf("%c", data->map.map[i][j]);
			j++;
		}
		i++;
	}

	data->open_door_anim_state = 0;
	data->open_door_anim_state_changed = 0;
	data->open_door_anim_count_down = 0;
	data->open_door_anim_state_did = 0;
	
	data->color = 0x00FF0000;
    data->player = player;
	data->collectibles_left = 0;
	data->steps = 0;

    
	player->x = player_pos_x(data->map.map) * 64;
    player->y = player_pos_y(data->map.map) * 64;
    
	data->mlx = mlx_init();
	texture->wall = mlx_png_file_to_image(data->mlx, "./textures/Wall.png", x, y);
	texture->collectible = mlx_png_file_to_image(data->mlx, "./textures/Collec.png", x, y);
	texture->exit = mlx_png_file_to_image(data->mlx, "./textures/doors1.png", x, y);
	texture->player_up = mlx_png_file_to_image(data->mlx, "./textures/up_sprite.png", x, y);
	texture->player_down = mlx_png_file_to_image(data->mlx, "./textures/down_sprite.png", x, y);
	texture->player_left = mlx_png_file_to_image(data->mlx, "./textures/left_sprite.png", x, y);
	texture->player_right = mlx_png_file_to_image(data->mlx, "./textures/right_sprite.png", x, y);
	texture->bg = mlx_png_file_to_image(data->mlx, "./textures/bg.png", x, y);
	texture->exit2 = mlx_png_file_to_image(data->mlx, "./textures/doors2.png", x, y);
	texture->exit3 = mlx_png_file_to_image(data->mlx, "./textures/doors3.png", x, y);
	texture->exit4 = mlx_png_file_to_image(data->mlx, "./textures/doors4.png", x, y);
	texture->exit5 = mlx_png_file_to_image(data->mlx, "./textures/doors5.png", x, y);
	texture->exit6 = mlx_png_file_to_image(data->mlx, "./textures/doors6.png", x, y);
	data->texture = texture;
	mlx_loop_hook(data->mlx, looooop, data);
	data->mlx_win = mlx_new_window(data->mlx, data->map.width * 64, data->map.height * 64, "MisthAA!");
	put_all_textures(data->map.	map, texture, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->texture->player_up, player->x, player->y);

    mlx_on_event(data->mlx, data->mlx_win, 0, handle_key_press, data); // Deplacement
    mlx_loop(data->mlx);
    free(player);
    free(data);

    return (0);
}

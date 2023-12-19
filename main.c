/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:07:40 by tsadouk           #+#    #+#             */
/*   Updated: 2023/12/19 15:06:05 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdlib.h>

void exit_game(void *mlx, void *mlx_win)
{
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	exit(0);
}

int print_square(void *mlx, void *mlx_win, int x, int y, int color)
{
    int i;
    int j;

    j = 0;
    while (j < 64)
    {
        i = 0;
        while (i < 64)
        {
            mlx_pixel_put(mlx, mlx_win, x + i, y + j, color);
            i++;
        }
        j++;
    }
    return (0);
}
int del_square(void *mlx, void *mlx_win, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j <= 64)
	{
		i = 0;
		while (i <= 64)
		{
			mlx_pixel_put(mlx, mlx_win, x + i, y + j, 0x00000000);
			i++;
		}
		j++;
	}
	return (0);
}

int handle_key_press(int keycode, void *data_ptr)
{
	t_data	*data = (t_data *)data_ptr;
	if (keycode == 82)
		move_up(data);
	if (keycode == 81)
		move_down(data);
	if (keycode == 80)
		move_left(data);
	if (keycode == 79)
		move_right(data);
	if (keycode == 41)
		exit_game(data->mlx, data->mlx_win);
	printf("collectibles_left: %d\n", ((t_data *)data_ptr)->collectibles_left);
    return (0);
}
void	put_all_textures(char **map, t_texture *texture, t_data *data)
{
	put_walls(map, texture, data);
	put_collectibles(map, texture, data);
	put_exit(map, texture, data);
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
	
	data->color = 0x00FF0000;
    data->player = player;
	data->collectibles_left = 0;
	data->steps = 0;

    
	player->x = player_pos_x(data->map.map) * 64;
    player->y = player_pos_y(data->map.map) * 64;
    
	data->mlx = mlx_init();
	texture->wall = mlx_png_file_to_image(data->mlx, "./textures/Wall.png", x, y);
	texture->collectible = mlx_png_file_to_image(data->mlx, "./textures/64x64_Tiles/Metal_Floor_64x64.png", x, y);
	texture->exit = mlx_png_file_to_image(data->mlx, "./textures/Exit.png", x, y);
    data->mlx_win = mlx_new_window(data->mlx, data->map.width * 64, data->map.height * 64, "MisthAA!");
	print_square(data->mlx, data->mlx_win, player->x, player->y, data->color);
    mlx_on_event(data->mlx, data->mlx_win, 0, handle_key_press, data); // Deplacement
    put_all_textures(data->map.	map, texture, data);
	
    mlx_loop(data->mlx);
    free(player);
    free(data);

    return (0);
}

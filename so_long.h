/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:11:38 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/16 15:37:39 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include "GNL/get_next_line.h"

typedef struct s_texture
{
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*bg;
}	t_texture;

typedef struct s_player
{
	int	y;
	int	x;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}	t_map;

typedef struct s_data
{
	void				*mlx;
	void				*mlx_win;
	int					color;
	int					collectibles_left;
	int					steps;
	int					door_x;
	int					door_y;
	t_map				map;
	t_player			*player;
	t_texture			*texture;
}	t_data;

int		get_height(char *path_to_map);
int		get_width(char *path_to_map);
char	**get_map(char *path_to_map);
void	open_door(t_data *data);
int		player_pos_x(char **map);
int		player_pos_y(char **map);
void	put_walls(char **map, t_texture *texture, t_data *data);
void	put_collectibles(char **map, t_texture *texture, t_data *data);
void	put_exit(char **map, t_texture *texture, t_data *data);
void	put_bg(char **map, t_texture *texture, t_data *data);
int		move_up(t_data *data);
int		move_down(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);
char	**spread(char **map, int x, int y, char *path_to_map);
bool	is_valid_map(char **map, t_data *data);
bool	handle_errors(char **map, char *path_to_map);
bool	check_player(char **map);
bool	check_walls(char **map, char *path_to_map);
bool	check_exit(char **map);
bool	check_collectibles(char **map);
void	exit_game(t_data *data);
void	initialize_graphics(t_data *data, t_texture *texture);
void	initialize_data(t_data *data, t_player *player,
			char ***map_cpy, char *path_to_map);
void	main_error_handler(int argc, char **argv);
void	handle_map_errors(char **map, char **map_cpy,
			char *path_to_map, void *data_ptr);
int		handle_cross_click(int keycode, void *data_ptr);
int		handle_key_press(int keycode, void *data_ptr);
void	main_error_handler(int argc, char **argv);
void	load_textures(t_texture *texture, t_data *data);
void	put_all_textures(char **map, t_texture *texture, t_data *data);
void	run_game_loop(t_data *data);
bool	is_valid_map2(char **map, t_data *data);
char	**spread2(char **map, int x, int y, char *path_to_map);
void	remap_map(char **map, char *path_to_map);
void	handle_map_errors2(char **map, char *path_to_map, t_data *data);
void	free_error_1(t_data *data);
void	free_error_2(t_data *data, char **map_cpy);
void	free_textures(t_texture *texture);
void	free_all(t_data *data, t_player *player, t_texture *texture);
void	free_map(char **map);
bool	unvalid_char_in_map(char **map);
bool	is_valid_map_size(char **argv);
bool	is_valid_args(int argc, char **argv);

#endif

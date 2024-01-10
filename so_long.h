/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:39:48 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/10 09:23:14 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_position
{
	int		row;
	int		col;
}				t_position;

typedef struct s_queue_node
{
	t_position	pos;
	int			steps;
}				t_queue_node;

typedef struct s_queue
{
	t_queue_node	*array;
	int				front;
	int				rear;
	int				capacity;
}				t_queue;

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
	void	*exit2;
	void	*exit3;
	void	*exit4;
	void	*exit5;
	void	*exit6;
}				t_texture;

typedef struct s_player
{
	int	y;
	int	x;
	int	**hit_box;
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
	int					open_door_anim_state;
	int					open_door_anim_state_changed;
	int					open_door_anim_count_down;
	int					open_door_anim_state_did;
	unsigned long long	frames;
}	t_data;

int		get_height(void);
int		get_width(void);
char	**get_map(void);
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
void	exit_game(void *mlx, void *mlx_win, void *data_ptr);

#endif
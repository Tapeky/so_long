/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:39:48 by tsadouk           #+#    #+#             */
/*   Updated: 2023/12/18 20:31:42 by tsadouk          ###   ########.fr       */
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

typedef	struct s_texture
{
	void	*wall;
	void	*collectible;
	void	*exit;
}				t_texture;

typedef struct s_player
{
    int x;
    int y;
	int **hit_box;
} t_player;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
} t_map;

typedef struct s_data
{
    void	*mlx;
    void	*mlx_win;
	int		color;
	int		collectibles_left;
	int		steps;
	t_map map;
    t_player *player;
} t_data;

int		get_height(void);
int		get_width(void);
char	**get_map(void);
int		player_pos_x(char **map);
int		player_pos_y(char **map);
void	put_walls(char **map, t_texture *texture, t_data *data);
void	put_collectibles(char **map, t_texture *texture, t_data *data);
void	put_exit(char **map, t_texture *texture, t_data *data);

#endif
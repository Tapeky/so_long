/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:47:52 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/16 15:38:14 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key_press(int keycode, void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	ft_printf("steps : %d\n", data->steps);
	if (keycode == 26)
		move_up(data);
	else if (keycode == 22)
		move_down(data);
	else if (keycode == 4)
		move_left(data);
	else if (keycode == 7)
		move_right(data);
	else if (keycode == 41)
		exit_game(data);
	return (0);
}

int	handle_cross_click(int keycode, void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	if (keycode == 0)
		exit_game(data);
	return (0);
}

void	handle_map_errors(char **map, char **map_cpy,
	char *path_to_map, void *data_ptr)
{
	t_data	*data;
	int		i;

	data = (t_data *)data_ptr;
	if (!handle_errors(map, path_to_map) || !is_valid_map(map_cpy, data)
		|| unvalid_char_in_map(map))
	{
		free_error_2(data, map_cpy);
		ft_putstr_fd("Error\nInvalid map (ICI)\n", 2);
		exit(0);
	}
	i = 0;
	while (i < data->map.height)
	{
		free(map_cpy[i]);
		i++;
	}
	free(map_cpy);
}

void	handle_map_errors2(char **map, char *path_to_map, t_data *data)
{
	char	**map_cpy2;
	int		i;

	map_cpy2 = malloc(sizeof(char *) * data->map.height);
	i = 0;
	while (i < data->map.height)
	{
		map_cpy2[i] = ft_strdup(map[i]);
		i++;
	}
	map_cpy2 = spread2(map_cpy2, player_pos_x(map),
			player_pos_y(map), path_to_map);
	if (!is_valid_map2(map_cpy2, data))
	{
		free_error_2(data, map_cpy2);
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(0);
	}
	i = 0;
	while (i < data->map.height)
	{
		free(map_cpy2[i]);
		i++;
	}
	free(map_cpy2);
}

void	main_error_handler(int argc, char **argv)
{
	char	**map;

	if (!is_valid_args(argc, argv) || !is_valid_map_size(argv))
		exit(0);
	map = get_map(argv[1]);
	if (map == NULL)
	{
		free_map(map);
		ft_putstr_fd("Error\nInvalid map or Invalid Read\n", 2);
		exit(0);
	}
	free_map(map);
}

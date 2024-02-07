/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_error_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:32:45 by tsadouk           #+#    #+#             */
/*   Updated: 2024/01/16 15:22:20 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_valid_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Wrong number of arguments\n", 2);
		return (false);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Wrong file extension\n", 2);
		return (false);
	}
	return (true);
}

bool	is_valid_map_size(char **argv)
{
	if (get_height(argv[1]) < 3 || get_width(argv[1]) < 3)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map is too small\n", 2);
		return (false);
	}
	return (true);
}

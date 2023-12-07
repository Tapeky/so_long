/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:39:48 by tsadouk           #+#    #+#             */
/*   Updated: 2023/12/07 16:13:43 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "mlx/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

#endif
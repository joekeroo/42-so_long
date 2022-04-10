/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:01:22 by jhii              #+#    #+#             */
/*   Updated: 2022/04/08 16:04:57 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_malloc(t_program *game)
{
	int	i;

	i = 0;
	while (i < game->map.row)
	{
		free(game->map.arr[i]);
		i++;
	}
	free(game->map.arr);
}

int	close_window(t_program *game)
{
	mlx_destroy_window(game->mlx, game->win.ptr);
	destroy_images(game);
	free_malloc(game);
	exit(0);
	return (0);
}

t_window	create_window(t_program *game, int x, int y, char *name)
{
	t_window	window;

	window.ptr = mlx_new_window(game->mlx, x, y, name);
	window.width = x;
	window.height = y;
	mlx_hook(window.ptr, 17, 0, close_window, game);
	return (window);
}

t_image	create_image(t_program *game, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(game->mlx, path, &img.width, &img.height);
	return (img);
}

int	find_pos(t_program *game, char unit, int type)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (game->map.arr[i][j] == unit)
			{
				if (type == 1)
					return (j);
				else
					return (i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

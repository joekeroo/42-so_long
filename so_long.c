/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:53:36 by jhii              #+#    #+#             */
/*   Updated: 2022/04/09 20:16:16 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	render_condition(t_program *game, int i, int j, int type)
{
	mlx_put_image_to_window(game->mlx, game->win.ptr,
		game->tile.ptr, j * 64, i * 64);
	if (game->map.arr[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->wall.ptr, j * 64, i * 64);
	if (game->map.arr[i][j] == 'X' || game->map.arr[i][j] == 'Y')
		render_portal(game, i, j, type);
	if (game->map.arr[i][j] == 'P')
		render_player(game, i, j, type);
	if (game->map.arr[i][j] == 'C')
		render_coin(game, i, j, type);
	if (game->map.arr[i][j] == 'Q')
		render_enemy(game, i, j, type);
	if (game->map.arr[i][j] == 'E')
		render_exit(game, i, j, type);
}

static	int	render_image(t_program *game, int type)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			render_condition(game, i, j, type);
			j++;
		}
		i++;
	}
	update_counter(game);
	return (0);
}

static	int	final_animation(t_program *game)
{
	render_image(game, 0);
	return (0);
}

static	int	animation(t_program *game)
{
	static int	frame;

	frame++;
	if (frame < 5)
		render_image(game, 1);
	else if (frame < 10)
		render_image(game, 2);
	else if (frame < 15)
		render_image(game, 3);
	else if (frame < 17)
		render_image(game, 4);
	else if (frame < 20)
		render_image(game, 5);
	else if (frame < 23)
		render_image(game, 6);
	else if (frame < 25)
		render_image(game, 7);
	else if (frame < 30)
		render_image(game, 8);
	else if (frame < 35)
		render_image(game, 9);
	else if (frame >= 40)
		frame = final_animation(game);
	return (0);
}

void	so_long(t_program *game)
{
	int			map_x;
	int			map_y;

	map_x = 64 * game->map.col;
	map_y = 64 * game->map.row;
	game->moves = 0;
	game->mlx = mlx_init();
	game->win = create_window(game, map_x, map_y, "so_long");
	create_images(game);
	game->plyr.x = find_pos(game, 'P', 1);
	game->plyr.y = find_pos(game, 'P', 2);
	game->enmy.x = find_pos(game, 'Q', 1);
	game->enmy.y = find_pos(game, 'Q', 2);
	mlx_key_hook(game->win.ptr, controls, game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_loop(game->mlx);
	return ;
}

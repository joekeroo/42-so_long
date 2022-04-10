/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:52:50 by jhii              #+#    #+#             */
/*   Updated: 2022/04/08 16:21:46 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	extra_render_player(t_program *game, int i, int j, int type)
{
	if (type == 5)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->plyr4.ptr, j * 64, i * 64);
	if (type == 6)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->plyr4.ptr, j * 64, i * 64);
	if (type == 7)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->plyr5.ptr, j * 64, i * 64);
	if (type == 8)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->plyr6.ptr, j * 64, i * 64);
	if (type == 9)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->plyr7.ptr, j * 64, i * 64);
}

void	render_player(t_program *game, int i, int j, int type)
{
	if (type == 0)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->plyr.ptr, j * 64, i * 64);
	if (type == 1)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->plyr1.ptr, j * 64, i * 64);
	if (type == 2)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->plyr2.ptr, j * 64, i * 64);
	if (type == 3)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->plyr3.ptr, j * 64, i * 64);
	if (type == 4)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->plyr3.ptr, j * 64, i * 64);
	extra_render_player(game, i, j, type);
}

static	void	extra_render_coin(t_program *game, int i, int j, int type)
{
	if (type == 5)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->coin5.ptr, j * 64, i * 64);
	if (type == 6)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->coin6.ptr, j * 64, i * 64);
	if (type == 7)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->coin7.ptr, j * 64, i * 64);
	if (type == 8)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->coin8.ptr, j * 64, i * 64);
	if (type == 9)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->coin9.ptr, j * 64, i * 64);
}

void	render_coin(t_program *game, int i, int j, int type)
{
	if (type == 0)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->coin.ptr, j * 64, i * 64);
	if (type == 1)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->coin1.ptr, j * 64, i * 64);
	if (type == 2)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->coin2.ptr, j * 64, i * 64);
	if (type == 3)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->coin3.ptr, j * 64, i * 64);
	if (type == 4)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->coin4.ptr, j * 64, i * 64);
	extra_render_coin(game, i, j, type);
}

void	update_counter(t_program *game)
{
	char	*count;

	count = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win.ptr, 10, 20, 0xFFFFFF, count);
	if (count != NULL)
		free(count);
}

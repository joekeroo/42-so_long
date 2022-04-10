/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:18:22 by jhii              #+#    #+#             */
/*   Updated: 2022/04/09 18:13:20 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	extra_render_enemy(t_program *game, int i, int j, int type)
{
	if (type == 5)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->enmy5.ptr, j * 64, i * 64);
	if (type == 6)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->enmy6.ptr, j * 64, i * 64);
	if (type == 7)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->enmy7.ptr, j * 64, i * 64);
	if (type == 8)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->enmy8.ptr, j * 64, i * 64);
	if (type == 9)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->enmy9.ptr, j * 64, i * 64);
}

void	render_enemy(t_program *game, int i, int j, int type)
{
	if (type == 0)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->enmy.ptr, j * 64, i * 64);
	if (type == 1)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->enmy1.ptr, j * 64, i * 64);
	if (type == 2)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->enmy2.ptr, j * 64, i * 64);
	if (type == 3)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->enmy3.ptr, j * 64, i * 64);
	if (type == 4)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->enmy4.ptr, j * 64, i * 64);
	extra_render_enemy(game, i, j, type);
}

void	render_exit(t_program *game, int i, int j, int type)
{
	if (type == 0 || type == 5)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->exit.ptr, j * 64, i * 64);
	if (type == 1 || type == 6)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->exit1.ptr, j * 64, i * 64);
	if (type == 2 || type == 7)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->exit2.ptr, j * 64, i * 64);
	if (type == 3 || type == 8)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->exit3.ptr, j * 64, i * 64);
	if (type == 4 || type == 9)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->exit4.ptr, j * 64, i * 64);
}

static	void	extra_render_portal(t_program *game, int i, int j, int type)
{
	if (type == 5)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->prtl4.ptr, j * 64, i * 64);
	if (type == 6)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->prtl4.ptr, j * 64, i * 64);
	if (type == 7)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->prtl5.ptr, j * 64, i * 64);
	if (type == 8)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->prtl6.ptr, j * 64, i * 64);
	if (type == 9)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->prtl7.ptr, j * 64, i * 64);
}

void	render_portal(t_program *game, int i, int j, int type)
{
	if (type == 0)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->prtl.ptr, j * 64, i * 64);
	if (type == 1)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->prtl1.ptr, j * 64, i * 64);
	if (type == 2)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->prtl2.ptr, j * 64, i * 64);
	if (type == 3)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->prtl3.ptr, j * 64, i * 64);
	if (type == 4)
		mlx_put_image_to_window(game->mlx, game->win.ptr,
			game->prtl3.ptr, j * 64, i * 64);
	extra_render_portal(game, i, j, type);
}

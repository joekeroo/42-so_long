/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:02:54 by jhii              #+#    #+#             */
/*   Updated: 2022/04/09 18:08:03 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_player(t_program *game)
{
	mlx_destroy_image(game->mlx, game->plyr.ptr);
	mlx_destroy_image(game->mlx, game->plyr1.ptr);
	mlx_destroy_image(game->mlx, game->plyr2.ptr);
	mlx_destroy_image(game->mlx, game->plyr3.ptr);
	mlx_destroy_image(game->mlx, game->plyr4.ptr);
	mlx_destroy_image(game->mlx, game->plyr5.ptr);
	mlx_destroy_image(game->mlx, game->plyr6.ptr);
	mlx_destroy_image(game->mlx, game->plyr7.ptr);
}

void	destroy_coin(t_program *game)
{
	mlx_destroy_image(game->mlx, game->coin.ptr);
	mlx_destroy_image(game->mlx, game->coin1.ptr);
	mlx_destroy_image(game->mlx, game->coin2.ptr);
	mlx_destroy_image(game->mlx, game->coin3.ptr);
	mlx_destroy_image(game->mlx, game->coin4.ptr);
	mlx_destroy_image(game->mlx, game->coin5.ptr);
	mlx_destroy_image(game->mlx, game->coin6.ptr);
	mlx_destroy_image(game->mlx, game->coin7.ptr);
	mlx_destroy_image(game->mlx, game->coin8.ptr);
	mlx_destroy_image(game->mlx, game->coin9.ptr);
}

void	destroy_enemy(t_program *game)
{
	mlx_destroy_image(game->mlx, game->enmy.ptr);
	mlx_destroy_image(game->mlx, game->enmy1.ptr);
	mlx_destroy_image(game->mlx, game->enmy2.ptr);
	mlx_destroy_image(game->mlx, game->enmy3.ptr);
	mlx_destroy_image(game->mlx, game->enmy4.ptr);
	mlx_destroy_image(game->mlx, game->enmy5.ptr);
	mlx_destroy_image(game->mlx, game->enmy6.ptr);
	mlx_destroy_image(game->mlx, game->enmy7.ptr);
	mlx_destroy_image(game->mlx, game->enmy8.ptr);
	mlx_destroy_image(game->mlx, game->enmy9.ptr);
}

void	destroy_exit(t_program *game)
{
	mlx_destroy_image(game->mlx, game->exit.ptr);
	mlx_destroy_image(game->mlx, game->exit1.ptr);
	mlx_destroy_image(game->mlx, game->exit2.ptr);
	mlx_destroy_image(game->mlx, game->exit3.ptr);
	mlx_destroy_image(game->mlx, game->exit4.ptr);
}

void	destroy_portal(t_program *game)
{
	mlx_destroy_image(game->mlx, game->prtl.ptr);
	mlx_destroy_image(game->mlx, game->prtl1.ptr);
	mlx_destroy_image(game->mlx, game->prtl2.ptr);
	mlx_destroy_image(game->mlx, game->prtl3.ptr);
	mlx_destroy_image(game->mlx, game->prtl4.ptr);
	mlx_destroy_image(game->mlx, game->prtl5.ptr);
	mlx_destroy_image(game->mlx, game->prtl6.ptr);
	mlx_destroy_image(game->mlx, game->prtl7.ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:06:58 by jhii              #+#    #+#             */
/*   Updated: 2022/04/09 18:07:49 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_images(t_program *game)
{
	game->tile = create_image(game, "images/tile0.xpm");
	game->wall = create_image(game, "images/wall0.xpm");
	create_players(game);
	create_coins(game);
	create_exit(game);
	create_enemy(game);
	create_portals(game);
}

void	destroy_images(t_program *game)
{
	mlx_destroy_image(game->mlx, game->tile.ptr);
	mlx_destroy_image(game->mlx, game->wall.ptr);
	destroy_player(game);
	destroy_coin(game);
	destroy_enemy(game);
	destroy_exit(game);
	destroy_portal(game);
}

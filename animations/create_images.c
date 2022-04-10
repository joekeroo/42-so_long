/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:10:39 by jhii              #+#    #+#             */
/*   Updated: 2022/04/09 18:53:36 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_players(t_program *game)
{
	game->plyr = create_image(game, "images/player0.xpm");
	game->plyr1 = create_image(game, "images/player1.xpm");
	game->plyr2 = create_image(game, "images/player2.xpm");
	game->plyr3 = create_image(game, "images/player3.xpm");
	game->plyr4 = create_image(game, "images/player4.xpm");
	game->plyr5 = create_image(game, "images/player5.xpm");
	game->plyr6 = create_image(game, "images/player6.xpm");
	game->plyr7 = create_image(game, "images/player7.xpm");
}

void	create_coins(t_program *game)
{
	game->coin = create_image(game, "images/coin0.xpm");
	game->coin1 = create_image(game, "images/coin1.xpm");
	game->coin2 = create_image(game, "images/coin2.xpm");
	game->coin3 = create_image(game, "images/coin3.xpm");
	game->coin4 = create_image(game, "images/coin4.xpm");
	game->coin5 = create_image(game, "images/coin5.xpm");
	game->coin6 = create_image(game, "images/coin6.xpm");
	game->coin7 = create_image(game, "images/coin7.xpm");
	game->coin8 = create_image(game, "images/coin8.xpm");
	game->coin9 = create_image(game, "images/coin9.xpm");
}

void	create_enemy(t_program *game)
{
	game->enmy = create_image(game, "images/enemy0.xpm");
	game->enmy1 = create_image(game, "images/enemy1.xpm");
	game->enmy2 = create_image(game, "images/enemy2.xpm");
	game->enmy3 = create_image(game, "images/enemy3.xpm");
	game->enmy4 = create_image(game, "images/enemy4.xpm");
	game->enmy5 = create_image(game, "images/enemy5.xpm");
	game->enmy6 = create_image(game, "images/enemy6.xpm");
	game->enmy7 = create_image(game, "images/enemy7.xpm");
	game->enmy8 = create_image(game, "images/enemy8.xpm");
	game->enmy9 = create_image(game, "images/enemy9.xpm");
}

void	create_exit(t_program *game)
{
	game->exit = create_image(game, "images/exit0.xpm");
	game->exit1 = create_image(game, "images/exit1.xpm");
	game->exit2 = create_image(game, "images/exit2.xpm");
	game->exit3 = create_image(game, "images/exit3.xpm");
	game->exit4 = create_image(game, "images/exit4.xpm");
}

void	create_portals(t_program *game)
{
	game->prtl = create_image(game, "images/portal0.xpm");
	game->prtl1 = create_image(game, "images/portal1.xpm");
	game->prtl2 = create_image(game, "images/portal2.xpm");
	game->prtl3 = create_image(game, "images/portal3.xpm");
	game->prtl4 = create_image(game, "images/portal4.xpm");
	game->prtl5 = create_image(game, "images/portal5.xpm");
	game->prtl6 = create_image(game, "images/portal6.xpm");
	game->prtl7 = create_image(game, "images/portal7.xpm");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:59:46 by jhii              #+#    #+#             */
/*   Updated: 2022/04/10 14:08:10 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	check_portal(t_program *game, t_pos *new, t_pos *old)
{
	if (game->map.arr[new->y][new->x] == 'X')
	{
		if (game->map.arr[game->map.prtl1_y][game->map.prtl1_x] == 'Q')
			death_msg(game);
		game->map.arr[game->map.prtl1_y][game->map.prtl1_x] = 'P';
		game->map.arr[old->y][old->x] = '0';
		game->plyr.x = game->map.prtl1_x;
		game->plyr.y = game->map.prtl1_y;
		game->moves++;
		return (1);
	}
	else if (game->map.arr[new->y][new->x] == 'Y')
	{
		if (game->map.arr[game->map.prtl_y][game->map.prtl_x] == 'Q')
			death_msg(game);
		game->map.arr[game->map.prtl_y][game->map.prtl_x] = 'P';
		game->map.arr[old->y][old->x] = '0';
		game->plyr.x = game->map.prtl_x;
		game->plyr.y = game->map.prtl_y;
		game->moves++;
		return (1);
	}
	return (-1);
}

static	int	update_condition(t_program *game, t_pos *new, t_pos *old)
{
	if (game->map.arr[new->y][new->x] != '1' &&
		game->map.arr[new->y][new->x] != 'X' &&
		game->map.arr[new->y][new->x] != 'Y')
	{
		if (game->map.arr[new->y][new->x] == 'E')
		{
			if (game->map.coin == 0)
			{
				ft_printf("You decimated the game!\n");
				close_window(game);
			}
			return (-1);
		}
		else if (game->map.arr[new->y][new->x] == 'Q')
			death_msg(game);
		else if (game->map.arr[new->y][new->x] == 'C')
			game->map.coin--;
		game->map.arr[new->y][new->x] = 'P';
		game->map.arr[old->y][old->x] = '0';
		return (1);
	}
	return (-1);
}

static	void	fix_plyr(t_program *game, t_pos *new, t_pos *old)
{
	if (new->x != old->x)
	{
		if (new->x > old->x)
			game->plyr.x--;
		else
			game->plyr.x++;
	}
	if (new->y != old->y)
	{
		if (new->y > old->y)
			game->plyr.y--;
		else
			game->plyr.y++;
	}
}

void	update_player(t_program *game, int key)
{
	t_pos	new;
	t_pos	old;

	new.x = game->plyr.x;
	new.y = game->plyr.y;
	old.x = game->plyr.x;
	old.y = game->plyr.y;
	if (key == 13)
		new.y = --game->plyr.y;
	else if (key == 0)
		new.x = --game->plyr.x;
	else if (key == 1)
		new.y = ++game->plyr.y;
	else if (key == 2)
		new.x = ++game->plyr.x;
	else
		return ;
	if (check_portal(game, &new, &old) > 0)
		return ;
	if (update_condition(game, &new, &old) < 0)
		fix_plyr(game, &new, &old);
	else
		game->moves++;
}

int	controls(int key, t_program *game)
{
	if (key == 53)
		close_window(game);
	update_player(game, key);
	if (game->map.enmy > 0)
		update_enemy(game, key);
	return (0);
}

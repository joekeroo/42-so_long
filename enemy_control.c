/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:41:24 by jhii              #+#    #+#             */
/*   Updated: 2022/04/09 18:29:26 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	update_cond(t_program *game, t_pos *new, t_pos *old)
{
	if (game->map.arr[new->y][new->x] != '1' &&
		game->map.arr[new->y][new->x] != 'E' &&
		game->map.arr[new->y][new->x] != 'X' &&
		game->map.arr[new->y][new->x] != 'Y')
	{
		if (game->map.arr[new->y][new->x] == 'P')
		{
			ft_printf("The Enemy Killed You!\n");
			close_window(game);
		}
		else if (game->map.arr[new->y][new->x] == 'C')
			game->map.arr[old->y][old->x] = 'C';
		else
			game->map.arr[old->y][old->x] = '0';
		game->map.arr[new->y][new->x] = 'Q';
		return (1);
	}
	return (-1);
}

static	void	fix_enmy(t_program *game, t_pos *new, t_pos *old)
{
	if (new->x != old->x)
	{
		if (new->x > old->x)
			game->enmy.x--;
		else
			game->enmy.x++;
	}
	if (new->y != old->y)
	{
		if (new->y > old->y)
			game->enmy.y--;
		else
			game->enmy.y++;
	}
}

void	update_enemy(t_program *game, int key)
{
	t_pos	new;
	t_pos	old;

	new.x = game->enmy.x;
	new.y = game->enmy.y;
	old.x = game->enmy.x;
	old.y = game->enmy.y;
	if (key == 34)
		new.y = --game->enmy.y;
	else if (key == 38)
		new.x = --game->enmy.x;
	else if (key == 40)
		new.y = ++game->enmy.y;
	else if (key == 37)
		new.x = ++game->enmy.x;
	else
		return ;
	if (update_cond(game, &new, &old) < 0)
		fix_enmy(game, &new, &old);
}

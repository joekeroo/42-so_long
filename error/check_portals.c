/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_portals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:36:25 by jhii              #+#    #+#             */
/*   Updated: 2022/04/09 20:28:53 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	check_portal_x(t_program *game)
{
	if (game->map.arr[game->map.prtl_y][game->map.prtl_x - 1] == '0')
	{
		game->map.prtl_x -= 1;
		return (1);
	}
	else if (game->map.arr[game->map.prtl_y][game->map.prtl_x + 1] == '0')
	{
		game->map.prtl_x += 1;
		return (1);
	}
	else if (game->map.arr[game->map.prtl_y - 1][game->map.prtl_x] == '0')
	{
		game->map.prtl_y -= 1;
		return (1);
	}
	else if (game->map.arr[game->map.prtl_y + 1][game->map.prtl_x] == '0')
	{
		game->map.prtl_y += 1;
		return (1);
	}
	return (-1);
}

static	int	check_portal_y(t_program *game)
{
	if (game->map.arr[game->map.prtl1_y][game->map.prtl1_x - 1] == '0')
	{
		game->map.prtl1_x -= 1;
		return (1);
	}
	else if (game->map.arr[game->map.prtl1_y][game->map.prtl1_x + 1] == '0')
	{
		game->map.prtl1_x += 1;
		return (1);
	}
	else if (game->map.arr[game->map.prtl1_y - 1][game->map.prtl1_x] == '0')
	{
		game->map.prtl1_y -= 1;
		return (1);
	}
	else if (game->map.arr[game->map.prtl1_y + 1][game->map.prtl1_x] == '0')
	{
		game->map.prtl1_y += 1;
		return (1);
	}
	return (-1);
}

int	check_portals(t_program *game)
{
	game->map.prtl_x = find_pos(game, 'X', 1);
	game->map.prtl_y = find_pos(game, 'X', 2);
	game->map.prtl1_x = find_pos(game, 'Y', 1);
	game->map.prtl1_y = find_pos(game, 'Y', 2);
	if (check_portal_x(game) > 0 && check_portal_y(game) > 0)
		return (1);
	else
		return (ft_printf("Error: Portals do not have exits in Map\n") * -1);
}

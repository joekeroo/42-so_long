/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:19:46 by jhii              #+#    #+#             */
/*   Updated: 2022/04/09 18:44:54 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	check_unit(t_program *game, int i, int j)
{
	int	check;

	check = -1;
	if (game->map.arr[i][j] == '1')
		check = 1;
	if (game->map.arr[i][j] == '0')
		check = 1;
	if (game->map.arr[i][j] == 'P')
		check = ++game->map.plyr;
	if (game->map.arr[i][j] == 'C')
		check = ++game->map.coin;
	if (game->map.arr[i][j] == 'E')
		check = ++game->map.exit;
	if (game->map.arr[i][j] == 'Q')
		check = ++game->map.enmy;
	if (game->map.arr[i][j] == 'X')
		check = ++game->map.prtl;
	if (game->map.arr[i][j] == 'Y')
		check = ++game->map.prtl1;
	if (check < 0)
		return (-1);
	return (1);
}

static	int	check_units(t_program *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (check_unit(game, i, j) < 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static	int	check_walls(t_program *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.row)
	{
		if (i == 0 || i == game->map.row - 1)
		{
			j = 0;
			while (j < game->map.col)
			{
				if (game->map.arr[i][j++] != '1')
					return (-1);
			}
		}
		else
			if (game->map.arr[i][0] != '1' ||
				game->map.arr[i][game->map.col - 1] != '1')
				return (-1);
		i++;
	}
	return (1);
}

static	int	check_requirements(t_program *game)
{
	if (game->map.plyr < 1)
		return (ft_printf("Error: No Player in Map\n") * -1);
	if (game->map.plyr > 1)
		return (ft_printf("Error: Too Many Players in Map\n") * -1);
	if (game->map.coin < 1)
		return (ft_printf("Error: No Collectables in Map\n") * -1);
	if (game->map.exit < 1)
		return (ft_printf("Error: No Exits in Map\n") * -1);
	if (game->map.enmy > 1)
		return (ft_printf("Error: Too Many Enemies in Map\n") * -1);
	if (game->map.prtl + game->map.prtl1 == 0)
		return (1);
	if (game->map.prtl != 1)
		return (ft_printf("Error: Must have 2 Portals in Map\n") * -1);
	if (game->map.prtl1 != 1)
		return (ft_printf("Error: Must have 2 Portals in Map\n") * -1);
	return (1);
}

int	check_map_error(t_program *game)
{
	game->map.plyr = 0;
	game->map.coin = 0;
	game->map.exit = 0;
	game->map.enmy = 0;
	game->map.prtl = 0;
	game->map.prtl1 = 0;
	if (check_units(game) < 0)
		return (ft_printf("Error: Invalid Map Unit\n") * -1);
	if (check_walls(game) < 0)
		return (ft_printf("Error: Unclosed Wall\n") * -1);
	if (check_requirements(game) < 0)
		return (-1);
	if (game->map.prtl == 1 && game->map.prtl1 == 1)
		if (check_portals(game) < 0)
			return (-1);
	return (1);
}

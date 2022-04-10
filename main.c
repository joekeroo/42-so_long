/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:03:17 by jhii              #+#    #+#             */
/*   Updated: 2022/04/08 16:50:06 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// manmlxloop, manmlximg, manmlxwin, manmlxput, manmlx
int	main(int argc, char **argv)
{
	t_program	game;

	if (argc != 2)
		return (0);
	if (check_error(&game, argv[1]) < 0)
		return (0);
	so_long(&game);
	return (0);
}

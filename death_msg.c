/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:44:40 by jhii              #+#    #+#             */
/*   Updated: 2022/04/09 20:49:33 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	death_msg(t_program *game)
{
	ft_printf("It's okay, you died a Quick Death!\n");
	close_window(game);
}
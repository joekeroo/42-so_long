/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:32:48 by jhii              #+#    #+#             */
/*   Updated: 2022/04/07 14:44:15 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	char	*strdup(char *str, int size)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * ft_strlen(str));
	i = -1;
	while (++i < size)
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

void	create_map(t_program *game, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game->map.arr = malloc(sizeof(char *) * game->map.row);
	while (line != NULL)
	{
		game->map.arr[i++] = strdup(line, game->map.col);
		free(line);
		line = get_next_line(fd);
	}
}

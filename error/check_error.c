/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:24:15 by jhii              #+#    #+#             */
/*   Updated: 2022/04/08 15:55:05 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	nl_len(char *str)
{
	if (str[ft_strlen(str) - 1] == '\n')
		return (ft_strlen(str) - 1);
	return (ft_strlen(str));
}

static	int	check_nl(t_program *game, char **line, char **last, int fd)
{
	if (game->map.row == 0)
	{
		game->map.col = nl_len(*line);
		free(*line);
		*line = get_next_line(fd);
	}
	else if (nl_len(*line) == game->map.col)
	{
		if (*last != NULL)
			free(*last);
		*last = ft_strdup(*line);
		free(*line);
		*line = get_next_line(fd);
	}
	else
	{
		free(*line);
		if (*last != NULL)
			free(*last);
		ft_printf("Error: Invalid Map Size\n");
		return (-1);
	}
	return (1);
}

static	int	store_map_info(t_program *game, char *filename)
{
	int		fd;
	int		check;
	char	*line;
	char	*last;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	last = NULL;
	while (line != NULL)
	{
		check = check_nl(game, &line, &last, fd);
		if (check < 0)
			return (-1);
		game->map.row++;
	}
	if (last != NULL && last[ft_strlen(last) - 1] == '\n')
	{
		free(last);
		ft_printf("Error: Invalid Map Size\n");
		return (-1);
	}
	if (last != NULL)
		free(last);
	close(fd);
	return (1);
}

static	int	check_map_size(t_program *game)
{
	if (game->map.row >= 4 && game->map.col >= 4)
		return (1);
	else if (game->map.row == 3 && game->map.col >= 5)
		return (1);
	else if (game->map.row >= 5 && game->map.col == 3)
		return (1);
	ft_printf("Error: Invalid Map Size\n");
	return (-1);
}

int	check_error(t_program *game, char *filename)
{
	game->map.row = 0;
	game->map.col = 0;
	if (check_file_error(filename) < 0)
		return (-1);
	if (store_map_info(game, filename) < 0)
		return (-1);
	if (check_map_size(game) < 0)
		return (-1);
	create_map(game, filename);
	if (check_map_error(game) < 0)
	{
		free_malloc(game);
		return (-1);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:03:28 by jhii              #+#    #+#             */
/*   Updated: 2022/04/09 20:47:47 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"
# include "libftprintf/libftprintf.h"

typedef struct s_map
{
	int		row;
	int		col;
	int		plyr;
	int		coin;
	int		exit;
	int		enmy;
	int		prtl;
	int		prtl_x;
	int		prtl_y;
	int		prtl1;
	int		prtl1_x;
	int		prtl1_y;
	char	**arr;
}	t_map;

typedef struct s_window
{
	void	*ptr;
	int		width;
	int		height;
}	t_window;

typedef struct s_image
{
	void	*ptr;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_image;

typedef struct s_pos
{
	int		x;
	int		y;
}	t_pos;

typedef struct s_program
{
	int			moves;
	void		*mlx;
	t_map		map;
	t_window	win;
	t_image		tile;
	t_image		wall;
	t_image		plyr;
	t_image		plyr1;
	t_image		plyr2;
	t_image		plyr3;
	t_image		plyr4;
	t_image		plyr5;
	t_image		plyr6;
	t_image		plyr7;
	t_image		coin;
	t_image		coin1;
	t_image		coin2;
	t_image		coin3;
	t_image		coin4;
	t_image		coin5;
	t_image		coin6;
	t_image		coin7;
	t_image		coin8;
	t_image		coin9;
	t_image		enmy;
	t_image		enmy1;
	t_image		enmy2;
	t_image		enmy3;
	t_image		enmy4;
	t_image		enmy5;
	t_image		enmy6;
	t_image		enmy7;
	t_image		enmy8;
	t_image		enmy9;
	t_image		exit;
	t_image		exit1;
	t_image		exit2;
	t_image		exit3;
	t_image		exit4;
	t_image		prtl;
	t_image		prtl1;
	t_image		prtl2;
	t_image		prtl3;
	t_image		prtl4;
	t_image		prtl5;
	t_image		prtl6;
	t_image		prtl7;
}	t_program;

char		*get_next_line(int fd);
void		create_map(t_program *game, char *filename);
void		so_long(t_program *game);
void		update_player(t_program *game, int key);
void		update_enemy(t_program *game, int key);
int			controls(int key, t_program *game);
int			check_map_error(t_program *game);
int			check_file_error(char *filename);
int			check_error(t_program *game, char *filename);
int			check_portals(t_program *game);
void		free_malloc(t_program *game);
int			close_window(t_program *game);
t_window	create_window(t_program *game, int x, int y, char *name);
t_image		create_image(t_program *game, char *path);
int			find_pos(t_program *game, char unit, int type);
void		create_images(t_program *game);
void		render_player(t_program *game, int i, int j, int type);
void		render_coin(t_program *game, int i, int j, int type);
void		render_enemy(t_program *game, int i, int j, int type);
void		render_exit(t_program *game, int i, int j, int type);
void		render_portal(t_program *game, int i, int j, int type);
void		create_players(t_program *game);
void		create_coins(t_program *game);
void		create_exit(t_program *game);
void		create_portals(t_program *game);
void		create_enemy(t_program *game);
void		destroy_player(t_program *game);
void		destroy_coin(t_program *game);
void		destroy_exit(t_program *game);
void		destroy_portal(t_program *game);
void		destroy_enemy(t_program *game);
void		destroy_images(t_program *game);
void		update_counter(t_program *game);
void		death_msg(t_program *game);

#endif

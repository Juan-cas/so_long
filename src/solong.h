/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:52:32 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/10 03:05:56 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
#define SOLONG_H

#ifndef ASSETS_H
#define ASSETS_H
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10000
#endif


#define floor_sprite "./lib/assets/floor.xpm"
#define player_sprite "./lib/assets/player.xpm"
#define enemy_sprite "./lib/assets/Juan-heroe-ogro.xpm"
#define potion_sprite "./lib/assets/collectible.xpm"
#define exit_door_sprite "./lib/assets/exit.xpm"
#define wall_sprite "./lib/assets/wall.xpm"

# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "../lib/mlx_linux/mlx.h"
# include "../lib/mlx_linux/mlx_int.h"

# include <math.h>
#include <X11/X.h>

typedef struct game_objects
{
	size_t	player;
	size_t	collectible;
	size_t	exit;
	size_t	map_length;
	size_t	map_lines;
	size_t	py_coord;
	size_t	px_coord;
	size_t	ex_coord;
	size_t	ey_coord;
	size_t	col_x;
	size_t	col_y;
	size_t	col_check;
	size_t	init_pos_flood;
	struct	game_objects *next;
}	t_objects;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[6];
	int		winysize;
	int 	winxsize;

}	t_data;

void	solong(char **map);

//error
void	ft_error(int i);

//parsing
int		is0(char c);
int		is1(char c);
int		isc(char c, t_objects *status);
int		ise(char c, t_objects *status);
int		isp(char c, t_objects *status);
void	map_check(char **map, t_objects **status);
void	collx_y(size_t y, size_t x, t_objects **status);
void	flood_fill(char **map, t_objects **status);
void	final_check(char **map, t_objects **status);
void	init_data(t_objects **status);
void	find_coords_p(char **map, t_objects **status);
void	find_coords_e(char **map, t_objects **status);
void	free_coords(t_objects **nodes);
void	lets_parse_data(char **map, t_objects **status);
char	**lets_parse_map(char **argv);
char	**init_parser(char **argv, t_objects **status);

//utils
char	**map_maker(int fd);
char	*get_next_line(int fd);
void	matrix_clear(char **matrix);
int		line1(const char *line);
char	*append(char *s1, char *s2);
int		search_n(const char *s, int c);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	textures_init(t_data *data, char **map);
void populate_window(char **map, t_data **data);

// movements

int key_press(int keycode, void *param);




//Colors
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

#endif

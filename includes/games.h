/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   games.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 02:24:55 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/21 02:24:58 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMES_H
# define GAMES_H
# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include "struct.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# define TILE_SIZE 128
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define GOAL 'E'
# define COLLECTIBLE 'C'
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ESC
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define WALL_PATH "./assets/wall/wall.xpm"
# define FLOOR_PATH "./assets/floor/floor.xpm"
# define PLAYER_PATH "./assets/players/player.xpm"
# define GOAL_PATH "./assets/goal/goal.xpm"
# define COLLECTIBLE_PATH "./assets/collect/collect.xpm"

// init/init.c
void	exit_game(t_game *game);
int		exit_success_game(t_game *game);
int		exit_failure_game(t_game *game);
int		exit_error_game(t_game *game, char *message);
void	free_map(char **map);
// init/create_map.c
void	*set_image(t_game *game, char *path, t_position *ptrs);
void	draw_image(t_game *game, t_position pos, void *img);
void	create_map(t_game *game);
char	**read_map(char *filename);
char	*get_next_line(int fd);
// inir/is_invalid_map.c
int		is_invalid_map(t_game *game, char **map);
// set_player.c
void	set_player(t_game *game);
void	set_goal(t_game *game);
// player/hooks.c
void	set_hooks(t_game *game);
// action_check.c
void	what_is_press_key(int keycode, t_position *move);
int		goal_check(t_game *game, int x, int y);
int		move_check(t_game *game, int x, int y);
int		collectible_check(t_game *game, int x, int y);
#endif
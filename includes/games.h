#ifndef GAMES_H
# define GAMES_H
# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include "struct.h"
# include <fcntl.h>
# include <stdlib.h>
# define TILE_SIZE 128
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define GOAL 'E'
# define COLLECTIBLE 'C'

int		exit_game(t_game *game);
void	exit_success_game(t_game *game);
#endif
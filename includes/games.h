#ifndef GAMES_H
# define GAMES_H
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# define TILE_SIZE 32
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define GOAL 'E'
# define COLLECTIBLE 'C'

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;
typedef struct s_map
{
	char		**body;
	int			width;
	int			height;
}				t_map;
typedef struct s_player
{
	t_point		point;
	int			cnt_collectibles;
	int			cnt_moves;
	void		*asset;
}				t_player;
typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	t_map		map;
	t_player	player;
}				t_game;
#endif
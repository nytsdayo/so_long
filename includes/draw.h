#ifndef INIT_H
# define INIT_H
# define WALL_PATH "./assets/wall/wall.xpm"
# define FLOOR_PATH "./assets/floor/floor.xpm"
# define PLAYER_PATH "./assets/players/player.xpm"
# define GOAL_PATH "./assets/goal/goal.xpm"
# define COLLECTIBLE_PATH "./assets/collectible/collect.xpm"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define TILE_SIZE 32
# include "games.h"
# include <fcntl.h>
typedef struct s_assets
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*goal;
	void	*collectible;
}			t_assets;

char		**read_map(int fd);
void		draw_map(t_game *game);
void		set_images(t_game *game, t_assets *assets);
char		*get_next_line(int fd);
#endif
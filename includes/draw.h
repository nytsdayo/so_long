#ifndef INIT_H
# define INIT_H
# define WALL_PATH "./assets/wall/wall.xpm"
# define FLOOR_PATH "./assets/floor/floor.xpm"
# define PLAYER_PATH "./assets/players/player.xpm"
# define GOAL_PATH "./assets/goal/goal.xpm"
# define COLLECTIBLE_PATH "./assets/collect/collect.xpm"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include "../../Libft/libft.h"
# include "struct.h"
# include <fcntl.h>
# include <stdlib.h>
void	create_map(t_game *game, char *filename);
char	**read_map(char *filename);
void	draw_map(t_game *game);
void	set_player(t_game *game, t_point point, void *asset);
char	*get_next_line(int fd);
void	set_hooks(t_game *game);

#endif
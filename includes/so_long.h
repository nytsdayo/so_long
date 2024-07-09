#ifndef SO_LONG_H
# define SO_LONG_H
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define TILE_SIZE 32
# define ESC 53

typedef struct s_point
{
	int		*x;
	int		*y;
}			t_point;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	t_map	*map;
	void	*wall;
	void	*floor;
	void	*player;
	void	*goal;
	void	*collectible;
}			t_game;

typedef enum e_map_element
{
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}			t_map_element;

void		set_hooks(t_game *game);
char		*get_next_line(int fd);
char		**read_map(int fd);
void		draw_map(t_game *game);
void		press_ESC(t_game *game);

#endif
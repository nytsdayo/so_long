#ifndef GAMES_H
# define GAMES_H
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point
{
	int		x;
	int		y;
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
}			t_game;
#endif
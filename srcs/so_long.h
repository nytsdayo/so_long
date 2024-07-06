#ifndef SO_LONG_H
# define SO_LONG_H
# include "../Libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
}			t_game;

void		set_hooks(t_game *game);

#endif
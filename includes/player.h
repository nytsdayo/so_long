#ifndef PLAYER_H
# define PLAYER_H
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# include "games.h"

void	set_hooks(t_game *game);
void	press_ESC(t_game *game);
void	move_forward(t_game *game, int *x, int *y);
void	move_backward(t_game *game, int *x, int *y);
void	move_left(t_game *game, int *x, int *y);
void	move_right(t_game *game, int *x, int *y);

#endif
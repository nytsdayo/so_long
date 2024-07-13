#ifndef PLAYER_H
# define PLAYER_H
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ESC
# include "games.h"

void	set_hooks(t_game *game);
void	press_ESC(t_game *game);
void	move_forward(t_game *game, int *x, int *y);
void	move_backward(t_game *game, int *x, int *y);
void	move_left(t_game *game, int *x, int *y);
void	move_right(t_game *game, int *x, int *y);
// moving check
int		exit_check(t_game *game, int x, int y);
int		move_check(t_game *game, int x, int y);
int		collectible_check(t_game *game, int x, int y);
#endif
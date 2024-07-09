#ifndef PLAYER_H
# define PLAYER_H
# define ESC 53
# include "games.h"

void	set_hooks(t_game *game);
void	press_ESC(t_game *game);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

#endif
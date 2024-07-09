/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:15:42 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/10 02:26:28 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

int		key_press(int keycode, t_game *game);
void	move_player(t_game *game, int keycode, int *p_x, int *p_y);

void	set_hooks(t_game *game)
{
	mlx_key_hook(game->win, key_press, game);
}

int	key_press(int keycode, t_game *game)
{
	(void)game;
	if (keycode == ESC) // ESC
		press_ESC(game);
	else if (keycode == W || keycode == S || keycode == A || keycode == D)
	{
		move_player(game, keycode, &game->player->point->x,
			&game->player->point->y);
	}
	return (0);
}

void	move_player(t_game *game, int keycode, int *p_x, int *p_y)
{
	if (keycode == W)
		move_forward(game, p_x, p_y);
	else if (keycode == S)
		move_backward(game, p_x, p_y);
	else if (keycode == A)
		move_left(game, p_x, p_y);
	else if (keycode == D)
		move_right(game, p_x, p_y);
}
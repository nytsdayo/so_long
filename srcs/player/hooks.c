/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:15:42 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/10 00:22:12 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

int		key_press(int keycode, t_game *game);

void	set_hooks(t_game *game)
{
	mlx_key_hook(game->win, key_press, game);
}

int	key_press(int keycode, t_game *game)
{
	(void)game;
	if (keycode == ESC) // ESC
		press_ESC(game);
	else if (keycode == 13) // W
		move_forward(game);
	else if (keycode == 1) // S
		move_backward(game);
	else if (keycode == 0) // A
		move_left(game);
	else if (keycode == 2) // D
		move_right(game);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hocks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:15:42 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/07 00:26:08 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		key_press(int keycode, t_game *game);

void	set_hooks(t_game *game)
{
	mlx_key_hook(game->win, key_press, game);
}

int	key_press(int keycode, t_game *game)
{
	(void)game;
	if (keycode == 53) // ESC
		exit(0);
	else if (keycode == 13) // W
		printf("Move forward\n");
	else if (keycode == 1) // S
		printf("Move backward\n");
	else if (keycode == 0) // A
		printf("Move left\n");
	else if (keycode == 2) // D
		printf("Move right\n");

	printf("Key pressed: %d\n", keycode);
	return (0);
}
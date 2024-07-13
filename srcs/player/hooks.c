/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:15:42 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/12 16:57:46 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

int		key_press(int keycode, t_game *game);
void	move_player(t_game *game, int keycode, int *p_x, int *p_y);

void	set_hooks(t_game *game)
{
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
}

int	key_press(int keycode, t_game *game)
{
	ft_printf("keycode: %d\n", keycode);
	ft_printf("player x: %d\n", game->player.point.x);
	ft_printf("player y: %d\n", game->player.point.y);
	if (keycode == KEY_ESC)
		press_ESC(game);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
	{
		move_player(game, keycode, &game->player.point.x,
			&game->player.point.y);
	}
	return (0);
}

void	move_player(t_game *game, int keycode, int *p_x, int *p_y)
{
	if (keycode == KEY_W)
		move_forward(game, p_x, p_y);
	else if (keycode == KEY_S)
		move_backward(game, p_x, p_y);
	else if (keycode == KEY_A)
		move_left(game, p_x, p_y);
	else if (keycode == KEY_D)
		move_right(game, p_x, p_y);
}
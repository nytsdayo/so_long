/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:15:42 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/20 14:38:04 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

int		key_press(int keycode, t_game *game);
void	move_player(t_game *game, int keycode, t_point *pos);
void	press_ESC(t_game *game);

void	set_hooks(t_game *game)
{
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0, exit_failure_game, game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		press_ESC(game);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		move_player(game, keycode, &game->player.point);
	return (0);
}

void	move_player(t_game *game, int keycode, t_point *pos)
{
	t_point	move;

	move = (t_point){0, 0};
	if (keycode == KEY_W)
		move.y = -1;
	else if (keycode == KEY_S)
		move.y = 1;
	else if (keycode == KEY_A)
		move.x = -1;
	else if (keycode == KEY_D)
		move.x = 1;
	if (move_check(game, pos->x + move.x, pos->y + move.y))
	{
		draw_image(game, *pos, game->map.assets.floor);
		*pos = (t_point){pos->x + move.x, pos->y + move.y};
		game->player.cnt_collectibles -= collectible_check(game, pos->x,
				pos->y);
		ft_printf("cnt_collectibles: %d\n", game->player.cnt_collectibles);
		draw_image(game, *pos, game->map.assets.player);
		game->player.cnt_moves++;
		ft_printf("cnt_moves: %d\n", game->player.cnt_moves);
		if (exit_check(game, pos->x, pos->y))
			exit_success_game(game);
	}
}

void	press_ESC(t_game *game)
{
	printf("Exit game\n");
	exit_game(game);
	exit(0);
}

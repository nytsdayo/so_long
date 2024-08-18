/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:15:42 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/19 06:09:15 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/games.h"

int		key_press(int keycode, t_game *game);
void	move_player(t_game *game, int keycode, t_position *pos);
void	press_esc(t_game *game);

void	set_hooks(t_game *game)
{
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0, exit_failure_game, game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		press_esc(game);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		move_player(game, keycode, &game->player.point);
	return (0);
}

void	move_player(t_game *game, int keycode, t_position *pos)
{
	t_position	move;

	move = (t_position){0, 0};
	what_is_press_key(keycode, &move);
	if (move_check(game, pos->x + move.x, pos->y + move.y))
	{
		if (game->map.body[pos->y][pos->x] != 'E')
			draw_image(game, *pos, game->map.assets.floor);
		else
			draw_image(game, *pos, game->map.assets.goal);
		*pos = (t_position){pos->x + move.x, pos->y + move.y};
		game->player.cnt_collectibles -= collectible_check(game, pos->x,
				pos->y);
		draw_image(game, *pos, game->map.assets.player);
		game->player.cnt_moves++;
		ft_printf("cnt_moves: %d\n", game->player.cnt_moves);
		if (goal_check(game, pos->x, pos->y))
			exit_success_game(game);
	}
}

void	press_esc(t_game *game)
{
	printf("Exit game\n");
	exit_game(game);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 22:21:54 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/19 06:08:05 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/games.h"

void	what_is_press_key(int keycode, t_position *move)
{
	if (keycode == KEY_W)
		move->y = -1;
	else if (keycode == KEY_S)
		move->y = 1;
	else if (keycode == KEY_A)
		move->x = -1;
	else if (keycode == KEY_D)
		move->x = 1;
}

int	collectible_check(t_game *game, int x, int y)
{
	if (game->map.body[y][x] == COLLECTIBLE)
	{
		game->map.body[y][x] = FLOOR;
		return (1);
	}
	return (0);
}

int	move_check(t_game *game, int x, int y)
{
	if (game->map.body[y][x] != WALL)
	{
		return (1);
	}
	return (0);
}

int	goal_check(t_game *game, int x, int y)
{
	if (game->map.body[y][x] == GOAL)
	{
		if (game->player.cnt_collectibles == 0)
			return (1);
	}
	return (0);
}

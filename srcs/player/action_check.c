/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 22:21:54 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/13 14:04:29 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

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

int	exit_check(t_game *game, int x, int y)
{
	if (game->map.body[y][x] == GOAL)
	{
		if (game->player.cnt_collectibles == 0)
			return (1);
	}
	return (0);
}
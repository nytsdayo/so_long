/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:24:29 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/19 06:26:27 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/games.h"

void	set_player(t_game *game)
{
	t_position	map_pos;

	map_pos = (t_position){0, 0};
	game->player.point = (t_position){0, 0};
	while (game->map.body[map_pos.y])
	{
		map_pos.x = 0;
		while (game->map.body[map_pos.y][map_pos.x])
		{
			if (game->map.body[map_pos.y][map_pos.x] == PLAYER)
			{
				if (game->player.point.x != 0 || game->player.point.y != 0)
					exit_error_game(game, "Multiple players");
				game->player.point = (t_position){map_pos.x, map_pos.y};
				game->player.asset = game->map.assets.player;
				game->player.cnt_collectibles = 0;
				game->player.cnt_moves = 0;
			}
			map_pos.x++;
		}
		map_pos.y++;
	}
	if (game->player.point.x == 0 && game->player.point.y == 0)
		exit_error_game(game, "Error\nPlayer not found\n");
}

void	set_goal(t_game *game)
{
	t_position	map_pos;
	int			flag;

	flag = 0;
	map_pos = (t_position){0, 0};
	game->goal.point = (t_position){0, 0};
	while (game->map.body[map_pos.y])
	{
		map_pos.x = 0;
		while (game->map.body[map_pos.y][map_pos.x])
		{
			if (game->map.body[map_pos.y][map_pos.x] == GOAL)
			{
				if (flag)
					exit_error_game(game, "Multiple goals");
				game->goal.point = (t_position){map_pos.x, map_pos.y};
				game->goal.asset = game->map.assets.goal;
				flag = 1;
			}
			map_pos.x++;
		}
		map_pos.y++;
	}
	if (!flag)
		exit_error_game(game, "Error\nGoal not found\n");
}

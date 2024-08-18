/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:59:00 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/19 06:18:49 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/games.h"

t_assets	set_images(t_game *game);
void		draw_map(t_game *game, t_assets assets);

void	create_map(t_game *game)
{
	int	i;

	game->map.width = ft_cnt_col(game->map.body);
	game->map.height = ft_cnt_row(game->map.body);
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	if (!game->win)
		exit_error_game(game, "Error\nFailed to create window\n");
	game->map.assets = set_images(game);
	draw_map(game, game->map.assets);
	i = 0;
	while (i < game->map.height)
	{
		game->player.cnt_collectibles += ft_count_char(game->map.body[i],
				COLLECTIBLE);
		i++;
	}
}

t_assets	set_images(t_game *game)
{
	t_position	ptrs;
	t_assets	assets;

	assets.wall = set_image(game, WALL_PATH, &ptrs);
	if (!assets.wall)
		exit_error_game(game, "Error\nFailed to set wall image\n");
	assets.floor = set_image(game, FLOOR_PATH, &ptrs);
	if (!assets.floor)
		exit_error_game(game, "Error\nFailed to set floor image\n");
	assets.player = set_image(game, PLAYER_PATH, &ptrs);
	if (!assets.player)
		exit_error_game(game, "Error\nFailed to set player image\n");
	assets.goal = set_image(game, GOAL_PATH, &ptrs);
	if (!assets.goal)
		exit_error_game(game, "Error\nFailed to set goal image\n");
	assets.collectible = set_image(game, COLLECTIBLE_PATH, &ptrs);
	if (!assets.collectible)
		exit_error_game(game, "Error\nFailed to set collectible image\n");
	return (assets);
}

void	draw_map(t_game *game, t_assets assets)
{
	t_position	pos;
	char		c;

	pos.y = 0;
	while (pos.y < game->map.height)
	{
		pos.x = 0;
		while (pos.x < game->map.width)
		{
			c = game->map.body[pos.y][pos.x];
			if (c == '1')
				draw_image(game, pos, assets.wall);
			else if (c == '0')
				draw_image(game, pos, assets.floor);
			else if (c == 'P')
				draw_image(game, pos, assets.player);
			else if (c == 'E')
				draw_image(game, pos, assets.goal);
			else if (c == 'C')
				draw_image(game, pos, assets.collectible);
			pos.x++;
		}
		pos.y++;
	}
}

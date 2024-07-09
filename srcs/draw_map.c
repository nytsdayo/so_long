/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:31:56 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/09 10:18:25 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"
#include "../includes/so_long.h"

void	set_images(t_game *game)
{
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &x, &y);
	if (!game->wall)
	{
		perror("mlx_xpm_file_to_image");
		// エラー処理
	}
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR_PATH, &x, &y);
	if (!game->floor)
	{
		perror("mlx_xpm_file_to_image");
		// エラー処理
	}
	game->player = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH, &x, &y);
	if (!game->player)
	{
		perror("mlx_xpm_file_to_image");
		// エラー処理
	}
	game->goal = mlx_xpm_file_to_image(game->mlx, GOAL_PATH, &x, &y);
	if (!game->goal)
	{
		perror("mlx_xpm_file_to_image");
		// エラー処理
	}
	game->collectible = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE_PATH, &x,
			&y);
	if (!game->collectible)
	{
		perror("mlx_xpm_file_to_image");
		// エラー処理
	}
}

void	check_map(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x * TILE_SIZE,
			y * TILE_SIZE);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->goal, x * TILE_SIZE,
			y * TILE_SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible, x
			* TILE_SIZE, y * TILE_SIZE);
}
void	draw_map(t_game *game)
{
	int	x;
	int	y;

	set_images(game);
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			printf("x: %d, y: %d\n", x, y);
			printf("map: %c\n", game->map->map[y][x]);
			check_map(game, game->map->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

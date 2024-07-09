/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:31:56 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/10 00:13:15 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/draw.h"
#include "../../includes/games.h"

void	set_images(t_game *game, t_assets *assets);
void	check_map(t_game *game, t_assets *assets);

void	draw_map(t_game *game)
{
	t_assets	*assets;

	assets = (t_assets *)malloc(sizeof(t_assets));
	set_images(game, assets);
	check_map(game, assets);
}

void	set_images(t_game *game, t_assets *assets)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	assets->wall = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &point.x,
			&point.y);
	if (!assets->wall)
		perror("mlx_xpm_file_to_image");
	assets->floor = mlx_xpm_file_to_image(game->mlx, FLOOR_PATH, &point.x,
			&point.y);
	if (!assets->floor)
		perror("mlx_xpm_file_to_image");
	assets->player = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH, &point.x,
			&point.y);
	if (!assets->player)
		perror("mlx_xpm_file_to_image");
	assets->goal = mlx_xpm_file_to_image(game->mlx, GOAL_PATH, &point.x,
			&point.y);
	if (!assets->goal)
		perror("mlx_xpm_file_to_image");
	assets->collectible = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE_PATH,
			&point.x, &point.y);
	if (!assets->collectible)
		perror("mlx_xpm_file_to_image");
}

void	check_map(t_game *game, t_assets *assets)
{
	t_point	point;
	char	c;
	int		i;
	int		j;

	point.y = 0;
	while (point.y < game->map->height)
	{
		point.x = 0;
		while (point.x < game->map->width)
		{
			c = game->map->body[point.y][point.x];
			i = point.x * TILE_SIZE;
			j = point.y * TILE_SIZE;
			if (c == '1')
				mlx_put_image_to_window(game->mlx, game->win, assets->wall, i,
					j);
			else if (c == '0')
				mlx_put_image_to_window(game->mlx, game->win, assets->floor, i,
					j);
			else if (c == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, assets->player, i,
					j);
				set_player(game, &point, assets->player);
			}
			else if (c == 'E')
				mlx_put_image_to_window(game->mlx, game->win, assets->goal, i,
					j);
			else if (c == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					assets->collectible, i, j);
			point.x++;
		}
		point.y++;
	}
}

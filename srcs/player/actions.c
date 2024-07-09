/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:a+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:25:30 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/08 23:09:11 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

void	press_ESC(t_game *game)
{
	printf("Exit game\n");
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	move_forward(t_game *game)
{
	game->player->point->y -= 1;
	if (game->player->point->y < 1)
		game->player->point->y = 1;
	mlx_put_image_to_window(game->mlx, game->win, game->player->asset,
		game->player->point->x * TILE_SIZE, game->player->point->y * TILE_SIZE);
	ft_printf("%d, %d\n", game->player->point->x, game->player->point->y);
	printf("Move forward\n");
}

void	move_backward(t_game *game)
{
	game->player->point->y += 1;
	if (game->player->point->y > game->map->height - 2)
		game->player->point->y = game->map->height - 2;
	mlx_put_image_to_window(game->mlx, game->win, game->player->asset,
		game->player->point->x * TILE_SIZE, game->player->point->y * TILE_SIZE);
	ft_printf("%d, %d\n", game->player->point->x, game->player->point->y);
	printf("Move backward\n");
}

void	move_left(t_game *game)
{
	game->player->point->x -= 1;
	if (game->player->point->x < 1)
		game->player->point->x = 1;
	mlx_put_image_to_window(game->mlx, game->win, game->player->asset,
		game->player->point->x * TILE_SIZE, game->player->point->y * TILE_SIZE);
	ft_printf("%d, %d\n", game->player->point->x, game->player->point->y);
	printf("Move left\n");
}

void	move_right(t_game *game)
{
	game->player->point->x += 1;
	if (game->player->point->x > game->map->width - 2)
		game->player->point->x = game->map->width - 2;
	mlx_put_image_to_window(game->mlx, game->win, game->player->asset,
		game->player->point->x * TILE_SIZE, game->player->point->y * TILE_SIZE);
	ft_printf("%d, %d\n", game->player->point->x, game->player->point->y);
	printf("Move right\n");
}

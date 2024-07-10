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

void	move_forward(t_game *game, int *p_x, int *p_y)
{
	int	x;
	int	y;

	x = *p_x;
	y = *p_y - 1;
	ft_printf("x: %d, y: %d\n", x, y);
	if (game->map.body[y][x] != WALL)
	{
		*p_y -= 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player.asset, x
			* TILE_SIZE, y * TILE_SIZE);
	}
	ft_printf("%d, %d\n", game->player.point.x, game->player.point.y);
}

void	move_backward(t_game *game, int *p_x, int *p_y)
{
	int	x;
	int	y;

	x = *p_x;
	y = *p_y + 1;
	if (game->map.body[y][x] != WALL)
	{
		*p_y += 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player.asset, x
			* TILE_SIZE, y * TILE_SIZE);
	}
	ft_printf("%d, %d\n", game->player.point.x, game->player.point.y);
}

void	move_left(t_game *game, int *p_x, int *p_y)
{
	int	x;
	int	y;

	x = *p_x - 1;
	y = *p_y;
	if (game->map.body[y][x] != WALL)
	{
		*p_x -= 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player.asset, x
			* TILE_SIZE, y * TILE_SIZE);
	}
	ft_printf("%d, %d\n", game->player.point.x, game->player.point.y);
}

void	move_right(t_game *game, int *p_x, int *p_y)
{
	int x;
	int y;

	x = *p_x + 1;
	y = *p_y;
	if (game->map.body[y][x] != WALL)
	{
		*p_x += 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player.asset, x
			* TILE_SIZE, y * TILE_SIZE);
	}
	ft_printf("%d, %d\n", game->player.point.x, game->player.point.y);
}
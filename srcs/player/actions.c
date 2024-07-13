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

void	draw_big_string(void *mlx, void *win, int x, int y, int color,
			char *string);
void	press_ESC(t_game *game)
{
	printf("Exit game\n");
	exit_game(game);
	exit(0);
}

void	move_forward(t_game *game, int *p_x, int *p_y)
{
	int	x;
	int	y;

	x = *p_x;
	y = *p_y - 1;
	if (move_check(game, x, y))
	{
		*p_y -= 1;
		game->player.cnt_collectibles -= collectible_check(game, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->player.asset, x
			* TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->map.assets.floor, x
			* TILE_SIZE, (y + 1) * TILE_SIZE);
		if (exit_check(game, x, y))
			exit_success_game(game);
		game->player.cnt_moves++;
	}
}

void	move_backward(t_game *game, int *p_x, int *p_y)
{
	int	x;
	int	y;

	x = *p_x;
	y = *p_y + 1;
	if (move_check(game, x, y))
	{
		*p_y += 1;
		game->player.cnt_collectibles -= collectible_check(game, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->player.asset, x
			* TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->map.assets.floor, x
			* TILE_SIZE, (y - 1) * TILE_SIZE);
		if (exit_check(game, x, y))
			exit_success_game(game);
		game->player.cnt_moves++;
	}
}

void	move_left(t_game *game, int *p_x, int *p_y)
{
	int	x;
	int	y;

	x = *p_x - 1;
	y = *p_y;
	if (move_check(game, x, y))
	{
		*p_x -= 1;
		game->player.cnt_collectibles -= collectible_check(game, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->player.asset, x
			* TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->map.assets.floor, (x
				+ 1) * TILE_SIZE, y * TILE_SIZE);
		game->player.cnt_moves++;
		mlx_string_put(game->mlx, game->win, TILE_SIZE / 2, TILE_SIZE / 2,
			0xFF22FF, ft_itoa(game->player.cnt_moves));
		if (exit_check(game, x, y))
			exit_success_game(game);
	}
}

void	move_right(t_game *game, int *p_x, int *p_y)
{
	int	x;
	int	y;

	x = *p_x + 1;
	y = *p_y;
	if (move_check(game, x, y))
	{
		*p_x += 1;
		game->player.cnt_collectibles -= collectible_check(game, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->player.asset, x
			* TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->map.assets.floor, (x
				- 1) * TILE_SIZE, y * TILE_SIZE);
		game->player.cnt_moves++;
		mlx_string_put(game->mlx, game->win, TILE_SIZE, TILE_SIZE, 0xFF22FF,
			ft_itoa(game->player.cnt_moves));
		if (exit_check(game, x, y))
			exit_success_game(game);
	}
}

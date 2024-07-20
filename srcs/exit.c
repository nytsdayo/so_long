/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:15:09 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/21 07:24:57 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/games.h"

void	free_map(char **map);

void	exit_game(t_game *game)
{
	if (game->map.body)
		free_map(game->map.body);
	if (game->mlx)
	{
		if (game->map.assets.wall)
		{
			if (game->map.assets.wall)
				mlx_destroy_image(game->mlx, game->map.assets.wall);
			if (game->map.assets.floor)
				mlx_destroy_image(game->mlx, game->map.assets.floor);
			if (game->map.assets.player)
				mlx_destroy_image(game->mlx, game->map.assets.player);
			if (game->map.assets.goal)
				mlx_destroy_image(game->mlx, game->map.assets.goal);
			if (game->map.assets.collectible)
				mlx_destroy_image(game->mlx, game->map.assets.collectible);
		}
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	exit_success_game(t_game *game)
{
	ft_printf("CLEAR!!!\n");
	exit_game(game);
	exit(EXIT_SUCCESS);
}

int	exit_failure_game(t_game *game)
{
	perror("Exit_game");
	exit_game(game);
	exit(EXIT_SUCCESS);
}

int	exit_error_game(t_game *game)
{
	perror("Error!");
	exit_game(game);
	exit(EXIT_FAILURE);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

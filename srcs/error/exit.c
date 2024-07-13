/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:15:09 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/13 13:36:08 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/games.h"

void	free_map(char **map);

int	exit_game(t_game *game)
{
	if (game->map.body)
		free_map(game->map.body);
	if (game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	exit_success_game(t_game *game)
{
	ft_printf("CLEAR!!! Long-tailed Ti\n");
	exit_game(game);
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

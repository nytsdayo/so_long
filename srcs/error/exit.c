/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:15:09 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/10 09:28:58 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/games.h"

void	free_map(char **map);

void	exit_game(t_game *game, char *message)
{
	if (game->map.body)
		free_map(game->map.body);
	if (game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	ft_printf("exit game\n");
	exit(0);
}
void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_printf("free map[%d]\n", i);
		free(map[i]);
		i++;
	}
	ft_printf("free map[%d]\n", i);
	free(map);
	ft_printf("free map\n");
}
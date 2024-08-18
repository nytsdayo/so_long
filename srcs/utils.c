/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:47:07 by rnakatan          #+#    #+#             */
/*   Updated: 2024/08/19 06:27:12 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/games.h"

void	*set_image(t_game *game, char *path, t_position *ptrs)
{
	void	*asset;

	asset = mlx_xpm_file_to_image(game->mlx, path, &ptrs->x, &ptrs->y);
	if (!asset)
		exit_error_game(game, "Error\nFailed to set image\n");
	return (asset);
}

void	draw_image(t_game *game, t_position index, void *asset)
{
	mlx_put_image_to_window(game->mlx, game->win, asset, index.x * TILE_SIZE,
		index.y * TILE_SIZE);
}

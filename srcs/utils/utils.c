/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:47:07 by rnakatan          #+#    #+#             */
/*   Updated: 2024/07/20 00:48:41 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/games.h"
#include "../../includes/struct.h"
#include "../../minilibx/mlx.h"

void	*set_image(t_game *game, char *path, t_point *ptrs)
{
	void	*asset;

	asset = mlx_xpm_file_to_image(game->mlx, path, &ptrs->x, &ptrs->y);
	if (!asset)
		perror("mlx_xpm_file_to_image");
	return (asset);
}

void	draw_image(t_game *game, t_point index, void *asset)
{
	mlx_put_image_to_window(game->mlx, game->win, asset, index.x * TILE_SIZE,
		index.y * TILE_SIZE);
}
